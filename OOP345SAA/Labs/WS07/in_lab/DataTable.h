#ifndef _SICT_DATATABLE_H
#define _SICT_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>

/**
 * External variables coming from w7.cpp
*/
extern int FW;
extern int ND;

namespace sict {
	/**
	 * A class that takes care of holding and processing statistical data
	 * The table structure will be defined using a vector container holding pair elements in each element of the vector
	 * std::vector<std::pair<T,T>> will be the structure
	 * 
	*/
	template<class T>
	class DataTable	{
		std::vector<std::pair<T,T>> m_dataTableNodes;
	public:

		/**
		 * One-arg constructor that reads every record from the file
		 * The file follows the format[X_Y], _ denotes the space
		 * The data will be stored in a pair, which is then stored in an index within the vector
		*/
		explicit DataTable(std::ifstream& file)	{
			bool keepReading = true;
			if (file) {
				T x = {0};
				T y = {0};
				do {
					if (file >> x >> y)
						m_dataTableNodes.push_back(std::make_pair(x,y));					
					else
						keepReading = false;
				} while (keepReading);
			}
		}

		/**
		 * Query function that displays the x-y data within the vector in the following format:
		 * 2.1000 8.0000
		 * 2.5000 12.0000
     * 4.0000 14.0000
     * 3.6000 10.0000
		 * 
		 * This can be done by utilizing the FW and ND provided from the main module
		 * The method iterates element by element through the vector displaying one pair at a time.
		 * To access first element from a pair: std::get<0>(pair_identifer)
		*/
		void displayData(std::ostream& os)	{
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (auto& i : m_dataTableNodes)
				os << std::setprecision(ND) << std::get<0>(i) << ' ' << std::get<1>(i) << std::endl;
		}
		void displayStatistics(std::ostream& os) {

		}
	};
}
#endif // !_SICT_DATATABLE_H

