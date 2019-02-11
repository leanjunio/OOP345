#include <iostream>
#include <string>
#include "Message.h"

namespace sict
{
	Message::Message()
		: m_tweet{ "" }
		, m_sender{ "" }
		, m_FullTweet{ "" }
		, m_recepient{ "" }
		, m_directedToRecipient{ true }
		, pos{ 0 }
	{
	}
	Message::Message(const std::string& str)
		: m_FullTweet{ str }
		, m_directedToRecipient{ m_FullTweet.find('@') != std::string::npos ? true : false }
		, pos{ 0 }
	{
		size_t next_space = { m_FullTweet.find(' ') };
		m_sender = { m_FullTweet.substr(pos, next_space) };

		if (m_sender.size() > 0 && m_sender.size() != m_FullTweet.size())
		{
			if (m_directedToRecipient)
			{
				pos = next_space;
				size_t at_pos = { m_FullTweet.find('@', pos + 1) };
				next_space = { m_FullTweet.find(' ', pos + 1) };

				m_recepient = { m_FullTweet.substr(at_pos + 1, next_space - at_pos) };
			}

			pos = { next_space };
			m_tweet = m_FullTweet.substr(pos + 1, m_FullTweet.size());
		}
		else
		{
			*this = Message();
		}
	}
	  bool Message::empty() const
	  {
		if (m_tweet.size() < 1)
		  return true;
		else
		  return false;
	  }

	  void Message::display(std::ostream& os) const
	  {
		  if (m_FullTweet.size())
		  {
			  os << ">User  : " << m_sender << std::endl;
			  if (m_recepient.size() > 0)
				  os << " Reply : " << m_recepient << std::endl;
			  os << " Tweet : " << m_tweet << std::endl;
		  }
	  }
  
	  Message::~Message()
	  {
	  }
}