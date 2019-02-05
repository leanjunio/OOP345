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

  Message::Message(const std::string& str)
    : m_FullTweet{str}
  {
    size_t next_space = {m_FullTweet.find(' ')};  // calculates the next space after the word
    m_sender = m_FullTweet.substr(pos, next_space);         // gets the 'sender' substring

    std::cout << "m_sender: " << m_sender << std::endl;

    if (m_sender.size() > 0)
    {
      pos = next_space;
      next_space = {m_FullTweet.find(' ')};
      m_tweet = m_FullTweet.substr(pos, next_space);
      std::cout << "m_tweet: " << m_tweet << std::endl;
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
    os << ">User  : " << m_sender << std::endl;
    os << " Reply : " << m_recepient << std::endl;
    os << " Tweet : " << m_tweet << std::endl;
  }
  
  Message::~Message()
  {
  }
}