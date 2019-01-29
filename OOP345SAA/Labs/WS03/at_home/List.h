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
		T m_list[N];
		size_t m_numElementsInArray = 0;
	public:
		
		// a query that returns the number 
		// of elements stored in the array
		size_t size() const
		{
			return m_numElementsInArray;
		}

		// an overloaded operator that receives 
		// an index and returns a reference to 
		// the unmodifiable object stored at that index of the array
		const T& operator[](size_t i) const
		{
			return m_list[i];
		}

		// an overloaded operator that receives a reference to an unmodifiable object t of type T
		// If space to store the additional element is available, 
		// this operator appends a copy of the referenced object t 
		// to the set of elements currently stored in the array 
		// If space to store the additional element is not available, 
		// this operator does nothing
		void operator+=(const T& t)
		{
			// check if there's space, if so, add the 't' into the list
			if (m_numElementsInArray < N)
			{
				m_list[m_numElementsInArray] = t;
				m_numElementsInArray++;
			}
		}
	};

	// a class template named LVList to manage a list of summable elements
	template<typename L, typename V>
	class LVList : List
	{
		// a query that receives a reference to an unmodifiable label (L) object
		// returns the sum of the values of all elements in the current LVList object in a locally created value (V) object 
		// initializes the accumulator (V) object to the initial value for objects of the label-value pair (T)
		// accumulates the values by calling the append query on each element in the list stored in the base class
		V accumulate(const L& label) const
		{

			// Initialize the accumulator to the initial value for objects of the label-value pair TODO: Ask prof to explain...
			V sumOfElementsInCurrentLVList = ((List<T, N>&)*this)->m_list[0];

			// append each element stored in the base class
			for (const auto &i : )
				sumOfElementsInCurrentLVList += ((List<T, N>&)*this)->m_list[i];

			return sumOfElementsInCurrentLVList;
		}
	};
}

#endif // !_SICT_LIST_H

