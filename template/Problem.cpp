#include "Problem.h"

void Problem::launch()
{
	std::fstream file;
	file.open(filename.c_str(), std::ios::in);

	read();
	solve();
	output();
}

void Problem::read()
{
	// TODO: implement details to read input
}

void Problem::solve()
{
	// TODO: implement details of the algorithm

}

void Problem::output()
{
	// TODO: implement details of output

}