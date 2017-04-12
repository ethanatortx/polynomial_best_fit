#ifndef _POLAR_H
#define _POLAR_H

#include <limits>
#include "cartesian.h"

class polar
{
public:
	polar(double r = std::numeric_limits<double>::infinity(), double d = std::numeric_limits<double>::infinity(), double a = std::numeric_limits<double>::infinity());
	polar(const polar& other);

	polar& operator=(const polar&);

	bool operator==(const polar&);
	bool operator!=(const polar&);
	bool operator<(const polar&);
	bool operator<=(const polar&);
	bool operator>(const polar&);
	bool operator>=(const polar&);

	polar operator+(const polar&);
	polar& operator+=(const polar&);
	polar operator-(const polar&);
	polar& operator-=(const polar&);

	void radius(double r);
	void degree(double d);
	void azimuth(double a);

	double radius() const;
	double degree() const;
	double azimuth() const;

private:
	double _radius, _degree, _azimuth;
};

#endif