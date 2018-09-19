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
			int v_Size = other.m_Messages->size();

			for (size_t i = 0; i < v_Size; i++)
				this->m_Messages[i] = other.m_Messages[i];

			other.m_Messages->clear();
		}

		return *this;
	}

	Notifications::~Notifications()
	{
		std::cout << "Destructor called" << std::endl;
	}
	void Notifications::operator+=(const Message & msg)
	{
		this->m_Messages->push_back(msg);
	}
	void Notifications::display(std::ostream & os) const
	{
		/*for (size_t i = 0; i < m_Messages->size(); i++)
		{
			m_Messages[i].display(os);
		}*/
	}
}
