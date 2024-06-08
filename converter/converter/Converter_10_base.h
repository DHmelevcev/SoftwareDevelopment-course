#pragma once
#include "Number.h"

namespace NumberConverter
{
	class Converter_10_base
	{
	private:
		// ������� ������ ����� � 10 �� � ������ ��
		static std::string int_to_base(uint64_t int_number_10, const uint8_t base);

		// ������� ������� ����� ����� � 10 �� � ������ ��
		static std::string float_to_base(double float_number_10, uint32_t& symbols_after_dot, const uint8_t base, const uint32_t accuracy);

	public:
		static unsigned char int_to_char(const uint8_t n);

		// ������� Number � 10 �� � ������ ��
		static void number_to_base(Number& number, const uint8_t base, const uint32_t accuracy = 7u);
	};
}