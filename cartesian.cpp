
#include <cmath>
#include "polar.h"
#include "cartesian.h"

cartesian::cartesian(double X, double Y, double Z): _x(X), _y(Y), _z(Z) {}
cartesian::cartesian(const cartesian& other): _x(other._x), _y(other._y), _z(other._z) {}

void cartesian::x(double X)
{ _x = X; }
void cartesian::y(double Y)
{ _y = Y; }
void cartesian::z(double Z)
{ _z = Z; }

double cartesian::x() const
{ return _x; }
double cartesian::y() const
{ return _y; }
double cartesian::z() const
{ return _z; }

polar convert(const cartesian& c)
{
	polar p;
	if(c.x() != std::numeric_limits<double>::infinity())
	{
		if(c.y() != std::numeric_limits<double>::infinity())
		{
			if(c.z() != std::numeric_limits<double>::infinity())
			{
				p.radius(std::sqrt( (c.x() * c.x()) + (c.y() * c.y()) + (c.z() * c.z()) ));
				p.degree(std::atan(c.y() / c.x()));
				p.azimuth(std::atan(c.z() / (std::sqrt((c.x() * c.x()) + (c.y() * c.y())) )));
			}
			else
			{
				p.radius(std::sqrt( (c.x() * c.x()) + (c.y() * c.y()) ));
				p.degree(std::atan(c.y() / c.x()));
			}
		}
		else
		{
			p.radius(c.x());
		}
	}
	return p;
}

cartesian& cartesian::operator=(const cartesian& rhs)
{
	x(rhs.x());
	y(rhs.y());
	z(rhs.z());
	return *this;
}

bool cartesian::operator==(const cartesian& rhs)
{
	if(x() == rhs.x())
		if(y() == rhs.y())
			if(z() == rhs.z())
				return true;
	return false;
}
bool cartesian::operator!=(const cartesian& rhs)
{
	if(x() != rhs.x())
		return true;
	else if(y() != rhs.y())
		return true;
	else if(z() != rhs.z())
		return true;
	else
		return false;
}
bool cartesian::operator<(const cartesian& rhs)
{
	if(x() >= rhs.x())
		return false;
	else if(y() >= rhs.y())
		return false;
	else if(z() >= rhs.z())
		return false;
	else
		return true;
}
bool cartesian::operator<=(const cartesian& rhs)
{
	return ((*this) < rhs) || ((*this) == rhs);
}
bool cartesian::operator>(const cartesian& rhs)
{
	if(x() <= rhs.x())
		return false;
	else if(y() <= rhs.y())
		return false;
	else if(z() <= rhs.z())
		return false;
	else
		return true;
}
bool cartesian::operator>=(const cartesian& rhs)
{
	return ((*this) < rhs) || ((*this) == rhs);
}
cartesian cartesian::operator+(const cartesian& rhs)
{
	cartesian c;
	if(x() == std::numeric_limits<double>::infinity())
		if(rhs.x() != std::numeric_limits<double>::infinity())
			c.x(rhs.x());
	else
	{
		if(rhs.x() != std::numeric_limits<double>::infinity())
			c.x(x() + rhs.x());
		else
			c.x(x());
	}

	if(y() == std::numeric_limits<double>::infinity())
		if(rhs.y() != std::numeric_limits<double>::infinity())
			c.y(rhs.y());
	else
	{
		if(rhs.y() != std::numeric_limits<double>::infinity())
			c.y(y() + rhs.y());
		else
			c.y(y());
	}

	if(z() == std::numeric_limits<double>::infinity())
		if(rhs.z() != std::numeric_limits<double>::infinity())
			c.z(rhs.z());
	else
	{
		if(rhs.z() != std::numeric_limits<double>::infinity())
			c.z(z() + rhs.z());
		else
			c.z(z());
	}

	return c;
}
cartesian& cartesian::operator+=(const cartesian& rhs)
{
	this->operator=((*this) + rhs);
	return (*this);
}

cartesian cartesian::operator-(const cartesian& rhs)
{
	cartesian c;
	if(x() == std::numeric_limits<double>::infinity())
		if(rhs.x() != std::numeric_limits<double>::infinity())
			c.x(0.0 - (rhs.x()));
	else
	{
		if(rhs.x() != std::numeric_limits<double>::infinity())
			c.x(x() - rhs.x());
		else
			c.x(x());
	}

	if(y() == std::numeric_limits<double>::infinity())
		if(rhs.y() != std::numeric_limits<double>::infinity())
			c.y(0.0 - (rhs.y()));
	else
	{
		if(rhs.y() != std::numeric_limits<double>::infinity())
			c.y(y() - rhs.y());
		else
			c.y(y());
	}

	if(z() == std::numeric_limits<double>::infinity())
		if(rhs.z() != std::numeric_limits<double>::infinity())
			c.z(0.0 - (rhs.z()));
	else
	{
		if(rhs.z() != std::numeric_limits<double>::infinity())
			c.z(z() - rhs.z());
		else
			c.z(z());
	}

	return c;
}
cartesian& cartesian::operator-=(const cartesian& rhs)
{
	this->operator=((*this) - rhs);
	return (*this);
}