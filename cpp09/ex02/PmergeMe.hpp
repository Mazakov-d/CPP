#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#define PRINT 1


#include <exception>
#include <iostream>



class PmergeMe {
	private:
		int*	_input;
		size_t	_inputSize;
		int*	_jacobsthalSequence;
		size_t	_jacobsthalSequenceSize;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	jacobsthalSequence(size_t size);
		clock_t	FordJohnsonVector();
		clock_t	FordJohnsonDeque();
		void	parseInput(char** args);

		class BadToken : public std::exception {
			private:
				std::string	_message;
			public:
				BadToken();
				BadToken(const std::string& tokenReceive,const std::string& tokenExpected);
				const char* what() const throw();
				~BadToken() throw();
		};

		class NegativeValue : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif