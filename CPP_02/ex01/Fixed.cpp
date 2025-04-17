#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = i_value << _frac_bit;
}

Fixed::Fixed(const float fl_value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(fl_value * (1 << _frac_bit));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called" << std::endl;
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _frac_bit));
}

int	Fixed::toInt(void) const
{
	return (_value >> _frac_bit);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
