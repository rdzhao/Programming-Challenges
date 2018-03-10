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

class Image
{
public:
	vector<vector<char>> colors;
};

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
	void operationI(stringstream& ss, Image& img);
	void operationG(stringstream& ss, Image& img);
	void operationC(stringstream& ss, Image& img);
	void operationL(stringstream& ss, Image& img);
	void operationV(stringstream& ss, Image& img);
	void operationH(stringstream& ss, Image& img);
	void operationK(stringstream& ss, Image& img);
	void operationF(stringstream& ss, Image& img);
	void operationS(stringstream& ss, Image& img);
	void operationX(stringstream& ss, Image& img);

private:
	std::string filename;
	
	// TODO: set input parameters here as private member variables.
	vector<string> cmds;
	vector<string> files;
	vector<Image> images;

	bool terminate;
};