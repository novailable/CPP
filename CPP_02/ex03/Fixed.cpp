#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {};

Fixed::Fixed(const int i_value)
{
	_value = i_value << _frac_bit;
}

Fixed::Fixed(const float fl_value)
{
	_value = roundf(fl_value * (1 << _frac_bit));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

Fixed	Fixed::fixedRawBits(int const raw)
{
	Fixed	temp;
	temp.setRawBits(raw);
	return (temp);
}

Fixed::~Fixed() {}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const {return (_value);}

float	Fixed::toFloat(void) const {return (static_cast<float>(_value) / (1 << _frac_bit));}

int	Fixed::toInt(void) const{return (_value >> _frac_bit);}

bool	Fixed::operator<(const Fixed &other) const {return (this->_value < other._value);}
bool	Fixed::operator>(const Fixed &other) const {return (this->_value > other._value);}
bool	Fixed::operator<=(const Fixed &other) const {return (this->_value <= other._value);}
bool	Fixed::operator>=(const Fixed &other) const {return (this->_value >= other._value);}
bool	Fixed::operator==(const Fixed &other) const {return (this->_value == other._value);}
bool	Fixed::operator!=(const Fixed &other) const {return (this->_value != other._value);}

Fixed	Fixed::operator+(const Fixed &other) const {return Fixed::fixedRawBits(_value + other._value);}
Fixed	Fixed::operator-(const Fixed &other) const {return Fixed::fixedRawBits(_value - other._value);}

Fixed	Fixed::operator*(const Fixed &other) const
{
	long long	result = (long long)_value * other._value;
	return (Fixed::fixedRawBits((int)(result >> _frac_bit)));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._value == 0)
		return (Fixed::fixedRawBits(
			_value >= 0 ? std::numeric_limits<int>::max() 
						: std::numeric_limits<int>::min()));
	long long	result = (long long)_value << _frac_bit;
	return Fixed::fixedRawBits((int)(result / other._value));
}

Fixed	&Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--(*this);
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
