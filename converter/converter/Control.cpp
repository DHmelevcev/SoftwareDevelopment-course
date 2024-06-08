#include "Control.h"

namespace NumberConverter
{
	Control::Control() : p1(10), p2(2), acc(32) {}

	bool Control::set_p1(int new_p1) {
		return new_p1 > 1 && new_p1 < 256 ? p1 = new_p1, true : false;
	}

	bool Control::set_p2(int new_p2) {
		return new_p2 > 1 && new_p2 < 256 ? p2 = new_p2, true : false;
	}

	std::string Control::do_cmnd(int command)
	{
		if (command <= -4 && command >= -6) {
			Number from(ed.num(), p1);
			Number to(from);

			if (ed.num() != "0") {
				//acc = static_cast<uint32_t>(round(from.acc() * log2(p1) / log2(p2) + 0.5));

				Converter_base_10::number_to_10(to, acc);
				Converter_10_base::number_to_base(to, p2, acc);

				switch (command)
				{
				case -4: // history record
					hist.add_record(from, to);
					st = converted;
					break;
				case -5: // covertion in place, no history record
					if (to.get().first.find('.') == std::string::npos)
						const_cast<bool&>(ed.is_float()) = false;
					else
						const_cast<bool&>(ed.is_float()) = true;

					const_cast<std::string&>(ed.num()) = to.get().first;
					break;
				case -6: // no history record
					break;
				}
			}

			return to.get().first;
		}

		if (p1 <= command) {
			return ed.num();
		}

		if (command >= -3 && command <= 255) {
			st = redacting;
			return ed.do_edit(command);
		}
		else {
			// Do nothing or ...
			//throw gcnew System::String("unknown control command " + command + "\n");
			return ed.num();
		}
	}
}