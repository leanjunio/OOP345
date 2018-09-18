#ifndef _LIST_H
#define _LIST_H

template<typename T, int N>
class List
{
	T m_ListArr[N];							// Array of any data type of dimension 'N'
public:
	List()
		: m_ListArr{ nullptr }
	{
	}
	size_t size() const						// returns the number of entries in the array
	{
		
	}
	const T& operator[](int index) const	// returns the element of 'index' requested
	{
		return m_ListArr[index];
	}
	void operator+=(const T&)				// Adds an element to the array if space is available
	{

	}
};

#endif // !_LIST_H