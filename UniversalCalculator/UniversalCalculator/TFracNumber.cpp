#include "TFracNumber.h"
#include "TException.h"

TFracNumber::TFracNumber() :
	_num(0),
	_den(1)
{}

TFracNumber::TFracNumber
(
	const TFracNumber& other
) :
	_num(other._num),
	_den(other._den)
{}

TFracNumber::TFracNumber
(
	const std::string& string_value
) :
	_num(0),
	_den(1)
{
	if (size_t i = string_value.find(delimer); i != std::string::npos) {
		char* end_ptr;
		_num = strtoll(&string_value.front(), &end_ptr, 10);

		if (end_ptr - &string_value.front() != i)
			throw TException("Wrong TFracNumber format");

		_den = strtoll(end_ptr + 1, &end_ptr, 10);

		if (end_ptr != &string_value.back() + 1)
			throw TException("Wrong TFracNumber format");
	}
	else {
		char* end_ptr;
		_num = strtoll(&string_value.front(), &end_ptr, 10);

		if (end_ptr != &string_value.back() + 1)
			throw TException("Wrong TFracNumber format");
	}

	reduce();
}

TFracNumber& TFracNumber::operator=
(
	const INumber& other
	)
{
	const TFracNumber* castedFracNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedFracNumber) {
		memcpy(this, castedFracNumber, sizeof(TFracNumber));
		return *this;
	}

	throw TException("Wrong cast to TFracNumber");
}

bool TFracNumber::operator==
(
	const INumber& other
	)
	const
{
	const TFracNumber* castedPNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedPNumber)
		return ( _num == castedPNumber->_num &&
				 _den == castedPNumber->_den );

	throw TException("Wrong cast to TFracNumber");
}

bool TFracNumber::is_zero() const
{
	return _num == 0;
}

TFracNumber::return_ptr TFracNumber::operator+(const INumber& other) const
{
	std::unique_ptr<TFracNumber> result = std::make_unique<TFracNumber>(*this);
	*result += other;

	return result;
}

TFracNumber::return_ptr TFracNumber::operator-(const INumber& other) const
{
	std::unique_ptr<TFracNumber> result = std::make_unique<TFracNumber>(*this);
	*result -= other;

	return result;
}

TFracNumber::return_ptr TFracNumber::operator*(const INumber& other) const
{
	std::unique_ptr<TFracNumber> result = std::make_unique<TFracNumber>(*this);
	*result *= other;

	return result;
}

TFracNumber::return_ptr TFracNumber::operator/(const INumber& other) const
{
	std::unique_ptr<TFracNumber> result = std::make_unique<TFracNumber>(*this);
	*result /= other;

	return result;
}

TFracNumber::return_ptr TFracNumber::operator-() const
{
	std::unique_ptr<TFracNumber> result = std::make_unique<TFracNumber>(*this);
	result->negate();

	return result;
}

TFracNumber& TFracNumber::operator+=(const INumber& other)
{
	const TFracNumber* castedFracNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedFracNumber) {
		_num = _num * castedFracNumber->_den + castedFracNumber->_num * _den;
		_den *= castedFracNumber->_den;
		reduce();

		return *this;
	}

	throw TException("Wrong cast to TFracNumber");
}

TFracNumber& TFracNumber::operator-=(const INumber& other)
{
	const TFracNumber* castedFracNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedFracNumber) {
		_num = _num * castedFracNumber->_den - castedFracNumber->_num * _den;
		_den *= castedFracNumber->_den;
		reduce();

		return *this;
	}

	throw TException("Wrong cast to TFracNumber");
}

TFracNumber& TFracNumber::operator*=(const INumber& other)
{
	const TFracNumber* castedFracNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedFracNumber) {
		_num *= castedFracNumber->_num;
		_den *= castedFracNumber->_den;
		reduce();

		return *this;
	}

	throw TException("Wrong cast to TFracNumber");
}

TFracNumber& TFracNumber::operator/=(const INumber& other)
{
	const TFracNumber* castedFracNumber = dynamic_cast<const TFracNumber*>(&other);
	if (castedFracNumber) {
		_num *= castedFracNumber->_den;
		_den *= castedFracNumber->_num;
		reduce();

		return *this;
	}

	throw TException("Wrong cast to TFracNumber");
}

TFracNumber& TFracNumber::negate()
{
	_num *= -1;

	return *this;
}

TFracNumber& TFracNumber::sqr()
{
	_num *= _num;
	_den *= _den;

	return *this;
}

TFracNumber& TFracNumber::inverse()
{
	std::swap(_num, _den);

	return *this;
}

std::string TFracNumber::to_string() const
{
	return std::to_string(_num) + delimer + std::to_string(_den);
}

bool TFracNumber::is_correct() const
{
	if (_den == 0)
		return false;

	return true;
}

void TFracNumber::reduce()
{
	int64_t gcd = GCD(abs(_num), abs(_den));

	_num /= gcd;
	_den /= gcd;

	if (_den < 0) {
		_num *= -1;
		_den *= -1;
	}
}
