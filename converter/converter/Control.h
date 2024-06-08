#pragma once
#include "Editor.h"
#include "History.h"
#include "Converter_10_base.h"
#include "Converter_base_10.h"

namespace NumberConverter
{
	class Control
	{
	public:
		Control();

		enum State {
			redacting,
			converted,
		};

	private:
		Editor ed;
		History hist;

		uint8_t p1;
		uint8_t p2;

		uint32_t acc;

		State st = redacting;

	public:
		inline const State& state()
		{
			return st;
		}

		inline History& history()
		{
			return hist;
		}

		inline const uint8_t& get_p1() {
			return p1;
		}
		inline const uint8_t& get_p2() {
			return p2;
		}

		bool set_p1(int new_p1);
		bool set_p2(int new_p2);

		std::string do_cmnd(int command);
	};
}