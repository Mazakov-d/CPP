#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c , Point const point);

int main( void ) {
	Point a(3.4, 5);
	Point b(12, 1);
	Point c(0, 15);

	Point point(1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
}