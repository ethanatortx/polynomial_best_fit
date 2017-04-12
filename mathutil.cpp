
#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
#include "cartesian.h"
#include "polar.h"
#include "mathutil.h"
#include "error.h"

template<class T>
int sgn(T val)
{
	return (T(0) < val) - (val < T(0));
}

int dimensions(polar c)
{
	int dim = 0;
	if(c.radius() != std::numeric_limits<double>::infinity())
		++dim;
	if(c.degree() != std::numeric_limits<double>::infinity())
		++dim;
	if(c.azimuth() != std::numeric_limits<double>::infinity())
		+dim;
	return dim;
}

int dimensions(cartesian c)
{
	int dim = 0;
	if(c.x() != std::numeric_limits<double>::infinity())
		++dim;
	if(c.y() != std::numeric_limits<double>::infinity())
		++dim;
	if(c.z() != std::numeric_limits<double>::infinity())
		+dim;
	return dim;
}

std::vector<double> bounding(std::vector<cartesian> cvec)
{
	std::sort(cvec.begin(), cvec.end());
	int x, y, z;
	if((((cvec.end()-1)->x() == std::numeric_limits<double>::infinity()) ^ (cvec.begin()->x() == std::numeric_limits<double>::infinity()))
		|| (((cvec.end()-1)->y() == std::numeric_limits<double>::infinity()) ^ (cvec.begin()->y() == std::numeric_limits<double>::infinity()))
		|| (((cvec.end()-1)->z() == std::numeric_limits<double>::infinity()) ^ (cvec.begin()->z() == std::numeric_limits<double>::infinity())))
	{
		error::dimensions_not_equivalent den;
		den.set_errno('c');
		throw den;
	}
	x = (cvec.end()-1)->x() - cvec.begin()->x();
	y = (cvec.end()-1)->y() - cvec.begin()->y();
	z = (cvec.end()-1)->z() - cvec.begin()->z();
	std::vector<double> bounds;
	if(x != 0.0)
		bounds.push_back(x);
	if(y != 0.0)
		bounds.push_back(y);
	if(z != 0.0)
		bounds.push_back(z);
	return bounds;
}

void print_histogram(std::vector<cartesian> cvec)
{
	std::sort(cvec.begin(), cvec.end());
	double oldx = (cvec[0]).x();
	for(std::vector<cartesian>::iterator i = cvec.begin(); i != cvec.end(); ++i)
	{
		if(i->x() == oldx)
			std::cout << "x ";
		else
		{
			oldx = i->x();
			std::cout << "\nx ";
		}
	}
}

void print_histogram(std::vector<cartesian> cvec, double variation)
{
	std::sort(cvec.begin(), cvec.end());
	double oldx = (cvec[0]).x();
	for(std::vector<cartesian>::iterator i = cvec.begin(); i != cvec.end(); ++i)
	{
		if((i->x() < oldx+variation) && (i->x() > oldx-variation))
			std::cout << "x ";
		else
		{
			oldx = i->x();
			std::cout << "\nx ";
		}
	}
}

long int distribution(std::vector<cartesian> cvec)
{
	int dim = dimensions(cvec[0]);
	std::vector<double> bounds = bounding(cvec);
	long int distrib = (int)(bounds[0]+1) * (int)(bounds[1]+1) * (int)(bounds[2]+1);
	return distrib % cvec.size();
}