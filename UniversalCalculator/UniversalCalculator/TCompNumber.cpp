#include "TCompNumber.h"
#include "TException.h"

TCompNumber::TCompNumber() :
	_real(0),
	_imag(0)
{}

TCompNumber::TCompNumber
(
	const TCompNumber& other
) :
	_real(other._real),
	_imag(other._imag)
{}

TCompNumber::TCompNumber
(
	const std::string& string_value
) :
	_real(0),
	_imag(0)
{
	if (size_t i = string_value.find(delimer); i != std::string::npos) {
		char* end_ptr;

		_real = strtod(&string_value.front(), &end_ptr);

		if (end_ptr - &string_value.front() != i)
			throw TException("Wrong TCompNumber format");

		_imag = strtod(end_ptr + 1, &end_ptr);

		if (end_ptr != &string_value.back() + 1)
			throw TException("Wrong TCompNumber format");
	}
	else {
		char* end_ptr;
		_real = strtod(&string_value.front(), &end_ptr);

		if (end_ptr != &string_value.back() + 1)
			throw TException("Wrong TCompNumber format");
	}
}

TCompNumber& TCompNumber::operator=
(
	const INumber& other
)
{
	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedCompNumber) {
		memcpy(this, castedCompNumber, sizeof(TCompNumber));
		return *this;
	}

	throw TException("Wrong cast to TCompNumber");
}

bool TCompNumber::operator==
(
	const INumber& other
	)
	const
{
	const TCompNumber* castedPNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedPNumber)
		return (abs(_real - castedPNumber->_real) < ε &&
				abs(_imag - castedPNumber->_imag) < ε);

	throw TException("Wrong cast to TCompNumber");
}

bool TCompNumber::is_zero() const
{
	return (abs(_real) < ε &&
			abs(_imag) < ε);
}

TCompNumber::return_ptr TCompNumber::operator+(const INumber& other) const
{
	std::unique_ptr<TCompNumber> result = std::make_unique<TCompNumber>(*this);
	*result += other;

	return result;
}

TCompNumber::return_ptr TCompNumber::operator-(const INumber& other) const
{
	std::unique_ptr<TCompNumber> result = std::make_unique<TCompNumber>(*this);
	*result -= other;

	return result;
}

TCompNumber::return_ptr TCompNumber::operator*(const INumber& other) const
{
	std::unique_ptr<TCompNumber> result = std::make_unique<TCompNumber>(*this);
	*result *= other;

	return result;
}

TCompNumber::return_ptr TCompNumber::operator/(const INumber& other) const
{
	std::unique_ptr<TCompNumber> result = std::make_unique<TCompNumber>(*this);
	*result /= other;

	return result;
}

TCompNumber::return_ptr TCompNumber::operator-() const
{
	std::unique_ptr<TCompNumber> result = std::make_unique<TCompNumber>(*this);
	result->negate();

	return result;
}

TCompNumber& TCompNumber::operator+=(const INumber& other)
{
	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedCompNumber) {
		_real += castedCompNumber->_real;
		_imag += castedCompNumber->_imag;

		return *this;
	}

	throw TException("Wrong cast to TCompNumber");
}

TCompNumber& TCompNumber::operator-=(const INumber& other)
{
	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedCompNumber) {
		_real -= castedCompNumber->_real;
		_imag -= castedCompNumber->_imag;

		return *this;
	}

	throw TException("Wrong cast to TCompNumber");
}

TCompNumber& TCompNumber::operator*=(const INumber& other)
{
	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedCompNumber) {
		double real =
			_real * castedCompNumber->_real - _imag * castedCompNumber->_imag;

		double imag =
			_real * castedCompNumber->_imag + castedCompNumber->_real * _imag;

		_real = real;
		_imag = imag;

		return *this;
	}

	throw TException("Wrong cast to TCompNumber");
}

TCompNumber& TCompNumber::operator/=(const INumber& other)
{
	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&other);
	if (castedCompNumber) {
		double real =
			(	_real * castedCompNumber->_real + _imag * castedCompNumber->_imag) /
			(	castedCompNumber->_real * castedCompNumber->_real +
				castedCompNumber->_imag * castedCompNumber->_imag	);

		double imag =
			(	castedCompNumber->_real * _imag - _real * castedCompNumber->_imag) /
			(	castedCompNumber->_real * castedCompNumber->_real +
				castedCompNumber->_imag * castedCompNumber->_imag);

		_real = real;
		_imag = imag;

		return *this;
	}

	throw TException("Wrong cast to TCompNumber");
}

TCompNumber& TCompNumber::negate()
{
	_real *= -1;
	_imag *= -1;

	return *this;
}

TCompNumber& TCompNumber::sqr()
{
	double real = _real * _real - _imag * _imag;
	double imag = 2. * _real * _imag;

	_real = real;
	_imag = imag;

	return *this;
}

TCompNumber& TCompNumber::inverse()
{
	double real = _real /
		(_real * _real + _imag * _imag);

	double imag = -_imag /
		(_real * _real + _imag * _imag);

	_real = real;
	_imag = imag;

	return *this;
}

std::string TCompNumber::to_string() const
{
	size_t i;

	std::string str1 = std::to_string(_real);
	i = str1.find_last_not_of('0');
	if (str1[i] == '.')
		++i;
	str1.erase(i + 1);

	std::string str2 = std::to_string(_imag);
	i = str2.find_last_not_of('0');
	if (str2[i] == '.')
		++i;
	str2.erase(i + 1);

	return str1 + delimer + str2;
}

bool TCompNumber::is_correct() const
{
	if (std::_Is_nan(_real) ||
		std::_Is_inf(_imag) ||
		std::_Is_nan(_real) ||
		std::_Is_inf(_imag)
	)
		return false;

	return true;
}

double TCompNumber::length() const
{
	return sqrt(_real * _real + _imag * _imag);
}
