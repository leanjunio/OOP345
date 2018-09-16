#include "List.h"

template<typename T, int N>
inline List<T, N>::List()
{
}

template<typename T, int N>
size_t List<T, N>::size() const
{
	return sizeof(m_ListArr/sizeof(m_ListArr[0]));
}

template<typename T, int N>
const T & List<T, N>::operator[](int index) const
{
	return m_ListArr[index];
}

template<typename T, int N>
void List<T, N>::operator+=(const T &)
{
	size_t length = this->size();

	if (length < N)
		m_ListArr[length + 1] = t;
}