#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>

namespace sict
{
	/*
	
	defines a class template for a label-value pair (for example, a product label stored in an std::string object and a quantity stored in an int object)
	The template parameters identify the types of the label and value objects that constitute an LVPair object:

	a) L - the type of the label
	b) V - the type of the value
	
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
		void display(std::ostream& os) const
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

}


#endif // !_SICT_LVPAIR_H

