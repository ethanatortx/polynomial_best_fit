
#include <cmath>
#include "cartesian.h"
#include "polar.h"

polar::polar(double r, double d, double a):
	_radius(r), _degree(d), _azimuth(a) {}
polar::polar(const polar& other):
	_radius(other.radius()), _degree(other.degree()), _azimuth(other.azimuth()) {}

void polar::radius(double r)
{ _radius = r; }
void polar::degree(double d)
{ _degree = d; }
void polar::azimuth(double a)
{ _azimuth = a; }

double polar::radius() const
{ return _radius; }
double polar::degree() const
{ return _degree; }
double polar::azimuth() const
{ return _azimuth; }

cartesian convert(const polar& p)
{
	cartesian c;
	if(p.radius() != std::numeric_limits<double>::infinity())
	{
		if(p.degree() != std::numeric_limits<double>::infinity())
		{
			if(p.azimuth() != std::numeric_limits<double>::infinity())
			{
				c.x(std::cos(p.azimuth())*std::cos(p.degree())*p.radius());
				c.y(std::cos(p.azimuth())*std::sin(p.degree())*p.radius());
				c.z(std::sin(p.azimuth())*p.radius());
			}
			else
			{
				c.x(std::cos(p.degree())*p.radius());
				c.y(std::sin(p.degree())*p.radius());
			}
		}
		else
		{
			c.x(p.radius());
		}
	}
	return c;
}

polar& polar::operator=(const polar& rhs)
{
	radius(rhs.radius());
	degree(rhs.degree());
	azimuth(rhs.azimuth());
	return *this;
}
bool polar::operator==(const polar& rhs)
{
	if(_radius == rhs.radius())
		if(_degree == rhs.degree())
			if(_azimuth == rhs.azimuth())
				return true;
	return false;
}
bool polar::operator!=(const polar& rhs)
{
	if(_radius != rhs.radius())
		return true;
	else if(_degree != rhs.degree())
		return true;
	else if(_azimuth != rhs.azimuth())
		return true;
	else
		return false;
}
bool polar::operator<(const polar& rhs)
{
	if(_radius < rhs.radius())
		return true;
	else if(_radius == rhs.radius())
	{
		if(_degree < rhs.degree())
			return true;
		else if(_degree == rhs.degree())
			if(_azimuth < rhs.azimuth())
				return true;
	}
	return false;
}
bool polar::operator<=(const polar& rhs)
{
	return ((*this) < rhs) || ((*this) == rhs);
}
bool polar::operator>(const polar& rhs)
{
	if(_radius > rhs.radius())
		return true;
	else if(_radius == rhs.radius())
	{
		if(_degree > rhs.degree())
			return true;
		else if(_degree == rhs.degree())
			if(_azimuth > rhs.azimuth())
				return true;
	}
	return false;
}
bool polar::operator>=(const polar& rhs)
{
	return ((*this) > rhs) || ((*this) == rhs);
}
polar polar::operator+(const polar& rhs)
{
	polar p;
	if(radius() == std::numeric_limits<double>::infinity())
		if(rhs.radius() != std::numeric_limits<double>::infinity())
			p.radius(rhs.radius());
	else
	{
		if(rhs.radius() != std::numeric_limits<double>::infinity())
			p.radius(radius() + rhs.radius());
		else
			p.radius(radius());
	}

	if(degree() == std::numeric_limits<double>::infinity())
		if(rhs.degree() != std::numeric_limits<double>::infinity())
			p.degree(rhs.degree());
	else
	{
		if(rhs.degree() != std::numeric_limits<double>::infinity())
			p.degree(degree() + rhs.degree());
		else
			p.degree(degree());
	}
	
	if(azimuth() == std::numeric_limits<double>::infinity())
		if(rhs.azimuth() != std::numeric_limits<double>::infinity())
			p.azimuth(rhs.azimuth());
	else
	{
		if(rhs.azimuth() != std::numeric_limits<double>::infinity())
			p.azimuth(azimuth() + rhs.azimuth());
		else
			p.azimuth(azimuth());
	}

	return p;
}
polar& polar::operator+=(const polar& rhs)
{
	this->operator=((*this) + rhs);
	return *this;
}
polar polar::operator-(const polar& rhs)
{
	polar p;
	if(radius() == std::numeric_limits<double>::infinity())
		if(rhs.radius() != std::numeric_limits<double>::infinity())
			p.radius(0.0 - (rhs.radius()));
	else
	{
		if(rhs.radius() != std::numeric_limits<double>::infinity())
			p.radius(radius() - rhs.radius());
		else
			p.radius(radius());
	}

	if(degree() == std::numeric_limits<double>::infinity())
		if(rhs.degree() != std::numeric_limits<double>::infinity())
			p.degree(0.0 - (rhs.degree()));
	else
	{
		if(rhs.degree() != std::numeric_limits<double>::infinity())
			p.degree(degree() - rhs.degree());
		else
			p.degree(degree());
	}
	
	if(azimuth() == std::numeric_limits<double>::infinity())
		if(rhs.azimuth() != std::numeric_limits<double>::infinity())
			p.azimuth(0.0 - (rhs.azimuth()));
	else
	{
		if(rhs.azimuth() != std::numeric_limits<double>::infinity())
			p.azimuth(azimuth() - rhs.azimuth());
		else
			p.azimuth(azimuth());
	}

	return p;
}
polar& polar::operator-=(const polar& rhs)
{
	this->operator=((*this) - rhs);
	return *this;
}
