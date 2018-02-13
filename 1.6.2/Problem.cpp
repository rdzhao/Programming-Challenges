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
	ifstream in(filename);

	string str;
	while (getline(in, str))
	{
		stringstream ss(str);
		int r, c;
		ss >> r >> c;

		if (r != 0 && c != 0)
		{
			row.push_back(r);
			col.push_back(c);
			string d = "";
			for (int i = 0; i < r; ++i)
			{
				getline(in, str);
				d += str;
			}
			data.push_back(d);
		}
		else
			break;
	}
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	for (int i = 0; i < row.size(); ++i)
	{
		vector<vector<char> > reshape;
		transform(row[i], col[i], data[i], reshape);
		process(reshape);
	}

}

void Problem::output()
{
	// TODO: implement details of output
	ofstream out("output.txt");
	
	for (int k = 0; k < row.size(); ++k)
	{
		out << "Field #" << k + 1 << ":" << endl;

		for (int i = 0; i < row[k]; ++i)
		{
			for (int j = 0; j < col[k]; ++j)
			{
				out << res[k][i*col[k] + j] << " ";
			}
			out << endl;
		}
	}
}

void Problem::transform(int r, int c, string data, vector<vector<char> >& reshape)
{
	for (int i = 0; i < r; ++i)
	{
		vector<char> tmp;
		for (int j = 0; j < c; ++j)
		{
			tmp.push_back(data[i*c + j]);
		}
		reshape.push_back(tmp);
	}
	
}

void Problem::process(vector<vector<char> > reshape)
{
	vector<vector<int> > r;

	for (int i = 0; i < reshape.size(); ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < reshape[i].size(); ++j)
		{
			if (reshape[i][j] == -1)
				tmp.push_back(-1);
			else
				tmp.push_back(0);
		}
		r.push_back(tmp);
	}

	for (int i = 0; i < reshape.size(); ++i)
		for (int j = 0; j < reshape[i].size(); ++j)
		{
			if (reshape[i][j] == '.')
			{
				// check adjacent
				if (valid(i - 1, j - 1, reshape.size(), reshape[i].size()) 
					&& reshape[i - 1][j - 1] == '*')
					r[i][j]++;
				if (valid(i - 1, j, reshape.size(), reshape[i].size())
					&& reshape[i - 1][j] == '*')
					r[i][j]++;
				if (valid(i - 1, j + 1, reshape.size(), reshape[i].size())
					&& reshape[i - 1][j + 1] == '*')
					r[i][j]++;

				if (valid(i, j - 1, reshape.size(), reshape[i].size())
					&& reshape[i][j - 1] == '*')
					r[i][j]++;
				if (valid(i, j + 1, reshape.size(), reshape[i].size())
					&& reshape[i][j + 1] == '*')
					r[i][j]++;

				if (valid(i + 1, j - 1, reshape.size(), reshape[i].size())
					&& reshape[i + 1][j - 1] == '*')
					r[i][j]++;
				if (valid(i + 1, j, reshape.size(), reshape[i].size())
					&& reshape[i + 1][j] == '*')
					r[i][j]++;
				if (valid(i + 1, j + 1, reshape.size(), reshape[i].size())
					&& reshape[i + 1][j + 1] == '*')
					r[i][j]++;
			}
			else
			{
				r[i][j] = -1;
			}
		}
	string s;
	for(int i=0; i<r.size(); ++i)
		for (int j = 0; j < r[i].size(); ++j)
		{
			if (r[i][j] != -1)
				s += static_cast<char>(r[i][j] + '0');
			else
				s += '*';
		}
	res.push_back(s);
}

bool Problem::valid(int i, int j, int r, int c)
{
	bool ok;

	if (i >= 0 && j >= 0 && i < r && j < c)
		ok = true;
	else
		ok = false;

	return ok;
}