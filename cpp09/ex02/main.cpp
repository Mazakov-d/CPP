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
		double timeVec = (double)ctx.FordJohnsonVector() * 1000000.0 / CLOCKS_PER_SEC;
		double timeDeq = (double)ctx.FordJohnsonDeque() * 1000000.0 / CLOCKS_PER_SEC;
		std::cout << "Time taken with std::vector : " << timeVec << " µs" << std::endl;
		std::cout << "Time taken with std::deque : " << timeDeq << " µs" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}