#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class	Fixed
{
	private:
		int	_value;
		static const int	_frac_bit = 8;

	public:
		Fixed();
		Fixed(const int i_value);
		Fixed(const float fl_value);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		~Fixed();

		static Fixed	fixedRawBits(int const raw);
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		float	toFloat(void) const;
		int	toInt(void) const;
		
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);

		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif