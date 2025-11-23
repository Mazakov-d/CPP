#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<char>	_operators;
		std::stack<int>		_operands;

	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);

		void parseInput(const std::string& arg);
		void	execute();

		class InputError : public std::exception {
			public:
				const char* what() const throw();
		};

		class DivisionByZero : public std::exception {
			public:
				const char* what() const throw();
		};
};