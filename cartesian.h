#ifndef _CARTESIAN_H
#define _CARTESIAN_H

#include <initializer_list>
#include <stdexcept>

template<unsigned order>
class cartesian /* cartesian coordinate set of order M */
{
public:
	cartesian(); // construct coordinate system with [_m] elements
	cartesian(std::initializer_list<double> ilist);

	void clear(); // reset system
	unsigned size() const; // get dimensions of coordinate

	double& operator[](int); // get reference to coordinate at order

	~cartesian(); // delete coordinate array

private:
	double* carr; // array of size m containing coordinates
};

template<unsigned n>
cartesian<n>::cartesian() { carr = new double[n]; }
template<unsigned n>
cartesian<n>::cartesian(std::initializer_list<double> ilist)
{
	if(ilist.size() > n)
		throw std::runtime_error("Inintializer list conatins too many coordinates.");
	carr = new double[n];
	for(int i = 0; i < ilist.size(); ++i)
	{
		carr[i] = *(ilist.begin()+i);
	}
}
template<unsigned n>
cartesian<n>::~cartesian() { delete[] carr; }

template<unsigned n>
void cartesian<n>::clear() { delete[] carr; carr = new double[n]; }
template<unsigned n>
unsigned cartesian<n>::size() const { return n; }
template<unsigned n>
double& cartesian<n>::operator[](int p) { return carr[p]; }

#endif