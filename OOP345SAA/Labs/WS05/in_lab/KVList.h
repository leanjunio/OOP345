#ifndef _SICT_KVLIST_H
#define _SICT_KVLIST_H

namespace sict
{
	template <class T>
	class KVList
	{
		T* m_list;
		int m_numElementsInList;
		int m_numCurrentElementsInList;
	public:
		KVList()
			: m_list{nullptr}
			, m_numElementsInList{0}
			, m_numCurrentElementsInList{0}
		{
		}
		KVList(int n)
		{
			if (n > 0)
			{
				m_numElementsInList = { n };
				m_numCurrentElementsInList = { 0 };
				m_list = new T[n];
			}
			else
				throw "ERROR: Number of elements must be a positive number";
		}
		KVList(KVList&& other)
		{
			if (this != &other)
			{
				m_list = other.m_list;
				m_numElementsInList = other.m_numElementsInList;
				m_numCurrentElementsInList = other.m_numCurrentElementsInList;

				other.m_list = { nullptr };
				other.m_numElementsInList = { 0 };
				other.m_numCurrentElementsInList = { 0 };
			}
		}
		~KVList()
		{
			delete[] m_list;
			m_list = { nullptr };
		}
		const T& operator[](size_t i) const
		{
			if (i > m_numElementsInList)
				throw "ERROR: The index passed to the subscripting operator is out-of-bounds";
			return m_list[i];
		}
		template<typename F>
		void display(std::ostream& os, F f) const
		{
			for (int i = 0; i < m_numElementsInList; i++)
				m_list[i].display(os, f);
		}
		void push_back(const T& t)
		{
			if (m_numCurrentElementsInList + 1 <= m_numElementsInList)
				m_list[m_numCurrentElementsInList] = t;

			++m_numCurrentElementsInList;
		}
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
	};
}

#endif // !_SICT_KVLIST_H



