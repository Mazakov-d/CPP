#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define PRINT 0
#define PRINT_VEC 1
#define PRINT_DEQ 1

#include <deque>
#include <exception>
#include <iostream>
#include <vector>

class PmergeMe {
private:
	int *_input;
	size_t _inputSize;
	int *_jacobsthalSequence;
	int _jacobsthalSequenceSize;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void jacobsthalSequence(size_t size);
	clock_t FordJohnsonVector();
	clock_t FordJohnsonDeque();
	void parseInput(char **args);
	std::vector<int> algorithmImplementationVec(std::vector<int> &vec);
	std::deque<int> algorithmImplementationDeq(std::deque<int> &deq);
	class BadToken : public std::exception {
	private:
		std::string _message;

	public:
		BadToken();
		BadToken(const std::string &tokenReceive,
				const std::string &tokenExpected);
		const char *what() const throw();
		~BadToken() throw();
	};

	class NegativeValue : public std::exception {
	public:
		const char *what() const throw();
	};
	class Duplicate : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif