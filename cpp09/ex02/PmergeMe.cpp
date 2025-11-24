#include "PmergeMe.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <cstddef>
#include <time.h>
#include <algorithm>
#include <vector>
#include <deque>

/*
* Exception classes
*/

const char* PmergeMe::NegativeValue::what() const throw() {
	return "Expected positives values";
}

PmergeMe::BadToken::BadToken() {
	_message = "The token received was not expected";
}

PmergeMe::BadToken::BadToken(const std::string& tokenReceived, const std::string& tokenExpected) {
	_message = "The token expected was " + tokenExpected + " and received '" + tokenReceived + "'";
}

const char* PmergeMe::BadToken::what() const throw() {
	return _message.c_str();
}

PmergeMe::BadToken::~BadToken() throw() {}

/*
* utils functions
*/

int*	copyIntArray(int* original, size_t size) {
	int* copy;

	copy = new int[size];
	for (size_t i = 0; i <= size; ++i) {
		copy[i] = original[i];
	}
	return copy;
}

void	safeDelete(int** array) {
	if (array && *array)
	{
		delete[] *array;
		*array = NULL;
	}
}

int	countInput(char **args) {
	int	count = 0;

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

PmergeMe::PmergeMe(): _input(NULL), _inputSize(0), _jacobsthalSequence(NULL), _jacobsthalSequenceSize(0) {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	_input = copyIntArray(copy._input, copy._inputSize);
	_inputSize = copy._inputSize;
	_jacobsthalSequence = copyIntArray(copy._jacobsthalSequence, copy._jacobsthalSequenceSize);
	_jacobsthalSequenceSize = copy._jacobsthalSequenceSize;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		safeDelete(&this->_input);
		safeDelete(&this->_jacobsthalSequence);
		this->_input = copyIntArray(other._input, other._inputSize);
		this->_inputSize = other._inputSize;
		this->_jacobsthalSequence = copyIntArray(other._jacobsthalSequence, other._jacobsthalSequenceSize);
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

void	PmergeMe::parseInput(char** args) {
	_inputSize = countInput(args);
	_input = new int[_inputSize];

	int	iArrayInput = 0;
	int	value;

	for (size_t i = 0; args && args[i]; ++i) {
		std::string	token = args[i];
		for (size_t j = 0; j < token.size(); ++j) {
			if (isspace(token[j]))
				continue;
			std::istringstream iss(token.substr(j));
			iss >> value;
			if (iss.fail())
				throw (BadToken(token.substr(j), "an int"));
			if (value < 0)
				throw (NegativeValue());
			_input[iArrayInput] = value;
			iArrayInput++;
			while (isdigit(token[j]))
				j++;
			--j;
		}
	}
}


int*	jacobsthalSequence(size_t size) {
	int*	jS = new int[size];

	for (size_t i = 0; i <= size; ++i) {
		if (i == 0)
			jS[i] = 1;
		else if (i == 1)
			jS[i] = 3;
		else {
			jS[i] = jS[i - 1] + (2 * jS[i - 2]);
		}
	}
	return jS;
}

/*
 * algorithm implentation
*/

template <typename T>
void	swapIndex(T& t, size_t i, size_t j) {
	if (i >= t.size() || j >= t.size())
		return;
	std::swap(t[i], t[j]);
}

template <typename T>
void	fillContainer(T& t, int* input, size_t inputSize) {
	for (size_t i = 0; i < inputSize; ++i) {
		t.push_back(input[i]);
	}
}

template <typename T>
void	splitingWinnersAndLoosers(const T& t, T& winners, T& loosers) {
	typename T::const_iterator iter = t.begin();

	while (iter != t.end()) {
		int	save = *iter;
		++iter;
		if (iter == t.end())
		{
			loosers.push_back(save);
			break;
		}
		if (save > *iter)
		{
			winners.push_back(save);
			loosers.push_back(*iter);
		}
		else
		{
			winners.push_back(*iter);
			loosers.push_back(save);
		}
		++iter;
	}
}

std::vector<int>	algorithmImplementationVec(std::vector<int> vec) {
	if (vec.size() == 1)
		return vec;
	if (vec.size() == 2)
	{
		if (vec[0] > vec[1])
			swapIndex(vec, 0, 1);
		return vec;
	}

	std::vector<int> 					winners;
	std::vector<int>					loosers;

	splitingWinnersAndLoosers(vec, winners, loosers);

	if (PRINT) {
		std::cout << "*DIVIDING THE CONTAINER*" << std::endl;
		std::cout << "Winners: ";
		for (std::vector<int>::iterator it = winners.begin(); it != winners.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Loosers: ";
		for (std::vector<int>::iterator it = loosers.begin(); it != loosers.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl << std::endl;
	}

	winners = algorithmImplementationVec(winners);



	return (winners);
}

std::deque<int>	algorithmImplementationDeq(std::deque<int>& deq) {
	if (deq.size() == 1)
		return deq;
	if (deq.size() == 2)
	{
		if (deq[0] > deq[1])
			swapIndex(deq, 0, 1);
		return deq;
	}

	std::deque<int> winners;
	std::deque<int> loosers;

	splitingWinnersAndLoosers(deq, winners, loosers);

	if (PRINT) {
		std::cout << "*DIVIDING THE CONTAINER*" << std::endl;
		std::cout << "Winners: ";
		for (std::deque<int>::iterator it = winners.begin(); it != winners.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Loosers: ";
		for (std::deque<int>::iterator it = loosers.begin(); it != loosers.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl << std::endl;
	}

	winners = algorithmImplementationDeq(winners);



	return winners;
}

clock_t	PmergeMe::FordJohnsonVector() {
	clock_t	startTime = clock();
	std::vector<int> vec;

	fillContainer(vec, _input, _inputSize);
	algorithmImplementationVec(vec);
	return clock() - startTime;
}

clock_t	PmergeMe::FordJohnsonDeque() {
	clock_t	startTime = clock();
	std::deque<int>	deq;

	fillContainer(deq, _input, _inputSize);
	algorithmImplementationDeq(deq);
	return clock() -startTime;
}