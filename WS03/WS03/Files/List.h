// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: September 18, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _LIST_H
#define _LIST_H

#include <vector>

template<typename T, int N>
class List
{
	std::vector<T> m_List;					
public:
	List()
	{
		m_List.reserve(N);
	}
	size_t size() const						// returns the number of entries in the array
	{
		return m_List.size();
	}
	const T& operator[](int index) const	// returns the element of 'index' requested
	{
		return m_List.at(index);
	}
	void operator+=(const T& el)				// Adds an element to the array if space is available
	{
		bool isSpaceAvailable = (this->size() < N);
		if (isSpaceAvailable)
			m_List.push_back(el);
	}
};

#endif // _LIST_H