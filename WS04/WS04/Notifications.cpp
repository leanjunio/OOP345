#include "Notifications.h"

namespace w4
{
	Notifications::Notifications()
	{
		m_Messages->clear();
	}

	Notifications::Notifications(const Notifications & other)
	{
		m_Messages = other.m_Messages;
	}

	Notifications & Notifications::operator=(Notifications &)
	{
		// TODO: insert return statement here
	}

	Notifications::Notifications(Notifications &&)
	{
	}

	Notifications & Notifications::operator=(Notifications &&)
	{
		// TODO: insert return statement here
	}

	Notifications::~Notifications()
	{
	}
	void Notifications::operator+=(const Message & msg)
	{
	}
	void Notifications::display(std::ostream & os) const
	{
	}
}
