#ifndef	WHATEVER_HPP
#define WHATEVER_HPP

template <typename S>
void	swap(S &a, S &b)
{
	S	temp = a;
	a = b;
	b = temp;
}

template <typename I>
I const	&min(I &a, I &b) {return (a < b ? a : b);}

template <typename A>
A const	&max(A &a, A &b) {return (a > b ? a : b);}

#endif