#ifndef _LIST_H
#define _LIST_H

#include <vector>

template<typename T, int N>
class List
{
	std::vector<T> m_List[N];				// Array of any data type of dimension 'N'
public:
	List()
	{
	}
	size_t size() const						// returns the number of entries in the array
	{
		return m_List->size();
	}
	const T& operator[](int index) const	// returns the element of 'index' requested
	{
		return m_List->at(index);
	}
	void operator+=(const T& el)				// Adds an element to the array if space is available
	{
		bool isSpaceAvailable = (this->size() < N);
		if (isSpaceAvailable)
			m_List->push_back(el);
	}
};

#endif // _LIST_H