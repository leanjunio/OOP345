#ifndef _SICT_LIST_H
#define _SICT_LIST_H

namespace sict
{
	template <class T, int N>
	class List
	{
		T m_list[N];
		size_t m_numElementsInArray = 0;
	public:
		
		size_t size() const
		{
			return m_numElementsInArray;
		}

		const T& operator[](size_t i) const
		{
			return m_list[i];
		}

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

	/*
	
	T - the type of any element in the array
	L - the type of the specified label
	V - the type of summation value
	N - the maximum number of elements in the array

	*/
	// a class template named LVList to manage a list of summable elements
	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, N>
	{
		// a query that receives a reference to an unmodifiable label (L) object
		// returns the sum of the values of all elements in the current LVList object in a locally created value (V) object 
		// initializes the accumulator (V) object to the initial value for objects of the label-value pair (T)
		// accumulates the values by calling the append query on each element in the list stored in the base class
		V accumulate(const L& label) const
		{
			// Initialize the accumulator to the initial value for objects of the label-value pair TODO: Ask prof to explain...
			V sumOfElementsInCurrentLVList = ((List<T, N>&)*this)->m_list[0];

			size_t numElementsInBaseObject = ((List<T, N>&)*this).size();
			
			// append each element stored in the base class
			for (int i = 0; i < numElementsInBaseObject; ++i)
				sumOfElementsInCurrentLVList += ((List<T, N>&)*this)->m_list[i];

			return sumOfElementsInCurrentLVList;
		}
	};
}

#endif // !_SICT_LIST_H

