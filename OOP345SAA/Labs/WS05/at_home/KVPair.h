#ifndef _SICT_KVPAIR_H
#define _SICT_KVPAIR_H

#include <iostream>
#include <iomanip>

extern int fieldWidth;

namespace sict
{
	template<typename K, typename V>
	class KVPair
	{
		K m_key;
		V m_value;
	public:
		KVPair()
			: m_key{}
			, m_value{}
		{
		}
		KVPair(const K& key, const V& value)
			: m_key{key}
			, m_value{value}
		{
		}
		template<typename F> 
		void display(std::ostream& os, F f) const
		{
			os << std::left << std::setw(fieldWidth) << m_key << " " << ":" << " " << std::right << std::setw(fieldWidth) << m_value << std::setw(fieldWidth) << f(m_value) << std::endl;
		}
	};
}

#endif // !_SICT_KVPAIR_H