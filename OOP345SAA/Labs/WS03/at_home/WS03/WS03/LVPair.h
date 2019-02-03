#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>
#include <string>

namespace sict
{
	/*
	
	defines a class template for a label-value pair (for example, a product label stored in an std::string object and a quantity stored in an int object)
	
	*/
	template <typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		// leaves the object in a safe empty state
		LVPair()
			: m_label{}
			, m_value{}
		{
		}

		// an overloaded constructor that copies the values received 
		// in its parameters into the instance variables
		LVPair(const L& label, const V& value)
			: m_label(label)
			, m_value(value)
		{
		}

		const L& getLabel() { return m_label; }
		const V& getValue() { return m_value; }

		// a query that inserts into os the label and value 
		// stored in the current object separated by 
		// a space - colon - space string(“ : ”) 
		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};

	// a non - friend helper function that inserts into the 
	// os object the LVPair object referenced in the 2nd function parameter
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		V m_initialValueForSummation;
		size_t m_minFieldWidth;
	public:
		SummableLVPair()
			: m_initialValueForSummation{}
			, m_minFieldWidth{0u}
		{
		}

		SummableLVPair(const L& label, const V& v)
			: LVPair<L, V>(label, v)
		{
			if (m_minFieldWidth < label.size())
				m_minFieldWidth = label.size() + 1;
		}
		
		

		// returns the initial value for summations of LVPair objects
		const V& getInitialValue()
		{
			return m_initialValueForSummation;
		}

		// receives two unmodifiable references - one to a label (label) and another to a partially accumulated sum (sum) 
		// returns the sum of the value of the current object 
		// and the partially accumulated sum in a V object
		V sum(const L& label, const V& sum) const
		{
			return LVPair<L, V>::getValue() + sum;
		}

		// a query that inserts into the std::ostream object the label and value stored in the base class
		// Before calling the display() function on the base class, this query sets the std::ostream object to left - 
		// justified insertion and a field width equal to that stored for objects of this class
		void display(std::ostream& os) const
		{
		}
	};

	// Template specialization for LVPair<std::string, int>
	template<>
	class SummableLVPair<std::string, int> : public LVPair<std::string, int>
	{
	public:
		SummableLVPair(const std::string& label, const int& v)
			: LVPair(label, 0)
		{
		}
	};

	// Template specialization for LVPair<std::string, std::string>
	template<>
	class SummableLVPair<std::string, std::string> : public LVPair<std::string, std::string>
	{
	public:
		SummableLVPair(const std::string& label, const std::string& v)
			: LVPair(label, "")
		{
		}
	};
}


#endif // !_SICT_LVPAIR_H

