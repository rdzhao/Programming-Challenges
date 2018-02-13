#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Problem
{
public:
	Problem(std::string fn) { filename = fn; };
	~Problem() {};

	void launch(); 

	void read();
	void solve();
	void output();

	// TODO: additional helper functions

private:
	std::string filename;
	std::fstream file;
	
	// TODO: set input parameters here as private member variables.

};