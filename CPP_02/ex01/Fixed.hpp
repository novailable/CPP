#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
		Fixed &operator = (const Fixed &other);
		~Fixed();

		void	setRawBits(int const raw);
		int	getRawBits(void) const;
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif