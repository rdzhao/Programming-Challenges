#include "Problem.h"

void Problem::launch()
{
	cout << filename << endl;
	read();
	solve();
	output();
}

void Problem::read()
{
	// TODO: implement details to read input
	file.open(filename.c_str(), std::ios::in);
	std::string str;
	std::getline(file, str);

	std::stringstream ss(str);
	ss >> i >> j;
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	mc = 0; // maximum cycle
	for (int k = i; k <= j; ++k)
	{
		int cycle = findCycle(k);
		if (cycle > mc)
			mc = cycle;
	}
}

void Problem::output()
{
	// TODO: implement details of output
	std::ofstream out("output.txt");
	out << i << " " << j << " " << mc << std::endl;
 	
}

int Problem::findCycle(int var)
{
	int cycle=1;
	
	while (var != 1)
	{
		++cycle;

		if (var % 2 == 0)
			var /= 2;
		else
			var = 3 * var + 1;
	}

	return cycle;
}