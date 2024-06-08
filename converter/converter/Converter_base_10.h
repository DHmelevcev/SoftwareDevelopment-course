#pragma once
#include "Number.h"

namespace NumberConverter
{
	class Converter_base_10
	{
	public:
		static uint8_t char_to_int(const unsigned char c);

		// ������� Number � 10 ��
		static void number_to_10(Number& number, const uint32_t accuracy = 7u);
	};
}