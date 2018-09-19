#include <iostream>
#include <vector>
#include "Notifications.h"
#include "Message.h"

namespace w4
{
	Notifications::Notifications()
	{
		m_Messages->clear();
	}

	Notifications::Notifications(const Notifications & other)
	{
		*this = other;
	}

	Notifications & Notifications::operator=(const Notifications & other)
	{
		if (this != &other)
		{
			size_t v_Size = other.m_Messages->size();

			for (size_t i = 0; i < v_Size; i++)
				this->m_Messages[i] = other.m_Messages[i];
		}

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
			size_t v_Size = other.m_Messages->size();

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
