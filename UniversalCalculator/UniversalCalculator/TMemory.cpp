#include "TMemory.h"
#include "INumber.h"

TMemory::TMemory
(
	INumber* ptr
) :
	_value(*ptr),
	_state(State::_Off)
{}

TMemory::~TMemory()
{
	delete &_value;
}

void TMemory::save
(
	const INumber& value
)
{
	_value = value;
	_state = State::_On;
}

const INumber& TMemory::read() const
{
	return _value;
}

void TMemory::add
(
	const INumber& value
)
{
	if (_state == State::_Off)
		_value = value;
	else
		_value += value;

	_state = State::_On;
}

void TMemory::clear()
{
	_state = State::_Off;
}

typename const TMemory::State& TMemory::get_state() const
{
	return _state;
}
