#ifndef SICT_MESSAGEPACK
#define SICT_MESSAGEPACK

#include "Message.h";

namespace sict
{
	class MessagePack
	{
	public:
		MessagePack();
		MessagePack(const Message*, );
		MessagePack(const MessagePack&);
		MessagePack& operator=(const MessagePack&);
		MessagePack(MessagePack&&);
		MessagePack& operator=(MessagePack&&);
		~MessagePack();
	};
}

#endif // !SICT_MESSAGEPACK


