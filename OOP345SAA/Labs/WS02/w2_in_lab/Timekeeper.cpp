#include <iostream>
#include <chrono>
#include "Timekeeper.h"

namespace sict
{
	size_t Timekeeper::counter = 0;

	Timekeeper::Timekeeper()
	{
	}
	void Timekeeper::start()
	{
		records[counter].mt_start = std::chrono::steady_clock::now();
	}
	void Timekeeper::stop()
	{
		records[counter].mt_end = std::chrono::steady_clock::now();
	}
	void Timekeeper::recordEvent(const char *description)
	{
		auto start = records[counter].mt_start;
		auto end = records[counter].mt_end;

		records[counter].m_message = description;
		records[counter].mt_duration = end - start;
		
		counter++;
	}
	std::ostream & Timekeeper::report(std::ostream &os)
	{
		os << "\nExecution Times: " << std::endl;

		for (size_t i = 0; i < counter; ++i)
			os << records[i].m_message << " " << records[i].mt_duration.count() << " " << records[i].m_units << std::endl;
		return os;
	}
	Timekeeper::~Timekeeper()
	{
	}
}