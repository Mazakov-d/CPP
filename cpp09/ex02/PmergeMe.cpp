#include "PmergeMe.hpp"

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
			jS[i] = 0;
		else if (i == 1)
			jS[i] = 1;
		else {
			jS[i] = jS[i - 1] + (2 * jS[i - 2]);
		}
	}
	return jS;
}

void	sort