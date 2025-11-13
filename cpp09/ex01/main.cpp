#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "Error: Usage './RPN \"inverted Polish mathematical expression\"'" << std::endl;
		return 1;
	}

	RPN	rpn;

	try {
		rpn.parseInput(av[1]);
		rpn.execute();
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}