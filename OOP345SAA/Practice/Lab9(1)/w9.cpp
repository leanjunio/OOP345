 // Workshop 10 - Multi-Threading
 // w10.cpp

 #include <iostream>
 #include <fstream>
 #include <string>
 #include "SecureData.h"

 int main(int argc, char** argv) {

	 std::ofstream ofs("Lab9Output.txt");

     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 4) {
         std::cerr << "\n***Incorrect number of arguments***\n"; 
         return 1;
     }
     char key = argv[3][0];

     try {
         w10::SecureData sd(argv[1], key, &ofs);
         sd.backup(argv[2]);

         sd.restore(argv[2], key);
         ofs << sd << std::endl;

     } catch (const std::string& msg) {
         ofs << msg << std::endl;
     }

     std::cout << "Results can be found in the Lab9Output.txt file\nPress any key to continue ... ";
     std::cin.get();

	 ofs.close();
}
