#include <iostream>
#include "Point.hpp" // Assuming you have a Point class and bsp function defined

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	std::cout << "--- BSP TRIANGLE TESTS ---" << std::endl;

	// Inside
	{
		Point p(2, 1);
		std::cout << "Test Inside (2,1): " << (bsp(a, b, c, p) ? "✅ Inside" : "❌ Outside") << std::endl;
	}

	// Outside
	{
		Point p(5, 5);
		std::cout << "Test Outside (5,5): " << (bsp(a, b, c, p) ? "✅ Inside" : "❌ Outside") << std::endl;
	}

	// On Edge AB
	{
		Point p(2, 0);
		std::cout << "Test On Edge AB (2,0): " << (bsp(a, b, c, p) ? "✅ Inside (edge)" : "❌ Outside (edge)") << std::endl;
	}

	// On Edge BC
	{
		Point p(3, 1.5);
		std::cout << "Test On Edge BC (3,1.5): " << (bsp(a, b, c, p) ? "✅ Inside (edge)" : "❌ Outside (edge)") << std::endl;
	}

	// On Edge CA
	{
		Point p(1, 1.5);
		std::cout << "Test On Edge CA (1,1.5): " << (bsp(a, b, c, p) ? "✅ Inside (edge)" : "❌ Outside (edge)") << std::endl;
	}

	// On Vertex A
	{
		Point p(0, 0);
		std::cout << "Test On Vertex A (0,0): " << (bsp(a, b, c, p) ? "✅ Inside (vertex)" : "❌ Outside (vertex)") << std::endl;
	}

	// On Vertex B
	{
		Point p(4, 0);
		std::cout << "Test On Vertex B (4,0): " << (bsp(a, b, c, p) ? "✅ Inside (vertex)" : "❌ Outside (vertex)") << std::endl;
	}

	// On Vertex C
	{
		Point p(2, 3);
		std::cout << "Test On Vertex C (2,3): " << (bsp(a, b, c, p) ? "✅ Inside (vertex)" : "❌ Outside (vertex)") << std::endl;
	}

	// Just barely inside
	{
		Point p(2, 0.01);
		std::cout << "Test Just Inside (2,0.01): " << (bsp(a, b, c, p) ? "✅ Inside" : "❌ Outside") << std::endl;
	}

	// Just barely outside
	{
		Point p(2, -0.01);
		std::cout << "Test Just Outside (2,-0.01): " << (bsp(a, b, c, p) ? "✅ Inside" : "❌ Outside") << std::endl;
	}

	return 0;
}
