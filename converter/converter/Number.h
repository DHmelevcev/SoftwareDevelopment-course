#pragma once
#include <string>

namespace NumberConverter
{
	class Number
	{
	private:
		std::string value;

		uint32_t symbols_after_dot = 0;
		uint8_t base = 10u;
		bool sign = false;

		friend class Converter_10_base;
		friend class Converter_base_10;

	public:
		Number(const std::string& str, const uint8_t base = 10u);

		uint32_t acc();

		std::pair<std::string, uint8_t> get() const;

		// парсер для строк
		void set(std::string str, const uint8_t base = 10u);
	};
}