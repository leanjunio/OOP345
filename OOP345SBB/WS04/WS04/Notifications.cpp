// Name: Lean Junio
// Seneca Student ID: 019109123
// Seneca email: ljjunio@myseneca.ca	
// Date of completion: 10/1/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <vector>
#include <algorithm>
#include "Notifications.h"
#include "Message.h"

namespace w4
{
	Notifications::Notifications()
		: m_pMessages(new Message[10]),
		  m_Count(0)
	{	
	}

	Notifications::Notifications(const Notifications& other)
	{
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& other)
		// Allow the current object to take the value of the parameter using the '=' operator
		// Called via: `Notifications::n1 = Notifications::n2;`
	{
		if (this != &other)
		{
			delete[] m_pMessages;			
			m_pMessages = new Message[other.m_pMessages->getCount()];

			for (int i = 0; i < other.m_pMessages->getCount(); ++i)
				m_pMessages[i] = other.m_pMessages[i];
		}

		return *this;
	}

	Notifications::Notifications(Notifications && other)
	{
		*this = std::move(other);
	}

	Notifications& Notifications::operator=(Notifications&& other)
	{
		if (this != &other)
		{
			delete[] m_pMessages;
			m_Count = other.m_Count;

			m_pMessages = new Message[m_Count];
			m_pMessages = other.m_pMessages;

			other.m_pMessages = nullptr;
			other.m_Count = 0;
		}

		return *this;
	}

	Notifications::~Notifications()
	{
		delete[] m_pMessages;
		m_pMessages = nullptr;
	}

	// Adds the passed msg to the set
	//
	void Notifications::operator+=(const Message & msg)
	{
		if (m_Count < MAX)
		{
			m_pMessages[m_Count] = msg;
			m_Count++;
		}
		else
			std::cout << "------- MESSAGES FULL ----------" << std::endl;
	}
	void Notifications::display(std::ostream & os) const
	{	
		for (int i = 0; i < m_Count; ++i)
			m_pMessages[i].display(os);
	}
}