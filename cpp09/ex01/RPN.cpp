#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) {
	_operands = copy._operands;
	_operators = copy._operators;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
	{
		this->_operands = other._operands;
		this->_operators = other._operators;
	}
	return *this;
}

bool	isOperator(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return true;
	return false;
}

void RPN::parseInput(const std::string& arg) {
	for (size_t i = 0; i < arg.size(); ++i) {
		if (arg[i] == ' ')
			continue;
		if (isdigit(arg[i]))
		{
			if (arg[i + 1] && arg[i + 1] != ' ')
				throw(InputError());
			_operands.push(arg[i] - '0');
		}
		else if (isOperator(arg[i]))
			_operators.push(arg[i]);
		else
			throw(InputError());
	}
}

int	calculate(int a, int b, char c) {
	if (c == '/') {
		if (b == 0)
			throw(RPN::DivisionByZero());
		return (a / b);
	}
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	return (a * b);
}

void RPN::execute() {
	while (1) {
		if (_operands.size() <= 1 || _operators.empty())
			break;
		int	a = _operands.top();
		_operands.pop();

		int	b = _operands.top();
		_operands.pop();

		char	c = _operators.top();
		_operators.pop();

		_operands.push(calculate(a, b, c));
	}
	if (_operands.size() != 1 || !_operators.empty())
	{
		throw(InputError());
	}
	std::cout << _operands.top() << std::endl;
}




const char* RPN::InputError::what() const throw() {
	return "The input is not valid";
}

const char* RPN::DivisionByZero::what() const throw() {
	return "Division by zero impossible";
}
