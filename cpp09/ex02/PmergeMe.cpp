#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <time.h>

/*
 * Exception classes
 */

const char *PmergeMe::Duplicate::what() const throw() {
	return "The duplicate numbers are not authorized";
}

const char *PmergeMe::NegativeValue::what() const throw() {
	return "Expected positives values";
}

PmergeMe::BadToken::BadToken() {
	_message = "The token received was not expected";
}

PmergeMe::BadToken::BadToken(const std::string &tokenReceived,
							const std::string &tokenExpected) {
	_message = "The token expected was " + tokenExpected + " and received '" +
			tokenReceived + "'";
}

const char *PmergeMe::BadToken::what() const throw() {
	return _message.c_str();
}

PmergeMe::BadToken::~BadToken() throw() {}

/*
 * utils functions
 */

int *copyIntArray(int *original, size_t size) {
	int *copy;

	copy = new int[size];
	for (size_t i = 0; i <= size; ++i) {
		copy[i] = original[i];
	}
	return copy;
}

void safeDelete(int **array) {
	if (array && *array) {
		delete[] *array;
		*array = NULL;
	}
}

int countInput(char **args) {
	int count = 0;

	for (size_t i = 0; args && args[i]; ++i) {
		for (size_t j = 0; args[i][j]; ++j) {
			if (isspace(args[i][j]))
				continue;
			while (args[i][j] && !isspace(args[i][j]))
				j++;
			count++;
			if (!args[i][j])
				break;
		}
	}
	return count;
}

/*
 * class constructor/destructor
 */

PmergeMe::PmergeMe()
	: _input(NULL), _inputSize(0), _jacobsthalSequence(NULL),
	_jacobsthalSequenceSize(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	_input = copyIntArray(copy._input, copy._inputSize);
	_inputSize = copy._inputSize;
	_jacobsthalSequence =
		copyIntArray(copy._jacobsthalSequence, copy._jacobsthalSequenceSize);
	_jacobsthalSequenceSize = copy._jacobsthalSequenceSize;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		safeDelete(&this->_input);
		safeDelete(&this->_jacobsthalSequence);
		this->_input = copyIntArray(other._input, other._inputSize);
		this->_inputSize = other._inputSize;
		this->_jacobsthalSequence = copyIntArray(other._jacobsthalSequence,
												other._jacobsthalSequenceSize);
		this->_jacobsthalSequenceSize = other._jacobsthalSequenceSize;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
	safeDelete(&_input);
	safeDelete(&_jacobsthalSequence);
}

/*
 * algorithm implementation
 */

void PmergeMe::parseInput(char **args) {
	_inputSize = countInput(args);
	_input = new int[_inputSize];

	int iArrayInput = 0;
	int value;

	for (size_t i = 0; args && args[i]; ++i) {
		std::string token = args[i];
		for (size_t j = 0; j < token.size(); ++j) {
			if (isspace(token[j]))
				continue;
			std::istringstream iss(token.substr(j));
			iss >> value;
			if (iss.fail())
				throw(BadToken(token.substr(j), "an int"));
			if (value < 0)
				throw(NegativeValue());
			_input[iArrayInput] = value;
			iArrayInput++;
			while (isdigit(token[j]))
				j++;
			--j;
		}
	}
	for (size_t i = 0; i < _inputSize; ++i) {
		for (size_t j = i + 1; j < _inputSize; ++j) {
			if (_input[j] == _input[i])
				throw(Duplicate());
		}
	}
}

void PmergeMe::jacobsthalSequence(size_t size) {
	if (_jacobsthalSequence) {
		delete[] _jacobsthalSequence;
		_jacobsthalSequenceSize = 0;
	}
	_jacobsthalSequence = new int[size + 2];

	size_t value;
	size_t i = 0;
	while (1) {
		if (i == 0)
			value = 1;
		else if (i == 1)
			value = 3;
		else {
			value =
				_jacobsthalSequence[i - 1] + (2 * _jacobsthalSequence[i - 2]);
		}
		if (value > size) {
			_jacobsthalSequence[i] = value;
			_jacobsthalSequenceSize = i + 1;
			return;
		} else {
			_jacobsthalSequence[i] = value;
		}
		++i;
	}
	return;
}

template <typename T> void swapIndex(T &t, size_t i, size_t j) {
	if (i >= t.size() || j >= t.size())
		return;
	std::swap(t[i], t[j]);
}

template <typename T> void fillContainer(T &t, int *input, size_t inputSize) {
	for (size_t i = 0; i < inputSize; ++i) {
		t.push_back(input[i]);
	}
}

template <typename T>
void splitingWinnersAndLosers(const T &t, T &winners, T &losers, int &pending) {
	typename T::const_iterator iter = t.begin();

	while (iter != t.end()) {
		int save = *iter;
		++iter;
		if (iter == t.end()) {
			pending = save;
			break;
		}
		if (save > *iter) {
			winners.push_back(save);
			losers.push_back(*iter);
		} else {
			winners.push_back(*iter);
			losers.push_back(save);
		}
		++iter;
	}
}

void binaryInsertionDeq(int n, std::deque<int> &deq, size_t startPosition) {
	if (startPosition == 0) {
		deq.insert(deq.begin(), n);
		return;
	}
	if (startPosition > deq.size())
		startPosition = deq.size();

	size_t left = 0;
	size_t right = startPosition;
	while (left < right) {
		size_t mid = left + (right - left) / 2;

		if (deq[mid] < n)
			left = mid + 1;
		else
			right = mid;
	}
	deq.insert(deq.begin() + left, n);
}

void binaryInsertionVec(int n, std::vector<int> &vec, size_t startPosition) {
	if (startPosition == 0) {
		vec.insert(vec.begin(), n);
		return;
	}
	if (startPosition > vec.size())
		startPosition = vec.size();

	size_t left = 0;
	size_t right = startPosition;
	while (left < right) {
		size_t mid = left + (right - left) / 2;

		if (vec[mid] < n)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, n);
}

std::vector<int> PmergeMe::algorithmImplementationVec(std::vector<int> &vec) {
	if (vec.size() == 1)
		return vec;
	if (vec.size() == 2) {
		if (vec[0] > vec[1])
			swapIndex(vec, 0, 1);
		return vec;
	}

	std::vector<int> winners;
	std::vector<int> losers;
	int pending = -1;
	std::vector<std::pair<int, int> > pairs;

	splitingWinnersAndLosers(vec, winners, losers, pending);

	if (PRINT) {
		std::cout << "*DIVIDING THE CONTAINER <STD::VECTOR>*" << std::endl;
		std::cout << "Winners: ";
		for (size_t i = 0; i < winners.size() && i < 30; i++) {
			std::cout << winners[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Losers: ";
		for (size_t i = 0; i < losers.size() && i < 30; ++i) {
			std::cout << losers[i] << " ";
		}
		std::cout << "\nPending: " << pending;
		std::cout << std::endl << std::endl;
		std::cout << "*MAKING PAIRS*" << std::endl;
	}

	for (size_t i = 0; i < winners.size(); ++i) {
		if (PRINT && i < 10) {
			std::cout << "[" << winners[i] << "," << losers[i] << "]"
					  << std::endl;
		}
		pairs.push_back(std::make_pair(winners[i], losers[i]));
	}

	if (PRINT)
		std::cout << "\n";

	winners = algorithmImplementationVec(winners);

	std::vector<int> reorderedLosers;

	for (size_t i = 0; i < winners.size(); ++i) {
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin();
			 it < pairs.end(); ++it) {
			if (it->first == winners[i])
				reorderedLosers.push_back(it->second);
		}
		if (i == (winners.size() - 1) && losers.size() > winners.size()) {
			++i;
			while (i < losers.size()) {
				reorderedLosers.push_back(losers[i]);
				++i;
			}
		}
	}

	if (PRINT) {
		std::cout << "*REORDERING THE PAIRS*" << std::endl;
		std::cout << "Winners: ";
		for (size_t i = 0; i < winners.size() && i < 30; ++i) {
			std::cout << winners[i] << " ";
		}
		std::cout << "\nUnordered losers: ";
		for (size_t i = 0; i < losers.size() && i < 30; ++i) {
			std::cout << losers[i] << " ";
		}
		std::cout << "\nOrdered losers: ";
		for (size_t i = 0; i < reorderedLosers.size() && i < 30; ++i) {
			std::cout << reorderedLosers[i] << " ";
		}
		std::cout << "\n\n";
	}

	jacobsthalSequence(winners.size());
	if (PRINT) {
		for (int i = 0; i < _jacobsthalSequenceSize; ++i)
			std::cout << _jacobsthalSequence[i] << " ";
		std::cout << std::endl;
	}

	std::vector<int> originalWinners = winners;
	int prev = -1;

	for (int k = 0; k < _jacobsthalSequenceSize; ++k) {
		int j = _jacobsthalSequence[k] - 1;

		if ((size_t)j >= reorderedLosers.size())
			j = reorderedLosers.size() - 1;
		if (PRINT) {
			std::cout << "The jacobshtal order want to insert: " << j
					  << " and prev is " << prev << std::endl;
		}
		for (int x = j; x > prev; --x) {
			int rightBound = std::distance(
				winners.begin(),
				std::find(winners.begin(), winners.end(), originalWinners[x]));
			if (PRINT) {
				std::cout << "Going to insert the numbers: "
						  << reorderedLosers[x] << " at the index " << x
						  << " previously paired with " << originalWinners[x]
						  << std::endl;
				std::cout << "The right bound is " << rightBound
						  << " corresponding to " << winners[rightBound]
						  << std::endl;
			}
			binaryInsertionVec(reorderedLosers[x], winners, rightBound);
			if (PRINT) {
				std::cout << "winners: ";
				for (std::vector<int>::iterator it = winners.begin();
					 it != winners.end(); ++it) {
					std::cout << *it << " ";
				}
				std::cout << std::endl;
				std::cout << "losers: ";
				for (std::vector<int>::iterator it = reorderedLosers.begin();
					 it != reorderedLosers.end(); ++it) {
					std::cout << *it << " ";
				}
				std::cout << std::endl;
			}
		}
		prev = j;
	}
	if (pending != -1) {
		binaryInsertionVec(pending, winners, winners.size());
	}

	if (PRINT) {
		std::cout << "*WINNERS RETURNED*" << std::endl;
		std::cout << "Winners: ";
		for (int i = 0; (size_t)i < winners.size() && i < 30; ++i) {
			std::cout << winners[i] << " ";
		}
		std::cout << "\n\n";
	}

	return (winners);
}

std::deque<int> PmergeMe::algorithmImplementationDeq(std::deque<int> &deq) {
	if (deq.size() == 1)
		return deq;
	if (deq.size() == 2) {
		if (deq[0] > deq[1])
			swapIndex(deq, 0, 1);
		return deq;
	}

	std::deque<int> winners;
	std::deque<int> losers;
	int pending = -1;
	std::vector<std::pair<int, int> > pairs;

	splitingWinnersAndLosers(deq, winners, losers, pending);

	if (PRINT) {
		std::cout << "*DIVIDING THE CONTAINER <STD::deque>*" << std::endl;
		std::cout << "Winners: ";
		for (size_t i = 0; i < winners.size() && i < 30; i++) {
			std::cout << winners[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Losers: ";
		for (size_t i = 0; i < losers.size() && i < 30; ++i) {
			std::cout << losers[i] << " ";
		}
		std::cout << "\nPending: " << pending;
		std::cout << std::endl << std::endl;
		std::cout << "*MAKING PAIRS*" << std::endl;
	}

	for (size_t i = 0; i < winners.size(); ++i) {
		if (PRINT && i < 10) {
			std::cout << "[" << winners[i] << "," << losers[i] << "]"
					  << std::endl;
		}
		pairs.push_back(std::make_pair(winners[i], losers[i]));
	}

	if (PRINT)
		std::cout << "\n";

	winners = algorithmImplementationDeq(winners);

	std::deque<int> reorderedLosers;

	for (size_t i = 0; i < winners.size(); ++i) {
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin();
			it < pairs.end(); ++it) {
			if (it->first == winners[i])
				reorderedLosers.push_back(it->second);
		}
		if (i == (winners.size() - 1) && losers.size() > winners.size()) {
			++i;
			while (i < losers.size()) {
				reorderedLosers.push_back(losers[i]);
				++i;
			}
		}
	}

	if (PRINT) {
		std::cout << "*REORDERING THE PAIRS*" << std::endl;
		std::cout << "Winners: ";
		for (size_t i = 0; i < winners.size() && i < 30; ++i) {
			std::cout << winners[i] << " ";
		}
		std::cout << "\nUnordered losers: ";
		for (size_t i = 0; i < losers.size() && i < 30; ++i) {
			std::cout << losers[i] << " ";
		}
		std::cout << "\nOrdered losers: ";
		for (size_t i = 0; i < reorderedLosers.size() && i < 30; ++i) {
			std::cout << reorderedLosers[i] << " ";
		}
		std::cout << "\n\n";
	}

	jacobsthalSequence(winners.size());
	if (PRINT) {
		for (int i = 0; i < _jacobsthalSequenceSize; ++i)
			std::cout << _jacobsthalSequence[i] << " ";
		std::cout << std::endl;
	}

	std::deque<int> originalWinners = winners;
	int prev = -1;

	for (int k = 0; k < _jacobsthalSequenceSize; ++k) {
		int j = _jacobsthalSequence[k] - 1;

		if ((size_t)j >= reorderedLosers.size())
			j = reorderedLosers.size() - 1;
		if (PRINT) {
			std::cout << "The jacobshtal order want to insert: " << j
					  << " and prev is " << prev << std::endl;
		}
		for (int x = j; x > prev; --x) {
			int rightBound = std::distance(
				winners.begin(),
				std::find(winners.begin(), winners.end(), originalWinners[x]));
			if (PRINT) {
				std::cout << "Going to insert the numbers: "
						  << reorderedLosers[x] << " at the index " << x
						  << " previously paired with " << originalWinners[x]
						  << std::endl;
				std::cout << "The right bound is " << rightBound
						  << " corresponding to " << winners[rightBound]
						  << std::endl;
			}
			binaryInsertionDeq(reorderedLosers[x], winners, rightBound);
			if (PRINT) {
				std::cout << "winners: ";
				for (std::deque<int>::iterator it = winners.begin();
					 it != winners.end(); ++it) {
					std::cout << *it << " ";
				}
				std::cout << std::endl;
				std::cout << "losers: ";
				for (std::deque<int>::iterator it = reorderedLosers.begin();
					 it != reorderedLosers.end(); ++it) {
					std::cout << *it << " ";
				}
				std::cout << std::endl;
			}
		}
		prev = j;
	}
	if (pending != -1) {
		binaryInsertionDeq(pending, winners, winners.size());
	}

	if (PRINT) {
		std::cout << "*WINNERS RETURNED*" << std::endl;
		std::cout << "Winners: ";
		for (int i = 0; (size_t)i < winners.size() && i < 30; ++i) {
			std::cout << winners[i] << " ";
		}
		std::cout << "\n\n";
	}

	return (winners);
}

clock_t PmergeMe::FordJohnsonVector() {
	std::vector<int> vec;

	fillContainer(vec, _input, _inputSize);

	if (PRINT_VEC) {
		std::cout << "Before (std::vector): ";
		for (size_t i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " ";
		}
		std::cout << "\n";
	}

	clock_t startTime = clock();
	vec = algorithmImplementationVec(vec);
	clock_t endTime = clock() - startTime;

	if (PRINT_VEC) {
		std::cout << "After (std::vector): ";
		for (size_t i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " ";
		}
		std::cout << "\n";
	}

	return endTime;
}

clock_t PmergeMe::FordJohnsonDeque() {
	std::deque<int> deq;

	fillContainer(deq, _input, _inputSize);

	if (PRINT_DEQ) {
		std::cout << "Before (std::deque): ";
		for (size_t i = 0; i < deq.size(); ++i) {
			std::cout << deq[i] << " ";
		}
		std::cout << "\n";
	}
	clock_t startTime = clock();
	deq = algorithmImplementationDeq(deq);
	clock_t endTime = clock() - startTime;

	if (PRINT_DEQ) {
		std::cout << "After (std::deque): ";
		for (size_t i = 0; i < deq.size(); ++i) {
			std::cout << deq[i] << " ";
		}
		std::cout << "\n";
	}

	return endTime;
}