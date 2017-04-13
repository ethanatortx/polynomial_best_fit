#ifndef _MATHUTIL_H
#define _MATHUTIL_H

#include <array>
#include <vector>
#include "cartesian.h"

template<unsigned  varCount>
class polynomial
{
public:
	polynomial(std::vector<double>);

	std::vector<cartesian<varCount> > calculate(double x, double i, unsigned count);

private:
	/*	Each index of the array contains one abstraction
			away from the original function definition:

		0: f(x) = function definition = y;
		1: g(x, y) = function definition = z;
		n: ...;

		The contents of each vector contains the coefficients
			of each term in the function of that array index

		0: 1 (x^2 * y);
		1: 4 (x * y * z);
		2: 0 (this denotes a placeholder term that contains no polynomial);
		n: ...;
	*/
	std::array<std::vector<double>, varCount> poly;
};

template<unsigned varCount>
std::vector<cartesian<varCount> > polynomial<varCount>::calculate(double x, double i, unsigned count)
{
	std::vector<cartesian<varCount> > vec(count);
	while(count)
	{
		cartesian<varCount> c;
		for(int i = varCount; i > 0; --i)
		{
			c[i] = /* TODO: make the actual calculate stuff func */
		}
		vec[count--] == c;
	}
}

#endif