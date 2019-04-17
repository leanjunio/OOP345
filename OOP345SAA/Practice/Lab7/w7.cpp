 // Workshop 7 - STL Algorithms
 // w7.cpp

 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 #include "DataTable.h"

 const int FW = 7;
 const int ND = 2;

 int main(int argc, char** argv) {

	 std::ofstream ofs("Lab7Output.txt");

     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 2 && argc != 3) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }
     std::ifstream dataFile(argv[1]);
     if (!dataFile) {
         std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
         return 2;
     }

     try {
		 w7::DataTable<float> data(dataFile, FW, ND);
		 if (argc == 3) {
			 ofs << "\nData Values\n===========\n";
			 ofs << data << std::endl;
		 }
		 float m, c;
		 data.regression(m, c);
		 ofs << "\nStatistics\n==========\n";
		 ofs << std::fixed << std::setprecision(ND);
		 ofs << "y mean    = " << std::setw(FW) << data.mean() <<
		  "\ny sigma   = " << std::setw(FW) << data.sigma() <<
		  "\ny median  = " << std::setw(FW) << data.median() << std::endl;
		 ofs << "slope     = " << std::setw(FW) << m <<
		  "\nintercept = " << std::setw(FW) << c << std::endl;
     }
     catch (std::string& msg) {
         ofs << msg << std::endl;
         return 3;
     }

     std::cout << "See full results in the Lab7Output.txt file\nPress any key to continue ... ";
     std::cin.get();

	 ofs.close();
 }

