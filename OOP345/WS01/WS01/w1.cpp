// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"

using namespace w1;
using namespace std;

// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp
extern int STORED;

int main(int argc, char* argv[])
{
	cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << ' ';
	}
	if (argc < 2)
	{
		cout << "\nInsufficient number of arguments\n";
		return 1;
	}

	// TODO: Add code here that will print out max characters
	// stored by your CString object
	cout << "\nMaximum number of characters stored: " << STORED << endl;

	for (int i = 1; i < argc; i++)
	{
		w1::process(argv[i], cout);
	}

	return 0;
}