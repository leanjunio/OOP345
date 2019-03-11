#ifndef _SICT_DATATABLE_H
#define _SICT_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

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
					file >> x >> y;
					if (x && y)
						m_dataTableNodes.push_back(std::make_pair(x,y));					
					else
						keepReading = false;
				} while (keepReading);
				
				file >> x >> y;
			}
		}
		void displayData(std::ostream& os)	{

		}
		void displayStatistics(std::ostream& os) {

		}
	};
}
#endif // !_SICT_DATATABLE_H

