#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>
#include <string>

namespace sict
{
	template <typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		LVPair()
			: m_label{}
			, m_value{}
		{
		}
		LVPair(const L& label, const V& value)
			: m_label(label)
			, m_value(value)
		{
		}

		const L& getLabel() const { return m_label; }
		const V& getValue() const { return m_value; }

		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		V m_initialValueForSummation = { 0u };
		size_t m_minFieldWidth;
	public:
		SummableLVPair()
		{
		}

		SummableLVPair(const L& label, const V& v)
			: LVPair<L, V>(label, v)
		{
			if (m_minFieldWidth < label.size())
				m_minFieldWidth = label.size() + 1;
		}
		
		const V& getInitialValue()
		{
			return m_initialValueForSummation;
		}

		V sum(const L& label, const V& sum) const
		{
			return LVPair<L, V>::getValue() + sum;
		}

		void display(std::ostream& os) const
		{
			
		}

	};

	template<> 
	SummableLVPair<std::string, std::string>::SummableLVPair(const std::string& label, const std::string& v)
		: LVPair(label, "")
	{
	}
	template<> 
	SummableLVPair<std::string, int>::SummableLVPair(const std::string& label, const int& v)
		: LVPair(label, 0)
	{
	}
}


#endif // !_SICT_LVPAIR_H

