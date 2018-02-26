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
	file.open(filename.c_str(), ios::in);

	string str;
	while (getline(file, str))
	{
		stringstream ss(str);
		int num;
		ss >> num;

		if (num != 0)
		{
			vector<double> tmp;
			for (int i = 0; i < num; ++i)
			{
				getline(file, str);
				stringstream sss(str);

				double mny;
				sss >> mny;
				tmp.push_back(mny);
			}
			expense.push_back(tmp);
		}
	}
}

void Problem::solve()
{
	// TODO: implement details of the algorithm
	for (int i = 0; i < expense.size(); ++i)
	{
		double exMny;
		solveInstance(i, exMny);
		solution.push_back(exMny);
	}
}

void Problem::output()
{
	// TODO: implement details of output
	fstream file;
	file.open("result.txt", ios::out);

	for (int i = 0; i < solution.size(); ++i)
		file << solution[i] << endl;
}

void Problem::solveInstance(int i, double& exMny)
{
	exMny = 0;
	double ave=0;
	for (int k = 0; k < expense[i].size(); ++k)
		ave += expense[i][k];
	ave /= expense[i].size();
	cout << ave << endl;

	for (int k = 0; k < expense[i].size(); ++k)
	{
		if (expense[i][k] > ave)
			exMny += expense[i][k] - ceil(ave * 100) / 100;
	}
}
