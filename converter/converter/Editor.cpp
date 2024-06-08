#include "Editor.h"
#include "Converter_10_base.h"

namespace NumberConverter
{
	void Editor::add_digit(uint8_t n)
	{
		if (!dot && number.front() == '0')
			number.clear();

		number.insert(number.end(), Converter_10_base::int_to_char(n));
	}

	void Editor::add_zero()
	{
		if (dot || number.front() != '0')
			number.append(zero);
	}

	void Editor::add_delim()
	{
		if (!dot) {
			dot = true;
			number.append(delimer);
		}
	}

	void Editor::BS()
	{
		if (number.back() == '.')
			dot = false;
		number.pop_back();

		if (number.empty())
			number.append(zero);
	}

	void Editor::clear()
	{
		dot = false;
		number.clear();
		number.append(zero);
	}

	std::string Editor::do_edit(int command)
	{
		switch (command) {
		case 0:
			add_zero();
			break;
		case -1:
			add_delim();
			break;
		case -2:
			BS();
			break;
		case -3:
			clear();
			break;
		default:
			if (command >= 1 && command <= 255)
				add_digit(command);
			else
				throw gcnew System::String("unknown editor command " + command + "\n");
		}
		return number;
	}
}