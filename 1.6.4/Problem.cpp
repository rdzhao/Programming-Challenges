#include "Problem.h"

void Problem::launch()
{
	read();
	cout << "Reading Complete!" << endl;
	solve();
	cout << "Solving Complete!" << endl;
	output();
	cout << "Output Complete!" << endl;
}

void Problem::read()
{
	// TODO: implement details to read input
	fstream file;
	file.open(filename, ios::in);

	string str;
	while (getline(file, str)){
		stringstream ss(str);
		int num;
		ss >> num;
		if (num != 0){
			len.push_back(num);
			string s;
			ss >> s;
			vector<int> d;
			for (int i = 0; i < s.size(); ++i)
				d.push_back(static_cast<int>(s[i] - '0'));
			data.push_back(d);
		}
	}
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	for (int i = 0; i < len.size(); ++i){
		vector<vector<char>> digits;
		buildDigits(len[i], digits);
		assemble(i ,len[i], digits);
	}
}

void Problem::output()
{
	// TODO: implement details of output
	fstream file;
	file.open("result.txt", ios::out);

	for (int i = 0; i < len.size(); ++i){
		//cout << data[i].size() << endl;
		for (int j = 0; j < res[i].size(); ++j){
			file << res[i][j];
			//cout << res[i][j];
			if ((j + 1) % ((len[i] + 2)*data[i].size()) == 0) {
				file << endl;
				//cout << endl;
			}
		}
	}
}

void Problem::buildDigits(int len, vector<vector<char>>& digits)
{
	vector<char> zero, one, two, three, four, five, six, seven, eight, nine;
	buildZero(len, zero);
	buildOne(len, one);
	buildTwo(len, two);
	buildThree(len, three);
	buildFour(len, four);
	buildFive(len, five);
	buildSix(len, six);
	buildSeven(len, seven);
	buildEight(len, eight);
	buildNine(len, nine);

	digits.push_back(zero);
	digits.push_back(one);
	digits.push_back(two);
	digits.push_back(three);
	digits.push_back(four);
	digits.push_back(five);
	digits.push_back(six);
	digits.push_back(seven);
	digits.push_back(eight);
	digits.push_back(nine);
}

void Problem::assemble(int k, int len, vector<vector<char>> digits)
{
	vector<char> r;
	for (int i = 0; i < 2 * len + 3; ++i){
		for (int j = 0; j < data[k].size(); ++j) {
			if (data[k][j] == 0)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[0][l + i*(len + 2)]);
			if (data[k][j] == 1)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[1][l + i*(len + 2)]);
			if (data[k][j] == 2)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[2][l + i*(len + 2)]);
			if (data[k][j] == 3)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[3][l + i*(len + 2)]);
			if (data[k][j] == 4)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[4][l + i*(len + 2)]);
			if (data[k][j] == 5)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[5][l + i*(len + 2)]);
			if (data[k][j] == 6)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[6][l + i*(len + 2)]);
			if (data[k][j] == 7)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[7][l + i*(len + 2)]);
			if (data[k][j] == 8)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[8][l + i*(len + 2)]);
			if (data[k][j] == 9)
				for (int l = 0; l < len + 2; ++l)
					r.push_back(digits[9][l + i*(len + 2)]);
		}
	}

	res.push_back(r);
}

void Problem::buildZero(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
	
	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 0; i < len + 2; ++i)
		d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildOne(int len, vector<char>& d)
{
	for (int i = 0; i < len+2; ++i)
		d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 0; i < len+2; ++i)
		d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 0; i < len+2; ++i)
		d.push_back(' ');
}

void Problem::buildTwo(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 2; ++i)
			d.push_back(' ');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildThree(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildFour(int len, vector<char>& d)
{
	for (int i = 0; i < len + 2; ++i)
		d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 1; i < len + 1; ++i)
		d.push_back(' ');
}

void Problem::buildFive(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 2; ++i)
			d.push_back(' ');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildSix(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 2; ++i)
			d.push_back(' ');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildSeven(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 0; i < len + 2; ++i)
		d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	for (int i = 0; i < len + 2; ++i)
		d.push_back(' ');
}
void Problem::buildEight(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}

void Problem::buildNine(int len, vector<char>& d)
{
	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		d.push_back('|');
		for (int i = 1; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');

	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len + 1; ++i)
			d.push_back(' ');
		d.push_back('|');
	}

	d.push_back(' ');
	for (int i = 1; i < len + 1; ++i)
		d.push_back('-');
	d.push_back(' ');
}
