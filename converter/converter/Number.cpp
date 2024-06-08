#include "Number.h"

namespace NumberConverter
{
	Number::Number(const std::string& str, const uint8_t base)
	{
		set(str, base);
	}

	uint32_t Number::acc()
	{
		return static_cast<uint32_t>(value.length() - symbols_after_dot);
	}

	std::pair<std::string, uint8_t> Number::get() const
	{
		std::string result = std::string(value.begin(), value.begin() + value.length() - symbols_after_dot);
		if (symbols_after_dot) {
			result.push_back('.');
			result.insert(result.end(), value.end() - symbols_after_dot, value.end());
		}
		return std::make_pair(sign ? '-' + result : result, base);
	}

	void Number::set(std::string str, const uint8_t base)
	{
		this->base = base;
		value.clear();

		int count = 0;
		bool after_dot = false;
		while (!str.empty())
		{
			unsigned char c = str[0];
			str.erase(str.begin());

			if (c == '-')
				sign = true;
			if (c == ',' || c == '.')
				after_dot = true;
			if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z') {
				value.push_back(c);
				if (after_dot)
					count++;
			}
		}
		symbols_after_dot = count;
		if (value.empty())
			value = '0';
	}
}