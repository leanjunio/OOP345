#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <string>

namespace sict
{
  class Message
  {
  private:
    std::string m_tweet;
    std::string m_sender;
    std::string m_FullTweet;
    std::string m_recepient;
    bool m_directedToRecipient;
    size_t pos;
	public:
    Message();
    Message(const std::string& str);
    bool empty() const;
    void display(std::ostream& os) const;
    ~Message();
  };
} // sict


#endif // !SICT_MESSAGE_H