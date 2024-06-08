#pragma once
#include <string>

namespace NumberConverter
{
	class Editor
	{
	private:
		std::string number = "0";
		bool dot = false;

		inline static const std::string zero = "0";
		inline static const std::string delimer = ".";
	public:
		inline const std::string& num()
		{
			return number;
		}

		inline const bool& is_float()
		{
			return dot;
		}

		// add digit to string
		void add_digit(uint8_t n);

		// add zero to string
		void add_zero();

		// add delimer to string
		void add_delim();

		// delete last charecter in string
		void BS();

		// delete last charecter in string
		void clear();

		// do commamd
		std::string do_edit(int command);
	};
}