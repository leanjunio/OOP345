#ifndef _SICT_DATATABLE_H
#define _SICT_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>

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

			for (const auto& i : m_dataTableNodes)
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << std::right << std::get<0>(i) << std::setprecision(ND) << std::setw(FW) << std::get<1>(i) << std::endl;
		}

		/**
		 * Query that displays the statistics for the current object in the following format:
		 * y mean    = 11.0000
		 * y sigma   =  2.5820 
		 * 
		 * The mean can be calculated using the following formula:
		 * mean = sum of all the integers on the Y/ num of integers on the Y
		*/
		void displayStatistics(std::ostream& os) {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
				
			// Calculating mean
			T sum_y = std::accumulate(m_dataTableNodes.begin(), m_dataTableNodes.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.second; });
			size_t num_of_elements = m_dataTableNodes.size();
			T mean = sum_y/num_of_elements;

			// Calculating sigma
			T total = {};
			
			// Create a vector containing all Ys
			std::vector<T> seconds = {};

			for (const auto& i : m_dataTableNodes)
				seconds.push_back(std::get<1>(i));

			std::for_each(seconds.begin(), seconds.end(), [&](T& el) 
			{ 
				total += std::pow(el - mean, 2);
			});

			T sigma = std::sqrt(total / (m_dataTableNodes.size() - 1));

			os << std::fixed << std::setprecision(ND) << "y mean" << std::setw(FW) << "=" << mean << std::endl;
			os << std::fixed << std::setprecision(ND) << "y sigma" << std::setw(FW) << "=" << sigma << std::endl;
		}
	};
}
#endif // !_SICT_DATATABLE_H

