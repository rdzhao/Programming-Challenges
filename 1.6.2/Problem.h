#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

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
	void transform(int r, int c, string data, vector<vector<char> >& reshape);
	void process(vector<vector<char> > reshape);
	bool valid(int i, int j, int r, int c);

private:
	std::string filename;
	
	// TODO: set input parameters here as private member variables.
	vector<int> row, col;
	vector<string> data;
	vector<string> res;
};