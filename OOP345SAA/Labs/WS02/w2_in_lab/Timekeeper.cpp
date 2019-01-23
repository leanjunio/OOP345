#include <iostream>
#include <iomanip>
#include <chrono>
#include "Timekeeper.h"

namespace sict
{
	size_t Timekeeper::counter = 0;

	Timekeeper::Timekeeper()
		: mt_start{}
		, mt_end{}
	{
	}
	void Timekeeper::start()
	{
		mt_start = std::chrono::steady_clock::now();
	}
	void Timekeeper::stop()
	{
		mt_end = std::chrono::steady_clock::now();
	}
	void Timekeeper::recordEvent(const char *description)
	{
		auto start = mt_start;
		auto end = mt_end;

		if (counter < MAX_RECORDS)
		{
			records[counter].m_message = description;
			records[counter].mt_duration = end - start;
			counter++;
		}
	}
	std::ostream & Timekeeper::report(std::ostream &os)
	{
		os << "\nExecution Times:" << std::endl;

		for (size_t i = 0; i < counter; ++i)
			os << records[i].m_message << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(records[i].mt_duration).count() << " " << records[i].m_units << std::endl;
		return os;
	}
	Timekeeper::~Timekeeper()
	{
	}
}