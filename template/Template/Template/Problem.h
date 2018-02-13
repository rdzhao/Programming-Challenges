#pragma once

#include <fstream>
#include <sstream>
#include <string>

class Problem
{
public:
	Problem(std::string fn) { filename = fn; };
	~Problem() {};

	void launch(); 

	void read();
	void solve();
	void output();

private:
	std::string filename;

	// TODO: set input parameters here as private member variables.


};