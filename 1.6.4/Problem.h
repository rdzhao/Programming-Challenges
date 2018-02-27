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
	void buildDigits(int len, vector<vector<char>>& digits);
	void assemble(int k, int len, vector<vector<char>> digits);

	void buildZero(int len, vector<char>& d);
	void buildOne(int len, vector<char>& d);
	void buildTwo(int len, vector<char>& d);
	void buildThree(int len, vector<char>& d);
	void buildFour(int len, vector<char>& d);
	void buildFive(int len, vector<char>& d);
	void buildSix(int len, vector<char>& d);
	void buildSeven(int len, vector<char>& d);
	void buildEight(int len, vector<char>& d);
	void buildNine(int len, vector<char>& d);


private:
	std::string filename;
	
	// TODO: set input parameters here as private member variables.
	vector<int> len;
	vector<vector<int>> data;

	vector<vector<char>> res;
};