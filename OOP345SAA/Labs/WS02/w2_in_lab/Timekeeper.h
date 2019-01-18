#ifndef _SICT_TIMEKEEPER_H
#define _SICT_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict
{
	class Timekeeper
	{
		// MAX and counter
		const size_t MAX = 10;
		static size_t counter;

		// Data members
		const char* m_message;
		const char* m_units;
		std::chrono::steady_clock::time_point mt_start;
		std::chrono::steady_clock::time_point mt_end;
		std::chrono::steady_clock::duration mt_duration;
	public:	
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report();
		~Timekeeper();
	};
}

#endif // !_SICT_TIMEKEEPER_H


