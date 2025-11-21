#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <memory>
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <cstddef>

class PmergeMe {
	private:
		//first stack
		//second stack
		int*	_input;
		size_t	_inputSize;
		int*	_jacobsthalSequence;
		size_t	_jacobsthalSequenceSize;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

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