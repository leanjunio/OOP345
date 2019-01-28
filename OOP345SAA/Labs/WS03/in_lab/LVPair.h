#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>

namespace sict
{
	template <typename L, typename V>
	class LVPair
	{
	public:
		// leaves the object in a safe empty state
		LVPair()
		{

		}

		// an overloaded constructor that copies the values received 
		// in its parameters into the instance variables
		LVPair(const L& label, const V& value)
		{

		}

		// a query that inserts into os the label and value 
		// stored in the current object separated by 
		// a space - colon - space string(“ : ”) 
		void display(std::ostream& os) const
		{

		}

		// a non - friend helper function that inserts into the 
		// os object the LVPair object referenced in the 2nd function parameter
		std::ostream& operator<<(std::ostream& os, const LVPair& pair)
		{

		}
	};
}


#endif // !_SICT_LVPAIR_H

