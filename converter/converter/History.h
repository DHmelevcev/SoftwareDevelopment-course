#pragma once
#include <vector>
#include "Number.h"

namespace NumberConverter
{
	struct Record
	{
		std::string from;
		std::string to;
		uint8_t p1;
		uint8_t p2;

		Record(std::pair<std::string, uint8_t>& from, std::pair<std::string, uint8_t>& to);
	};

	class History
	{
	private:
		std::vector<Record> list;

	public:
		Record get(size_t index) const;

		void add_record(const Number& from, const Number& to);

		void clear();

		size_t count() const;
	};
}