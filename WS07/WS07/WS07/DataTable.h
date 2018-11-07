// DataTable.h

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <algorithm>

namespace w7
{
	/**
	 *
	 * A class template for performing statistical analysis on data stored in text files
	 *
	 * Upon instantiation, a DataTable object receives a reference to the filestream that holds:
	 * - Data values
	 * - field width for displaying data
	 * - number of decimals to display
	 *
	 * The object retrieves the data values from the file and stores them in its instance variables
	 */

	template <class T>
	class DataTable
	{
		std::vector<std::pair<T, T>> m_DataSet;

		int m_width;
		int m_precision;

		static int const position;
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
		~DataTable()
		{

		}

		// returns the mean value of the dependent coordinate
		//
		T mean() const
		{

		}

		// returns the standard deviation of the dependent coordinates
		//
		T sigma() const
		{

		}
			
		// returns the median value of the dependent coordinate
		//
		T median() const
		{

		}

		// sets the parameters to the slope and intercept for the data set
		//
		void regression(T& slope, T& y_intercept) const
		{

		}

		// displays the data pairs as shown below
		//
		void display(std::ostream& os) const
		{
			for (const auto& p : m_DataSet)
				os << std::fixed << std::setw(m_width) << std::right << std::setprecision(m_precision) << p.first << " " << p.second << std::endl;
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
	};
}

#endif // !W7_DATATABLE_H