#include <iostream>
#include "cartesian.h"
#include "mathutil.h"

int main()
{
	cartesian<3> c = {5.332, 2.354, 9.008};
	std::cout << c[0] << ' ' << c[1] << ' ' << c[2] << '\n';
	return 0;
};