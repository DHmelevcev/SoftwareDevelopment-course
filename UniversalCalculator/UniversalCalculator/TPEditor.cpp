#include "TPEditor.h"
#include "TException.h"

const std::string& TPEditor::value()
{
	return _value;
}

void TPEditor::set_value(const std::string& value)
{
	if (!value.size())
		return;

	std::string new_value = "0";

	bool sign = value[0] == TPEditor::sign;
	bool dot = false;

	if (value.size() - sign < 1)
		return;

	if (sign)
		new_value[0] = TPEditor::sign;

	for (size_t i = static_cast<size_t>(sign); i < value.size(); ++i) {
		if (value[i] == TPEditor::sign)
			return;

		if (value[i] == zero) {
			if (!is_zero(new_value))
				new_value.push_back(zero);
			continue;
		}

		if (value[i] == TPEditor::dot)
			if (!dot) {
				dot = true;
				if (i == 0 || i == 1 && sign)
					new_value.push_back(zero);
				new_value.push_back(TPEditor::dot);
				continue;
			}
			else
				return;

		if (zero <= value[i] && value[i] <= '9'
			|| 'A' <= value[i] && value[i] <= 'Z'
			) {
			if (!is_zero(new_value))
				new_value.push_back(value[i]);
			else
				new_value.back() = value[i];
			continue;
		}

		if ('a' <= value[i] && value[i] <= 'z') {
			if (!is_zero(new_value))
				new_value.push_back(value[i] - 'a' + 'A');
			else
				new_value.back() = value[i] - 'a' + 'A';
			continue;
		}
		else
			return;
	}

	_value = std::move(new_value);
	_dot = dot;
}

bool TPEditor::is_zero() const
{
	return !_dot && (
			_value[0] == zero ||
			_value[0] == sign && _value[1] == zero );
}

void TPEditor::add_sign()
{
	if (_value[0] == sign)
		_value.erase(0, 1);
	else
		_value = sign + _value;
}

void TPEditor::add_dot()
{
	if (!_dot) {
		_dot = true;
		_value.push_back(dot);
	}
}

void TPEditor::add_delimer()
{
	add_dot();
}

void TPEditor::add_digit(uint8_t n)
{
	if (is_zero())
		_value.back() = uint8_to_char(n);
	else
		_value.push_back(uint8_to_char(n));
}

void TPEditor::add_zero()
{
	if (!is_zero())
		_value.push_back(zero);
}

void TPEditor::BS()
{
	if (_value.back() == dot)
		_dot = false;
	_value.pop_back();
	if (_value.empty() || _value == std::string(1, sign))
		_value = zero;
}

void TPEditor::clear()
{
	_dot = false;
	_value.resize(1);
	_value[0] = zero;
}

void TPEditor::do_edit(int command)
{
	switch (command) {
	case Commands::addZero:
		add_zero();
		break;
	case Commands::addSign:
		add_sign();
		break;
	case Commands::addDot:
		add_dot();
		break;
	case Commands::addDelimer:
		add_dot();
		break;
	case Commands::doBS:
		BS();
		break;
	case Commands::doClear:
		clear();
		break;
	default:
		if (command >= 1 && command <= 35)
			add_digit(command);
		else
			throw TException("Unknown editor command: " + std::to_string(command));
	}
}

bool TPEditor::is_zero(std::string value)
{
	return	value.find(dot) == std::string::npos && (
			value[0] == zero ||
			value[0] == sign && value[1] == zero );
}
