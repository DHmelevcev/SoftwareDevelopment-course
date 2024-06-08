#pragma once
#include "INumber.h"

class TPNumber : public INumber
{
public:
	inline static const double ε = 1e-15;

public:
	TPNumber();

	TPNumber(const TPNumber& other);

	TPNumber(const std::string& string_value, uint8_t base = 10);

	TPNumber& operator=(const INumber& other) override;

	bool operator==(const INumber& other) const override;

	bool is_zero() const override;

	return_ptr operator+(const INumber& other) const override;

	return_ptr operator-(const INumber& other) const override;

	return_ptr operator*(const INumber& other) const override;

	return_ptr operator/(const INumber& other) const override;

	return_ptr operator-() const override;

	TPNumber& operator+=(const INumber& other) override;

	TPNumber& operator-=(const INumber& other) override;

	TPNumber& operator*=(const INumber& other) override;

	TPNumber& operator/=(const INumber& other) override;

	TPNumber& negate() override;

	TPNumber& sqr() override;

	TPNumber& inverse() override;

	std::string to_string() const override;

	bool is_correct() const override;

	uint8_t& base();

	const uint8_t& base() const;

protected:
	double _value;

	uint8_t _base;

	uint8_t _acc;
};
