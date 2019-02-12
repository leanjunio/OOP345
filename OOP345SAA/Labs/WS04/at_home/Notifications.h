#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** p_arrAddresses;	// points to the pointer contaiing array of Message object
		int m_maxNumAddresses;
		int m_numCurrentlyStoredAddresses;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();

		Notifications(int);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, Notifications& n);
}

#endif // !SICT_NOTIFICATIONS_H


