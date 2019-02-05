#include <iostream>
#include <string>
#include "Message.h"

namespace sict
{
  Message::Message()
    : m_tweet{""}
    , m_sender{""}
    , m_FullTweet{""}
    , m_recepient{""}
    , m_directedToRecipient{true}
    , pos{0}
  {
  }


  /*
  
  jim Workshop 4 is cool
harry @jim working on workshop 4 now

chris
dave what the ^#$%!
john @harry I'm done

  
  */

  Message::Message(const std::string& str)
	  : m_FullTweet{str}
	  , m_directedToRecipient{m_FullTweet.find('@') != std::string::npos ? true : false}
	  , pos{0}
  {
	  size_t next_space = { m_FullTweet.find(' ') };
	  m_sender = m_FullTweet.substr(pos, next_space + 1);

	  if (m_sender.size() > 0)
	  {
		  if (m_directedToRecipient)
		  {
			  pos = next_space;
			  size_t at_pos = { m_FullTweet.find('@', pos + 1) };
			  next_space = { m_FullTweet.find(' ', pos + 1) };

			  m_recepient = {m_FullTweet.substr(at_pos, next_space - at_pos)};
			  // std::cout << "m_recepient: " << m_recepient << std::endl;
		  }
		  
		  pos = next_space;
		  m_tweet = m_FullTweet.substr(pos + 1, m_FullTweet.size());
		  // std::cout << "m_tweet: " << m_tweet << std::endl;
	  }

	  /*if (m_sender.size() > 0)
	  {
		  pos = next_space;
		  next_space = { m_FullTweet.find(' ', pos + 1) };

		  if (!m_directedToRecipient)
		  {
			  m_tweet = m_FullTweet.substr(pos + 1, m_FullTweet.size());
			  std::cout << "m_tweet: " << m_tweet << std::endl;
		  }
		  else
		  {
			  size_t at_pos = { m_FullTweet.find('@', pos + 1) };
			  next_space = { m_FullTweet.find(' ', pos + 1) };
			  m_recepient = { m_FullTweet.substr(at_pos, next_space) };
			  std::cout << "Recipient: " << m_recepient << std::endl;
		  }
	  }*/
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
    os << ">User  : " << m_sender << std::endl;
    os << " Reply : " << m_recepient << std::endl;
    os << " Tweet : " << m_tweet << std::endl;
  }
  
  Message::~Message()
  {
  }
}