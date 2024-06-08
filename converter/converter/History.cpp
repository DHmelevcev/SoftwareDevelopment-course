#include "History.h"

namespace NumberConverter
{
	Record::Record(std::pair<std::string, uint8_t>& from, std::pair<std::string, uint8_t>& to)
		: from(from.first), to(to.first), p1(from.second), p2(to.second) {}

	Record History::get(size_t index) const
	{
		return list[index];
	}

	void History::add_record(const Number& from, const Number& to)
	{
		list.emplace_back(Record{ from.get(), to.get() });
	}

	void History::clear()
	{
		list.clear();
	}

	size_t History::count() const
	{
		return list.size();
	}
}