#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(3, 3);
    Point p2(0, 5);
    Point p3(10, 10);

	std::cout << "Triangle with a " << a << ", b" << b << ", c" << c << "\n"
	<< "Point p1" << p1 << (bsp(a, b, c, p1) ? " is inside!" : " is outside!") << "\n"
	<< "Point p2" << p2 << (bsp(a, b, c, p2) ? " is inside!" : " is outside!") << "\n"
	<< "Point p3" << p3 << (bsp(a, b, c, p3) ? " is inside!" : " is on edge!") << std::endl;

}
