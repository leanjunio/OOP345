#ifndef _SICT_LIST_H
#define _SICT_LIST_H

namespace sict
{
	/* a class template named List for managing an array of any datatype

	The template parameters in order of their specification are
	a) T - the type of any element in the array
	b) N - the maximum number of elements in the array

	*/
	template <class T, int N>
	class List
	{
		size_t m_NumElementsInArray;
	public:
		
		// a query that returns the number 
		// of elements stored in the array
		size_t size() const
		{
			return size_t(1);
		}

		// an overloaded operator that receives 
		// an index and returns a reference to 
		// the unmodifiable object stored at that index of the array
		const T& operator[](size_t i) const
		{
			
		}

		// an overloaded operator that receives a reference 
		// to an unmodifiable object t of type T
		// If space to store the additional element is available, 
		// this operator appends a copy of the referenced object t 
		// to the set of elements currently stored in the array 
		// If space to store the additional element is not available, 
		// this operator does nothing
		void operator+=(const T& t)
		{

		}
	};
}

#endif // !_SICT_LIST_H

