#include "PmergeMe.hpp"

int	badUsage() {
	std::cerr << "Usage: ./PmergeMe [sequence of positive intergers]" << std::endl;
	return 1;
}

int main(int ac, char** av) {
	if (ac <= 1)
		return badUsage();
	PmergeMe	ctx;
	try {
		ctx.parseInput(av + 1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}