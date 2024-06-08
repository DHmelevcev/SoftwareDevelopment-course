#include "TPNumber.h"
#include "TException.h"

TPNumber::TPNumber() :
	_value(0.),
	_base(10),
	_acc(15)
{}

TPNumber::TPNumber
(
	const TPNumber & other
) :
	_value(other._value),
	_base(other._base),
	_acc(other._acc)
{}

TPNumber::TPNumber
(
	const std::string & string_value,
	uint8_t base
) :
	_value(strtod_base(string_value, base)),
	_base(base),
	_acc(15)
{}

TPNumber& TPNumber::operator=
(
	const INumber & other
)
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber) {
		memcpy(this, castedPNumber, sizeof(TPNumber));
		return *this;
	}

	throw TException("Wrong cast to TPNumber");
}

bool TPNumber::operator==
(
	const INumber& other
)
const
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber)
		return abs(_value - castedPNumber->_value) < ε;

	throw TException("Wrong cast to TPNumber");
}

bool TPNumber::is_zero() const
{
	return abs(_value) < ε;
}

TPNumber::return_ptr TPNumber::operator+(const INumber& other) const
{
	std::unique_ptr<TPNumber> result = std::make_unique<TPNumber>(*this);
	*result += other;

	return result;
}

TPNumber::return_ptr TPNumber::operator-(const INumber& other) const
{
	std::unique_ptr<TPNumber> result = std::make_unique<TPNumber>(*this);
	*result -= other;

	return result;
}

TPNumber::return_ptr TPNumber::operator*(const INumber& other) const
{
	std::unique_ptr<TPNumber> result = std::make_unique<TPNumber>(*this);
	*result *= other;

	return result;
}

TPNumber::return_ptr TPNumber::operator/(const INumber& other) const
{
	std::unique_ptr<TPNumber> result = std::make_unique<TPNumber>(*this);
	*result /= other;

	return result;
}

TPNumber::return_ptr TPNumber::operator-() const
{
	std::unique_ptr<TPNumber> result = std::make_unique<TPNumber>(*this);
	result->negate();

	return result;
}

TPNumber& TPNumber::operator+=(const INumber& other)
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber) {
		_value += castedPNumber->_value;
		return *this;
	}

	throw TException("Wrong cast to TPNumber");
}

TPNumber& TPNumber::operator-=(const INumber& other)
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber) {
		_value -= castedPNumber->_value;
		return *this;
	}

	throw TException("Wrong cast to TPNumber");
}

TPNumber& TPNumber::operator*=(const INumber& other)
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber) {
		_value *= castedPNumber->_value;
		return *this;
	}

	throw TException("Wrong cast to TPNumber");
}

TPNumber& TPNumber::operator/=(const INumber& other)
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&other);
	if (castedPNumber) {
		_value /= castedPNumber->_value;
		return *this;
	}

	throw TException("Wrong cast to TPNumber");
}

TPNumber& TPNumber::negate()
{
	_value *= -1;
	return *this;
}

TPNumber& TPNumber::sqr()
{
	_value *= _value;
	return *this;
}

TPNumber& TPNumber::inverse()
{
	_value = 1. / _value;
	return *this;
}

std::string TPNumber::to_string() const
{
	return dtostr_base(_value, _base, _acc);
}


bool TPNumber::is_correct() const
{
	if (std::_Is_nan(_value) ||
		std::_Is_inf(_value)
		)
		return false;

	return true;
}

uint8_t& TPNumber::base()
{
	return _base;
}

const uint8_t& TPNumber::base() const
{
	return _base;
}
