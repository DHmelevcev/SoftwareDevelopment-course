#include "Converter_base_10.h"
#include <iomanip>
#include <sstream>

namespace NumberConverter
{
	uint8_t Converter_base_10::char_to_int(const unsigned char c)
	{
		if ('0' <= c && c <= '9')
			return c - '0';
		return c - 'A' + 10;
	}

	void Converter_base_10::number_to_10(Number& number, const uint32_t accuracy)
	{
		if (number.base == 10u)
			return;

		double number_10 = 0;
		for (uint32_t i = (uint32_t)number.value.length(); i != 0; i--)
		{
			int32_t a = static_cast<uint32_t>(number.value.length() - number.symbols_after_dot - i);
			uint8_t num = char_to_int(number.value[i - 1]);

			number_10 += num * pow(number.base, a);
		}

		number.base = 10u;
		number.symbols_after_dot = accuracy;

		std::stringstream stream;
		stream << std::fixed << std::setprecision(accuracy) << number_10;
		number.value = stream.str();

		// возвращает индекс первого не нулего справа
		auto last_not_zero = number.value.find_last_not_of('0');

		if (number.value[last_not_zero] == '.') {
			number.symbols_after_dot = 0;
			number.value.erase(last_not_zero);
		}
		else {
			number.symbols_after_dot -= static_cast<uint32_t>(number.value.length() - last_not_zero - 1);
			number.value.erase(last_not_zero + 1);
			number.value.erase(number.value.find('.'), 1);
		}
	}
}