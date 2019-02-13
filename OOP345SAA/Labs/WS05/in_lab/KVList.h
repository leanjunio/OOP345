#ifndef _SICT_KVLIST_H
#define _SICT_KVLIST_H

namespace sict
{
	template <class T>
	class KVList
	{
		T* m_list;
		int m_numElementsInList;
	public:
		KVList()
			: m_list{nullptr}
			, m_numElementsInList{0}
		{
		}
		KVList(int n)
		{
			if (n > 0)
			{
				m_numElementsInList = { n };
				m_list = new T[n];
			}
			else
				*this = KVList();
		}
		KVList(KVList&& other)
		{
			if (this != &other)
			{
				m_list = other.m_list;
				m_numElementsInList = other.m_numElementsInList;

				other.m_list = { nullptr };
				other.m_numElementsInList = { 0 };
			}

			return *this;
		}
		~KVList()
		{
			delete[] m_list;
			m_list = { nullptr };
		}
		const T& operator[](size_t i) const
		{
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

		}
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& KVList(KVList&&) = delete;
	};
}

#endif // !_SICT_KVLIST_H



