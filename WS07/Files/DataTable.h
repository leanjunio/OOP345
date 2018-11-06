// DataTable.h

#ifndef _DATATABLE_H
#define _DATATABLE_H

#include <fstream>
#include <algorithm>

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
public:
    DataTable(std::ifstream& file, int width, int precision);
    ~DataTable();
};

#endif