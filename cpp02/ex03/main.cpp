#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c , Point const point);

int main( void ) {
	Point a(1, 1);
	Point b(12, 1);
	Point c(7.5, 12);

	Point point(3.4, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
}