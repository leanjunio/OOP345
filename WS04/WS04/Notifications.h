#ifndef _W4_NOTIFICATIONS_H
#define _W4_NOTIFICATIONS_H

#include <vector>
#include "Message.h"

namespace w4
{
	const int MAX_OBJECTS = 10;

	class Notifications
	{
		std::vector<Message> m_Messages[MAX_OBJECTS];
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



