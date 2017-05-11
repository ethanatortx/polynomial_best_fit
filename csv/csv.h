#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>
#include <fstream>
#include "..\utility\string_utility.h"

class csv_reader
{
	typedef std::vector<std::vector<std::string> > stringvector;
public:
	csv_reader(const std::string& nm);

	void read_all();
	void read_line();

	stringvector data() const;

private:
	std::string fname;
	stringvector svec;
	std::fstream file;
};

#endif