// Notifications.h
// Manages access to a set of up to 10 instances of the Message type
#ifndef _W4_NOTIFICATIONS_H
#define _W4_NOTIFICATIONS_H

#include <vector>
#include "Message.h"

namespace w4
{
	class Notifications
	{
		std::vector<Message> m_Messages;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();

		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif // !_W4_NOTIFICATIONS_H



