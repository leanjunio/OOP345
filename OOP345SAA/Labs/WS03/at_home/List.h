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
			const T& t = m_list[i];
			return t;
		}
		void operator+=(const T& t)
		{
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
	public:
		V accumulate(const L& label) const
		{
			// Initialize the accumulator to the initial value for objects of the label-value pair
			SummableLVPair<L,V> currentSummable;
			V sumOfElementsInCurrentLVList = currentSummable.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i)
			{
				// If the labels match, append the values
				if (label == ((List<T, N>&)*this)[i].getLabel())
					sumOfElementsInCurrentLVList = ((List<T, N>&)*this)[i].sum(label, sumOfElementsInCurrentLVList);
			}

			return sumOfElementsInCurrentLVList;
		}
	};
}

#endif // !_SICT_LIST_H