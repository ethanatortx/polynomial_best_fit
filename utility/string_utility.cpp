#include <sstream>
#include "string_utility.h"

std::vector<std::string> split_string(std::string s, const char delim)
{
	std::stringstream ss(s);
	std::vector<std::string> svec;
	std::string frac;

	while(std::getline(ss, frac, delim))
	{
		svec.push_back(frac);
	}
	return svec;
}

std::vector<std::string> split_string(std::string s, const char delim, const char bounding)
{
	std::stringstream ss(s);
	std::vector<std::string> svec;
	std::string frac;

	while(std::getline(ss, frac, delim))
	{
		svec.push_back(frac);
	}

	unsigned dist;
	typename std::vector<std::string>::iterator i;
	for(i = svec.begin(); i != svec.end(); ++i)
	{
		if(i->operator[](0) == bounding)
		{
			while(i->operator[](i->size()-1) != bounding)
			{
				i->append(1, delim);
				i->append(*(i+1));
				dist = std::distance(svec.begin(), i);
				svec.erase(i+1);
				i = svec.begin()+dist;
			}
		}
	}
	return svec;
}
