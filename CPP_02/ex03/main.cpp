#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(3, 3);
    Point p2(0, 5);
    Point p3(10, 10);

    std::cout << "Inside? " << bsp(a, b, c, p1) << std::endl; // 1
    std::cout << "On edge? " << bsp(a, b, c, p2) << std::endl; // 0
    std::cout << "Outside? " << bsp(a, b, c, p3) << std::endl; // 0

    return (0);
}
