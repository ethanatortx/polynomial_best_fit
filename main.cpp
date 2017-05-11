
#include <algorithm>
#include <vector>
#include "csv\csv.h"
#include "table\table.h"

int main()
{
	csv_reader csv("dataSources\\crimeStats.csv");
	csv.read_all();
	std::vector<std::vector<std::string> > data = csv.data();
	hash_table<std::string, std::vector<std::string> > tbl;

	std::vector<std::string> s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17,s18;
	for(auto i = data.begin()+3; i != data.end()-7; ++i)
	{
		s0.push_back(i->operator[](0));
		s1.push_back(i->operator[](1));
		s2.push_back(i->operator[](2));
		s3.push_back(i->operator[](3));
		s4.push_back(i->operator[](4));
		s5.push_back(i->operator[](5));
		s6.push_back(i->operator[](6));
		s7.push_back(i->operator[](7));
		s8.push_back(i->operator[](8));
		s9.push_back(i->operator[](9));
		s10.push_back(i->operator[](10));
		s11.push_back(i->operator[](11));
		s12.push_back(i->operator[](12));
		s13.push_back(i->operator[](13));
		s14.push_back(i->operator[](14));
		s15.push_back(i->operator[](15));
		s16.push_back(i->operator[](16));
		s17.push_back(i->operator[](17));
		std::cout << "Running... " << std::distance(data.begin(), i)-3 << '\n';
		s18.push_back(i->operator[](18));
	}

	tbl.add(data[2][0], s0);
	tbl.add(data[2][1], s1);
	tbl.add(data[2][2], s2);
	tbl.add(data[2][3], s3);
	tbl.add(data[2][4], s4);
	tbl.add(data[2][5], s5);
	tbl.add(data[2][6], s6);
	tbl.add(data[2][7], s7);
	tbl.add(data[2][8], s8);
	tbl.add(data[2][9], s9);
	tbl.add(data[2][10], s10);
	tbl.add(data[2][11], s11);
	tbl.add(data[2][12], s12);
	tbl.add(data[2][13], s13);
	tbl.add(data[2][14], s14);
	tbl.add(data[2][15], s15);
	tbl.add(data[2][16], s16);
	tbl.add(data[2][17], s17);
	tbl.add(data[2][18], s18);

	std::string in; std::cout << "Statistic to retrieve: "; std::cin >> in;
	std::vector<std::string> specData = tbl[in];
	for(auto i = specData.begin(); i != specData.end(); ++i)
	{
		std::cout << (*i);
	}

	return 0;
};