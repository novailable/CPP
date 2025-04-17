#include "Point.hpp"

void    print_msg(Point p, bool is_inside)
{
    std::cout << "Point " << p << (is_inside ? " is " : " is not ") << "inside!" << std::endl;
}

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(3, 3);
    Point p2(0, 5);
    Point p3(10, 10);

	std::cout << "Triangle with a " << a << ", b" << b << ", c" << c << std::endl;
    print_msg(p1, (bsp(a, b, c, p1)));
    print_msg(p2, (bsp(a, b, c, p2)));
    print_msg(p3, (bsp(a, b, c, p3)));
}
