#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

#include <cmath>
#include <algorithm>

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
	void solveInstance(int i, double& exMny);

private:
	std::string filename;
	
	// TODO: set input parameters here as private member variables.
	vector<vector<double>> expense;
	vector<double> solution;
};