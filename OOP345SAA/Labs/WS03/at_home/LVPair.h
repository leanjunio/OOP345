#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>

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

		// a query that inserts into os the label and value 
		// stored in the current object separated by 
		// a space - colon - space string(“ : ”) 
		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}

		// TODO: Create getters for the 
		const L& label() { return m_label; }
		const V& value() { return m_value; }
	};

	// a non - friend helper function that inserts into the 
	// os object the LVPair object referenced in the 2nd function parameter
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	// manage the addition and pretty displaying of individual labeled values
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		// holds the initial value for starting a summation (this depends on the type of the value in the label-value pair
		V m_initialValueForSummation = 0;

		// holds the minimum field width for pretty columnar output of label-value pairs
		// this is the minimum number of characters needed to display any of the labels in a set of labels
		size_t m_minFieldWidth;
	public:

		// A templated declaration that initializes the field width class variable to 0
		// leaves the object in a safe empty state
		SummableLVPair()
			: m_initialValueForSummation{}
			, m_minFieldWidth(0)
		{
		}

		// calls the base class 2-argument constructor and passes the values received to the base class
		// increases the stored field width if it is less than the return of characters required to display the label for all LVPair objects
		// This class assumes that the type of the first parameter has a member function named size(), which returns that value
		SummableLVPair(const L& label, const V& v)	
			: LVPair(label, v)
		{
			if (m_minFieldWidth < label.size())
				m_minFieldWidth = label.size() + 1;
		}

		// returns the initial value for summations of LVPair objects
		const V& getInitialValue()
		{
			return V{};
		}

		// receives two unmodifiable references - one to a label (label) and another to a partially 
		// accumulated sum (sum) – and returns the sum of the value of the current object 
		// and the partially accumulated sum in a V object
		V sum(const L& label, const V& sum) const
		{
			LVPair<L, V>::label();
			LVPair<L, V>::Value();
		}

		// a query that inserts into the std::ostream object the label and value stored in the base class
		// Before calling the display() function on the base class, this query sets the std::ostream object to left - 
		// justified insertion and a field width equal to that stored for objects of this class
		void display(std::ostream& os) const
		{
		}
	};

}


#endif // !_SICT_LVPAIR_H

