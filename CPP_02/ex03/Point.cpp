#include "Point.hpp"

Point::Point() : _x(), _y() {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed	Point::get_x() const {return (_x);}

Fixed	Point::get_y() const {return (_y);}

static Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed result = ((b.get_x() - a.get_x()) * (c.get_y() - a.get_y()) -
				(b.get_y() - a.get_y()) * (c.get_x() - a.get_x()));
		
	result = result < 0 ? result * Fixed(-1) : result;
	return (result / Fixed(2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	full = area(a, b, c);
	Fixed	a1 = area(point, b, c);
	Fixed	a2 = area(a, point, c);
	Fixed	a3 = area(a, b, point);

	if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
		return (false);
	return (true);
}