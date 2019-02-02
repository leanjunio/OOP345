#ifndef _SICT_LIST_H
#define _SICT_LIST_H

namespace sict
{
	template <class T, int N>
	class List
	{
		T m_list[N];
		size_t m_numElementsInArray = {0u};
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

	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, N>
	{
		V accumulate(const L& label) const
		{
			// Initialize the accumulator to the initial value for objects of the label-value pair
			V sumOfElementsInCurrentLVList = SummableLVPair<L,V>::getInitialValue();

			size_t numElementsInBaseObject = ((List<T, N>&)*this).size();
			
			// append each element stored in the base class
			for (int i = 0; i < numElementsInBaseObject; ++i)
				sumOfElementsInCurrentLVList += ((List<T, N>&)*this)->m_list[i];

			return sumOfElementsInCurrentLVList;
		}
	};
}

#endif // !_SICT_LIST_H