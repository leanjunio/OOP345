// DataTable.h

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
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
		T nm_X;
		T m_Y;
	public:

		// Receives a reference to the file, field width, number of decimals to display
		// The object retrieves data from the file and stores them as members
		//
		DataTable(std::ifstream& file, int width, int precision)
		{
			if (file.is_open())
			{
				
			}

		}
		~DataTable()
		{

		}

		// returns the number of points in the dataset (the number of pairs)
		size_t getSize() const
		{

		}

		// sets the parameters to the slope and intercept for the data set
		void regression(T& slope, T& y_intercept) const
		{

		}
	};
}

#endif // !W7_DATATABLE_H