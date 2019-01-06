// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca 
// Date of completion: 11/8/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// DataTable.h

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

namespace w7
{
	template <class T>
	class DataTable
	{
		std::vector<std::pair<T, T>> m_DataSet;
		int m_width;
		int m_precision;
	public:
		// Receives a reference to the file, field width, number of decimals to display
		// The object retrieves data from the file and stores them as members
		//
		DataTable(std::ifstream& file, int width, int precision)
			: m_width(width),
			  m_precision(precision)
		{
			if (file.is_open())
			{
				float x, y;
				while (file >> x >> y)
					m_DataSet.push_back(std::make_pair(x, y));
			}
		}	

		// Returns the mean of the y coordinate
		//
		T mean() const
		{
			T total = {};
			for (const auto& p : m_DataSet)
				total += std::get<1>(p);

			return total/getSize();
		}

		// returns the standard deviation of the dependent coordinates
		//
		T sigma() const
		{
			T total = {};
			for (const auto& p : m_DataSet)
				total += pow(std::get<1>(p) - mean(), 2);

			return sqrt(total / (getSize() - 1));
		}
			
		// returns the median value of the dependent coordinate
		//
		T median() const
		{
			std::vector<T> Y = {};

			for (const auto& p : m_DataSet)
				Y.push_back(p.second);

			sort(Y.begin(), Y.end());

			return Y[Y.size()/2];
		}

		// sets the parameters to the slope and intercept for the data set
		//
		void regression(T& slope, T& y_intercept) const
		{
			slope = getSlope();
			y_intercept = getYIntercept();
		}

		// displays the data pairs as shown
		//
		void display(std::ostream& os) const
		{
			os << std::setw(m_width) << "x" << std::setw(m_width) << "y" << std::endl;
			
			for (const auto& p : m_DataSet)
				os << std::fixed << std::setprecision(m_precision) << std::setw(m_width) << p.first << std::setw(m_width) << p.second << std::endl;
		}

		// returns the number of points in the dataset (the number of pairs)
		//
		size_t getSize() const
		{
			return m_DataSet.size();
		}

		// calls the DataTable::display(...)
		//
		friend std::ostream& operator<<(std::ostream& os, const DataTable& data)
		{
			data.display(os);
			return os;
		}
	private:
		// Get the vector form of the first element of m_DataSet vectors
		//
		std::vector<T> getFirsts() const
		{
			std::vector<T> firsts = {};

			for (const auto& i : m_DataSet)
				firsts.push_back(std::get<0>(i));

			return firsts;
		}

		// Get the vector form of the second element of m_DataSet vectors
		//
		std::vector<T> getSeconds() const
		{
			std::vector<T> seconds = {};

			for (const auto& i : m_DataSet)
				seconds.push_back(std::get<1>(i));

			return seconds;
		}

		// Gets the sums from both the x and ys and returns them in a pair
		//
		std::pair<T, T> getSums() const
		{
			std::vector<T> firsts = getFirsts();
			std::vector<T> seconds = getSeconds();

			T sumX = std::accumulate(firsts.begin(), firsts.end(), 0.0);
			T sumY = std::accumulate(seconds.begin(), seconds.end(), 0.0);

			std::pair<T, T> sums = std::make_pair(sumX, sumY);

			return sums;
		}

		// gets the slope of the line in the x-y plane
		//
		T getSlope() const
		{
			std::vector<T> firsts = getFirsts();
			std::vector<T> seconds = getSeconds();

			std::pair<T, T> sums = std::move(getSums());
			std::pair<T, T> products = std::move(getInnerProducts());

			T a = (getSize() * products.second - sums.first * sums.second) / (getSize() * products.first - sums.first * sums.first);

			return a;
		}

		// Returns the y value of the line where the y axis is crossed
		//
		T getYIntercept() const
		{
			T slope = getSlope();
			std::pair<T, T> sums = std::move(getSums());

			return (sums.second - slope * sums.first) / getSize();
		}

		// Get the inner products of the x and ys
		//
		std::pair<T, T> getInnerProducts() const
		{
			std::vector<T> firsts = getFirsts();
			std::vector<T> seconds = getSeconds();

			T s_xx = std::inner_product(firsts.begin(), firsts.end(), firsts.begin(), static_cast<T>(0));
			T s_xy = std::inner_product(firsts.begin(), firsts.end(), seconds.begin(), static_cast<T>(0));

			std::pair<T, T> prods(s_xx, s_xy);

			return prods;
		}
	};
}

#endif // !W7_DATATABLE_H