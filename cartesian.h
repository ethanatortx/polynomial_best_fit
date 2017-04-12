#ifndef _CARTESIAN_H
#define _CARTESIAN_H

#include <limits>
#include "polar.h"

class cartesian
{
public:
	cartesian(double _x = std::numeric_limits<double>::infinity(), double _y = std::numeric_limits<double>::infinity(), double _z = std::numeric_limits<double>::infinity());
	cartesian(const cartesian& other);

	cartesian& operator=(const cartesian&);

	bool operator==(const cartesian&);
	bool operator!=(const cartesian&);
	bool operator<(const cartesian&);
	bool operator<=(const cartesian&);
	bool operator>(const cartesian&);
	bool operator>=(const cartesian&);

	cartesian operator+(const cartesian&);
	cartesian& operator+=(const cartesian&);
	cartesian operator-(const cartesian&);
	cartesian& operator-=(const cartesian&);

	void x(double);
	void y(double);
	void z(double);

	double x() const;
	double y() const;
	double z() const;

private:
	double _x, _y, _z;
};

#endif