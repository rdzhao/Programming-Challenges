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
	
	ifstream file(filename.c_str());
	
	string line;
	while (getline(file, line)) {
		cmds.push_back(line);
	}
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	terminate = false;
	int i = 0;
	Image img;
	while (!terminate && i<cmds.size())
	{
		stringstream ss(cmds[i]);
		char operation;
		ss >> operation;

		switch (operation) {
		case 'I':
			operationI(ss, img);
			break;
		case 'G':
			operationG(ss, img);
			break;
		case 'C':
			operationC(ss, img);
			break;
		case 'L':
			operationL(ss, img);
			break;
		case 'V':
			operationV(ss, img);
			break;
		case 'H':
			operationH(ss, img);
			break;
		case 'K':
			operationK(ss, img);
			break;
		case 'F':
			operationF(ss, img);
			break;
		case 'S':
			operationS(ss, img);
			break;
		case 'X':
			operationX(ss, img);
		default:
			break;
		}

		++i;
	}
}

void Problem::output()
{
	// TODO: implement details of output
	ofstream out("results.txt");

	for (int i = 0; i < files.size(); ++i)
	{
		out << files[i] << endl;;
		for (int j = 0; j < images[i].colors.size(); ++j) {
			for (int k = 0; k < images[i].colors[0].size(); ++k) {
				out << images[i].colors[j][k];
			}
			out << endl;
		}
	}
}

void Problem::operationI(stringstream& ss, Image& img)
{
	int m, n;
	ss >> m >> n;

	img.colors.clear();
	img.colors.reserve(m);

	vector<char> tmp;
	tmp.reserve(n);
	for (int i = 0; i < n; ++i) {
		tmp.push_back('O');
	}
	
	for (int i = 0; i < m; ++i) {
		img.colors.push_back(tmp);
	}
}

void Problem::operationG(stringstream& ss, Image& img)
{
	int m, n;
	char c;
	ss >> m >> n >> c;

	img.colors.clear();
	img.colors.reserve(m);

	vector<char> tmp;
	tmp.reserve(n);
	for (int i = 0; i < n; ++i) {
		tmp.push_back(c);
	}

	for (int i = 0; i < m; ++i) {
		img.colors.push_back(tmp);
	}
}

void Problem::operationC(stringstream& ss, Image& img)
{
	for (int i = 0; i < img.colors.size(); ++i) {
		for (int j = 0; j < img.colors[0].size(); ++j) {
			img.colors[i][j] = 'O';
		}
	}
}

void Problem::operationL(stringstream& ss, Image& img)
{
	int x, y;
	char color;
	ss >> x >> y >> color;

	x -= 1;
	y -= 1;

	int row, col;
	if (img.colors.empty()) {
		row = 0;
		col = 0;
	}
	else {
		row = img.colors.size();
		col = img.colors[0].size();
	}

	if (x >= 0 && x < col && y >= 0 && y < row) {
		img.colors[y][x] = color;
	}
}

void Problem::operationV(stringstream& ss, Image& img)
{
	int x, y1, y2;
	char color;
	ss >> x >> y1 >> y2 >> color;

	x -= 1;
	y1 -= 1;
	y2 -= 1;

	int row, col;
	if (img.colors.empty()) {
		row = 0;
		col = 0;
	}
	else {
		row = img.colors.size();
		col = img.colors[0].size();
	}

	if (x >= 0 && x < col && y1 >= 0 && y1 < row && y2 >= 0 && y2 < row && y1 <= y2) {
		for (int i = y1; i <= y2; ++i) {
			img.colors[i][x] = color;
		}
	}
}

void Problem::operationH(stringstream& ss, Image& img)
{
	int x1, x2, y;
	char color;
	ss >> x1 >> x2 >> y >> color;

	x1 -= 1;
	x2 -= 1;
	y -= 1;

	int row, col;
	if (img.colors.empty()) {
		row = 0;
		col = 0;
	}
	else {
		row = img.colors.size();
		col = img.colors[0].size();
	}

	if (x1 >= 0 && x1 < col && x2 >= 0 && x2 < col && y >= 0 && y < row && x1 <= x2) {
		for (int i = x1; i <= x2; ++i) {
			img.colors[y][i] = color;
		}
	}
}

void Problem::operationK(stringstream& ss, Image& img)
{
	int x1, x2, y1, y2;
	char color;
	ss >> x1 >> y1 >> x2 >> y2>> color;

	x1 -= 1;
	x2 -= 1;
	y1 -= 1;
	y2 -= 1;

	int row, col;
	if (img.colors.empty()) {
		row = 0;
		col = 0;
	}
	else {
		row = img.colors.size();
		col = img.colors[0].size();
	}

	if (x1 >= 0 && x1 < col && x2 >= 0 && x2 < col && y1 >= 0 && y1 < row && y2 >= 0 && y2 < row && x1 <= x2 && y1 <= y2) {
		for (int i = x1; i <= x2; ++i) {
			for (int j = y1; j <= y2; ++j) {
				img.colors[j][i] = color;
			}
		}
	}
}

void Problem::operationF(stringstream& ss, Image& img)
{
	int x, y;
	char color;
	ss >> x >> y >> color;

	x -= 1;
	y -= 1;

	int row, col;
	if (img.colors.empty()) {
		row = 0;
		col = 0;
	}
	else {
		row = img.colors.size();
		col = img.colors[0].size();
	}

	if (x >= 0 && x < col && y >= 0 && y < row) {
		char oc=img.colors[y][x];
		stack<int> xcoord, ycoord;
		xcoord.push(x);
		ycoord.push(y);

		while (!xcoord.empty()) {
			int tx, ty;
			tx = xcoord.top();
			ty = ycoord.top();
			xcoord.pop();
			ycoord.pop();

			img.colors[ty][tx] = color;

			if (tx - 1 >= 0 && img.colors[ty][tx - 1] == oc) {
				xcoord.push(tx - 1);
				ycoord.push(ty);
			}
			if (tx + 1 < col && img.colors[ty][tx + 1] == oc) {
				xcoord.push(tx + 1);
				ycoord.push(ty);
			}
			if (ty - 1 >= 0 && img.colors[ty - 1][tx] == oc) {
				xcoord.push(tx);
				ycoord.push(ty - 1);
			}
			if (ty + 1 < row && img.colors[ty + 1][tx] == oc) {
				xcoord.push(tx);
				ycoord.push(ty + 1);
			}
		}
	}
}

void Problem::operationS(stringstream& ss, Image& img)
{
	string fn;
	ss >> fn;

	files.push_back(fn);
	images.push_back(img);
}

void Problem::operationX(stringstream& ss, Image& img)
{
	terminate = true;
}
