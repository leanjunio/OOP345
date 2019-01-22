#ifndef _SICT_TIMEKEEPER_H
#define _SICT_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict
{
	class Timekeeper
	{
		static size_t counter;

		struct Record
		{
			const char* m_message;
			const char* m_units = "seconds";
			std::chrono::steady_clock::time_point mt_start;
			std::chrono::steady_clock::time_point mt_end;
			std::chrono::steady_clock::duration mt_duration;
		};

		Record records[10];
		
	public:	
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report(std::ostream&);
		~Timekeeper();
	};
}

#endif // !_SICT_TIMEKEEPER_H


