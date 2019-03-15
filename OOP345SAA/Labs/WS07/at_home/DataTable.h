#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>

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
	*/
	template<class T>
	class DataTable	{
		std::vector<std::pair<T,T>> m_data;
	private:
		/**
		 * Assistance methods
		 * Methods that assist in the calculation of queries
		 * 
		 * 
		 * 
		*/

		/**
		 * Private method that calculates the sum of the X and Y coordinates and returns them both via a pair object
		 * by using the STL algorithm: accumulate(begin, end, initialValue, [](currentValue - starts with the initialValue, currentValueInVector))
		 * Explanation:
		 * begin/end - range of the vector to iterate through
		 * initialValue - 'static_cast<T>(0)' -> make the initial value 0
		 * currentValue with init - the value starts with 0 and increases based on the returned value of the lambda
		 * currentValueInVector - the current element
		*/
		std::pair<T,T> sum_x_y() const {
			T t_x = {0};
			T t_y = {0};

			t_x += std::accumulate(m_data.begin(), m_data.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.first; });
			t_y += std::accumulate(m_data.begin(), m_data.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.second; });
			
			return std::make_pair(t_x, t_y);
		}

		/**
		 * Private method that returns all the x and y coordinates in a pair of enclosed vectors by using a range-based for loop
		*/
		std::pair<std::vector<T>,std::vector<T>> xy_collection() const {
			std::vector<T> x;
			std::vector<T> y;
			for (auto& i : m_data) {
				x.push_back(std::get<0>(i));
				y.push_back(std::get<1>(i));
			}
			return std::make_pair(x,y);			
		}

		/**
		 * Query Classes
		 * Classes that returns values that are requested from it (mean, sigma, slope, etc)
		 * 
		 * 
		 * 
		 * 
		*/
		/**
		 * private method that calculates the mean of all the Y coordinates
		 * The mean can be calculated using the following formula:
		 * mean = sum of all the integers on the Y/ num of integers on the Y
		*/
		T mean() const {
			std::pair<T,T> t_xy = sum_x_y();
			return std::get<1>(t_xy)/m_data.size();
		}

		/**
		 * Private method that calculates the sample standard deviation (sigma)
		 * To calculate the sigma:
		 * - [(y_element_n1 - mean)^2 + (y_element_n2 - mean)^2 + n3...]/num_of_elements - 1
		*/
		T sigma() const {
			T total = {0};
			std::pair<std::vector<T>, std::vector<T>> v_xy = xy_collection();
			std::vector<T> y = std::get<1>(v_xy);
			
			std::for_each(y.begin(), y.end(), [&](T& n) {
				total += std::pow(n - mean(), 2);
			});

			return std::sqrt(total/(y.size() - 1));
		}

		/**
		 * Private method that calculates the median 
		 * The median is described as the value that separates the values right in the middle
		 * In order to find the median, we can sort the values and then take the middle
		*/
		T median() const {
			std::pair<std::vector<T>,std::vector<T>> xy = xy_collection();
			std::vector<T> y = std::get<1>(xy);  
			std::sort(y.begin(), y.end());
			return y[y.size()/2];
		}

		/**
		 * Private method that calculates the slope
		 * The slope is the ratio of the amount that y increases as x increases
		 * The slope tells you how much y increases as x increases
		 * The following information is needed in order to calculate the slope:
		 * n - number of elements
		 * sum_x - sum of all the x coordinates
		 * sum_y - sum of all the y coordinates
		 * sum_prod_x_y - sum of the products of each x*y coordinates
		 * sum_squared_x - sum of all x^2
		*/
		T slope() const {
			size_t n = m_data.size();
			std::pair<T,T> sums_xy = sum_x_y();
			std::pair<std::vector<T>,std::vector<T>> v_xy = xy_collection();
			std::vector<T> x = std::get<0>(v_xy);
			T sum_x = std::get<0>(sums_xy);
			T sum_y = std::get<1>(sums_xy);
			
			T sum_prod_x_y = {0};
			std::for_each(m_data.begin(), m_data.end(), [&](auto& i) { sum_prod_x_y += i.first * i.second; });

			T sum_squared_x = {0};
			std::for_each(x.begin(), x.end(), [&](auto& i) { sum_squared_x += i * i; });
			
			T numerator = (n * sum_prod_x_y) - (sum_x * sum_y);
			T denominator = ((n * sum_squared_x) - (sum_x * sum_x));
			
			return numerator/denominator;
		}

		/**
		 * Private method that calculates the y-intercept of the given coordinates
		 * The following information is needed in order to calculate the intercept:
		 * slope
		 * n - number of elements
		 * sum_y - sum of all the y coordinates
		 * sum_x - sum of all the x coordinates
		 * 
		*/
		T intercept() const {
			size_t n = m_data.size();
			std::pair<T,T> sums_xy = sum_x_y();
			T sum_x = std::get<0>(sums_xy);
			T sum_y = std::get<1>(sums_xy);

			return (sum_y - (slope() * sum_x))/n;
		}
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
						m_data.push_back(std::make_pair(x,y));
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

			for (const auto& i : m_data)
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << std::right << std::get<0>(i) << std::setprecision(ND) << std::setw(FW) << std::get<1>(i) << std::endl;
		}

		/**
		 * Query that displays the statistics for the current object in the following format:
		 * y mean    = 11.0000
		 * y sigma   =  2.5820 
		 * y median  = 12.0000
     * slope     = 1.9087
     * intercept = 5.1784
		*/
		void displayStatistics(std::ostream& os) {
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y mean    = " << std::setw(FW) << mean() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y sigma   = " << std::setw(FW) << sigma() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y median  = " << std::setw(FW) << median() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  slope     = " << std::setw(FW) << slope() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  intercept = " << std::setw(FW) << intercept() << std::endl;
		}
	};
}
#endif // !SICT_DATA_TABLE_H