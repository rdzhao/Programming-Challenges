#include <iostream>

#include "Problem.h"

int main(int argc, char* argv)
{
	Problem p(std::to_string(argv[1]));

	p.launch();

	return 1;
}