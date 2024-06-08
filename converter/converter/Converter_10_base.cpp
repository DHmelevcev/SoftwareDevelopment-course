#include "Converter_10_base.h"

namespace NumberConverter
{
	unsigned char Converter_10_base::int_to_char(const uint8_t n)
	{
		return n > 9 ? n + 'A' - 10 : n + '0';
	}

	std::string Converter_10_base::int_to_base(uint64_t int_number_10, const uint8_t base)
	{
		std::string int_result;

		if (!int_number_10)
			int_result = '0';
		while (int_number_10)
		{
			int_result.insert(int_result.begin(), int_to_char(int_number_10 % base));
			int_number_10 /= base;
		}

		return int_result;
	}

	std::string Converter_10_base::float_to_base(double float_number_10, uint32_t& symbols_after_dot, const uint8_t base, const uint32_t accuracy)
	{
		std::string float_result;

		while (symbols_after_dot < accuracy && float_number_10)
		{
			float_number_10 *= base;
			float_result.push_back(int_to_char(static_cast<uint8_t>(float_number_10)));
			float_number_10 -= static_cast<uint8_t>(float_number_10);
			symbols_after_dot++;
		}

		if (!float_result.empty()) {
			// возвращает индекс первого не нулего справа или -1
			auto last_not_zero = float_result.find_last_not_of('0');
			if (last_not_zero == std::string::npos) {
				symbols_after_dot = 0;
				float_result.clear();
			}
			else {
				symbols_after_dot -= static_cast<uint32_t>(float_result.length() - last_not_zero - 1);
				float_result.erase(last_not_zero + 1);
			}
		}

		return float_result;
	}

	void Converter_10_base::number_to_base(Number& number, const uint8_t base, const uint32_t accuracy)
	{
		if (number.base != 10u)
			throw gcnew System::String("trying to convert Number with base" + int_to_char(number.base) + " from base10 to another base\n");

		if (number.base == base)
			return;

		/* TODO: shouldn't use double || uint64_t
		, but cannot define % and *= for std::string yet*/
		//uint32_t symbols_before_dot = number.value.length() - number.symbols_after_dot - 1;

		double number_10 = std::stod(number.value);
		number_10 /= pow(10, number.symbols_after_dot);

		number.value.clear();
		number.base = base;

		uint64_t int_number_10 = static_cast<uint64_t>(number_10);
		std::string int_result = int_to_base(int_number_10, base);
		number.value += int_result;

		double float_number_10 = number_10 - int_number_10;
		uint32_t symbols_after_dot = 0;
		std::string float_result = float_to_base(float_number_10, symbols_after_dot, base, accuracy - static_cast<uint16_t>(int_result.length()));
		number.symbols_after_dot = symbols_after_dot;
		number.value += float_result;
	}
}