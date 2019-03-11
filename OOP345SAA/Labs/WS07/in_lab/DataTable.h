#ifndef _SICT_DATATABLE_H
#define _SICT_DATATABLE_H

#include <iostream>
#include <fstream>

namespace sict
{
	class DataTable
	{
	public:
		DataTable(std::ifstream);
		void displayData(std::ostream&);
		void displayStatistics(std::ostream&);
	};
}
#endif // !_SICT_DATATABLE_H

