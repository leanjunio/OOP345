#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"

namespace sict
{
	MessagePack::MessagePack()
		: m_messages{ nullptr }
		, m_numElementsInPack{ 0 }
	{
	}
	MessagePack::MessagePack(const MessagePack& other)
	{
		*this = other;
	}
	MessagePack & MessagePack::operator=(const MessagePack& other)
	{
		if (this != &other)
		{
			delete[] m_messages;
			m_numElementsInPack = other.m_numElementsInPack;

			for (int i = 0; i < m_numElementsInPack; i++)
			{
				m_messages[i] = other.m_messages[i];
			}
		}
		return *this;
	}
	MessagePack::MessagePack(MessagePack&& other)
	{
		*this = std::move(other);
	}
	MessagePack& MessagePack::operator=(MessagePack&& other)
	{
		if (this != &other)
		{
			// delete[] m_messages;

			m_messages = other.m_messages;
			m_numElementsInPack = other.m_numElementsInPack;

			other.m_messages = { nullptr };
			other.m_numElementsInPack = { 0 };
		}
		return *this;
	}
	MessagePack::~MessagePack()
	{
		delete[] m_messages;
		m_messages = nullptr;
	}
	MessagePack::MessagePack(Message** pToArrayOfMessages, int numElementsInArrayPassed)
	{
		if (numElementsInArrayPassed > 0 && pToArrayOfMessages != nullptr)
		{
			m_numElementsInPack = { 0 };
			m_messages = new Message[numElementsInArrayPassed];

			for (int i = 0; i < numElementsInArrayPassed; ++i)
			{
				if (!(*pToArrayOfMessages[i]).empty())
				{
					m_messages[i] = *pToArrayOfMessages[i];
					m_numElementsInPack = i;595959
				
				}
				else
				{
					*pToArrayOfMessages[i] = Message();
				}
			}
		}
	}
	void MessagePack::display(std::ostream& os) const
	{
		for (int i = 0; i < m_numElementsInPack; i++)
		{
			m_messages[i].display(os);
		}
	}
	size_t MessagePack::size() const
	{
		return size_t(m_numElementsInPack);
	}
	std::ostream& operator<<(std::ostream& os, const MessagePack& m)
	{
		m.display(os);
		return os;
	}
}