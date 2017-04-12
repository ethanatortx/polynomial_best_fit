#include <iostream>
#include <vector>
#include "poly_best_fit.h"

void print_coordvec(std::vector<cartesian> vec)
{
	for(typename std::vector<cartesian>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		switch(dimensions(*i))
		{
			case 1: std::cout << i->x() << '\n'; break;
			case 2: std::cout << i->x() << ' ' << i->y() << '\n'; break;
			case 3: std::cout << i->x() << ' ' << i->y() << ' ' << i->z() << '\n'; break;
		}
	}
}

int main()
{
	int count; std::cout << "How many coordinate pairs to generate? "; std::cin >> count;
	std::vector<cartesian> cvec;
	cartesian tmp;
	while(count--)
	{
		tmp.x(std::rand());
		tmp.y(std::rand());
		cvec.push_back(tmp);
	}

	print_coordvec(cvec);

	std::cout << "Bounding box area: (x: " << (bounding(cvec)[0]+1) << ", y: " << (bounding(cvec)[1]+1) << ", z: " << (bounding(cvec)[2]+1) << ")\n";
	std::cout << "Histogram:\n";
	print_histogram(cvec, 20000);
	//std::cout << "Distribution: " << distribution(cvec) << '\n';
	return 0;
}