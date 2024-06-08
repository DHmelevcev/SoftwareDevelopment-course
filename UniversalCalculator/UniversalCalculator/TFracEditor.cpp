#include "TFracEditor.h"
#include "TException.h"

const std::string& TFracEditor::value()
{
	return _value;
}

void TFracEditor::set_value(const std::string& value)
{
	_value = value;
}

bool TFracEditor::is_zero() const
{
	return  _value[0] == zero ||
			_value[0] == sign && _value[1] == zero;
}

void TFracEditor::add_sign()
{
	if (_value[0] == sign)
		_value.erase(0, 1);
	else
		_value = sign + _value;
}

void TFracEditor::add_dot()
{
	add_delimer();
}

void TFracEditor::add_delimer()
{
	if (_delimer == -1) {
		_delimer = _value.length();
		_value.push_back(delimer);
	}
}

void TFracEditor::add_digit(uint8_t n)
{
	if (is_zero())
		_value.back() = uint8_to_char(n);
	else
		_value.push_back(uint8_to_char(n));
}

void TFracEditor::add_zero()
{
	if (!is_zero() && (_delimer != _value.length() - 1))
		_value.push_back(zero);
}

void TFracEditor::BS()
{
	if (_value.back() == delimer)
		_delimer = -1;
	_value.pop_back();
	if (_value.empty() || _value == std::string(1, sign))
		_value = zero;
}

void TFracEditor::clear()
{
	_delimer = -1;
	_value.resize(1);
	_value[0] = zero;
}

void TFracEditor::do_edit(int command)
{
	switch (command) {
	case Commands::addZero:
		add_zero();
		break;
	case Commands::addSign:
		add_sign();
		break;
	case Commands::addDot:
		add_delimer();
		break;
	case Commands::addDelimer:
		add_delimer();
		break;
	case Commands::doBS:
		BS();
		break;
	case Commands::doClear:
		clear();
		break;
	default:
		if (command >= 1 && command <= 9)
			add_digit(command);
		else
			throw TException("Unknown editor command: " + std::to_string(command));
	}
}

bool TFracEditor::is_zero(std::string value)
{
	return	value[0] == zero ||
			value[0] == sign && value[1] == zero;
}
