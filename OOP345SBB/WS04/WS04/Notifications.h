// Name: Lean Junio
// Seneca Student ID: 019109123
// Seneca email: ljjunio@myseneca.ca	
// Date of completion: 10/1/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Notifications.h
#ifndef _W4_NOTIFICATIONS_H
#define _W4_NOTIFICATIONS_H

#include "Message.h"

namespace w4
{
	// Container class that holds separate messages
	//
	class Notifications
	{
		const int MAX = 10;
		Message* m_pMessages;
		int m_Count;
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



