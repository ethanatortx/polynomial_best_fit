#include <vector>
#include <iostream>
#include <string>
#include "csv.h"

csv_reader::csv_reader(const std::string& nm):
	fname(nm)
{
	file.open(fname, std::ios_base::in);
}

void csv_reader::read_all()
{
	if(file.is_open())
	{
		while(!(file.eof()))
		{
			read_line();
		}
	}
}

void csv_reader::read_line()
{
	if(file.is_open())
	{
		if(!(file.eof())){
			std::string line;
			std::getline(file, line, '\n');
			std::vector<std::string> t(split_string(line, ',', '\"'));
			svec.push_back(t);
		}
	}
}

typename csv_reader::stringvector csv_reader::data() const { return svec; }
