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
	public:

		// Receives a reference to the file, field width, number of decimals to display
		// The object retrieves data from the file and stores them as members
		//
		DataTable(std::ifstream& file, int width, int precision)
		{
			if (file.is_open())
			{
				float x, y;
				int count = 0;

				while (file >> x >> y)
				{
					// std::cout << "X: " << x << std::setprecision(precision) << " - Y: " << y << std::setprecision(precision) << std::endl;
					m_DataSet.push_back(std::make_pair(x, y));
				}

				std::cout << "V Size: " << m_DataSet.size() << std::endl;
				// std::cout << count << std::endl;
			}

		}	
		~DataTable()
		{

		}

		// returns the number of points in the dataset (the number of pairs)
		size_t getSize() const
		{
			return m_DataSet.size();
		}

		// sets the parameters to the slope and intercept for the data set
		void regression(T& slope, T& y_intercept) const
		{

		}

		/*void display(std::ostream& os) const
		{
			os << m_X << " " m_Y << std::endl;
		}

		std::ostream& operator<<(std::ostream& os, const DataTable& data)
		{
			data.display(os);
			return os;
		}*/
	};
}

#endif // !W7_DATATABLE_H