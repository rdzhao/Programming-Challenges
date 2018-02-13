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
	string str;
	while (getline(file, str))
	{
		stringstream ss(str);
		int i, j;
		ss >> i >> j;
		lower.push_back(i);
		upper.push_back(j);
	}
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	for (int i = 0; i < lower.size(); ++i)
	{
		int mc = 0;
		for (int k = lower[i]; k <= upper[i]; ++k)
		{
			int cycle = findCycle(k);
			if (cycle > mc)
				mc = cycle;
		}

		maxCycle.push_back(mc);
	}
	
}

void Problem::output()
{
	// TODO: implement details of output
	std::ofstream out("output.txt");
	for (int i = 0; i < maxCycle.size(); ++i)
		out << lower[i] << " " << upper[i] << " " << maxCycle[i] << endl;
 	
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