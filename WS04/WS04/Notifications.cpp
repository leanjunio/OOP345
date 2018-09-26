#include <iostream>
#include <vector>
#include <algorithm>
#include "Notifications.h"
#include "Message.h"

namespace w4
{
	Notifications::Notifications()
	{	
	}

	Notifications::Notifications(const Notifications & other)
		// Allow the current object to take the value of the parameter passed to the constructor
		// This constructor can be called via: `Notifications n1 = Notifications::previousN1;`
	{
		*this = other;
	}

	Notifications & Notifications::operator=(const Notifications & other)
		// Allow the current object to take the value of the parameter using the '=' operator
		// Called via: `Notifications::n1 = Notifications::n2;`
	{
		if (this != &other)
			this->m_Messages = other.m_Messages;

		return *this;
	}

	Notifications::Notifications(Notifications && other)
	{
		*this = std::move(other);
	}

	Notifications & Notifications::operator=(Notifications && other)
	{
		if (this != &other)
		{
			this->m_Messages = other.m_Messages;
			(other.m_Messages).clear();
		}

		return *this;
	}

	Notifications::~Notifications()
	{
	}
	void Notifications::operator+=(const Message & msg)
		// Pushes the passed msg parameter into the vector m_Messages
	{
		m_Messages.push_back(msg);
	}
	void Notifications::display(std::ostream & os) const
	{
		std::cout << "m_Messages count: " << m_Messages.size() << std::endl;
	}
}