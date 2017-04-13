#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <cmath>
#include <utility>
#include <vector>
#include "cartesian.h"

/* degree must be smaller than or equal to number of coordinates*/
template<unsigned order> /* amount of data pieces in each coord */
std::vector<cartesian<order> > generate(
	std::vector<cartesian<order> > cvec, /* vector of coordinates to determine from */
	int degree, /* leading degree of the polynomial */
	int points /* how many points to generate */)
{

}

#endif