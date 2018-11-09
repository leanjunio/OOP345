// Workshop 7 - STL Algorithms
// w7.cpp
// updated by cornel on 18.10.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "DataTable.h"
#include "DataTable.h" // this is intentional

const int FW = 8; // field width
const int ND = 4; // precision for numbers

using namespace std;

void processFile(const char* pFileName)
{
	cout << endl;
	cout << "****************************************" << endl;
	cout << "*** Processing file [" << pFileName << "]" << endl;
	cout << "****************************************" << endl;

	std::ifstream dataFile(pFileName);
	if (!dataFile)
	{
		cerr << endl << "***Failed to open file " << pFileName << "***" << endl;
		return;
	}

	try
	{
		w7::DataTable<float> data(dataFile, FW, ND);

		if (data.getSize() < 10)
		{
			cout << endl;
			cout << "Data Values" << endl
				 << "------------" << endl;
			cout << data;
		}

		float m, c;
		data.regression(m, c);
		cout << endl << "Statistics"
			 << endl << "----------";
		cout << fixed << setprecision(ND);
		cout << endl << "  y mean    = " << setw(FW) << data.mean()
			 << endl << "  y sigma   = " << setw(FW) << data.sigma()
			 << endl << "  y median  = " << setw(FW) << data.median()
			 << endl << "  slope     = " << setw(FW) << m
			 << endl << "  intercept = " << setw(FW) << c
			 << endl;
	}
	catch (std::string& msg)
	{
		cout << "ERROR: " << msg << endl;
	}
	cout << "************************************" << endl << endl;
}

int main(int argc, char** argv)
{
#ifndef W7_DATATABLE_H
	cout << "Bad header guard for DataTable.h! Follow the convention "
		<< "when choosing a header guard as swhown at the lecture.\n";
#endif

    cout << "Command Line: " << argv[0];
    for (int i = 1; i < argc; i++)
        cout << " " << argv[i];
	cout << endl;

	if (argc != 3)
	{
        cerr << endl << "***Incorrect number of arguments***" << endl;
        return 1;
    }
   
	processFile(argv[1]);
	processFile(argv[2]);

		return 0;
}