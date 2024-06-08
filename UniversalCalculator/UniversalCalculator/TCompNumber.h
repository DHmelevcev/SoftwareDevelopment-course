#pragma once
#include "INumber.h"

class TCompNumber : public INumber
{
public:
	inline static const double ε = 1e-15;

	inline static const char delimer = 'i';

public:
	TCompNumber();

	TCompNumber(const TCompNumber& other);

	TCompNumber(const std::string& string_value);

	TCompNumber& operator=(const INumber& other) override;

	bool operator==(const INumber& other) const override;

	bool is_zero() const override;

	return_ptr operator+(const INumber& other) const override;

	return_ptr operator-(const INumber& other) const override;

	return_ptr operator*(const INumber& other) const override;

	return_ptr operator/(const INumber& other) const override;

	return_ptr operator-() const override;

	TCompNumber& operator+=(const INumber& other) override;

	TCompNumber& operator-=(const INumber& other) override;

	TCompNumber& operator*=(const INumber& other) override;

	TCompNumber& operator/=(const INumber& other) override;

	TCompNumber& negate() override;

	TCompNumber& sqr() override;

	TCompNumber& inverse() override;

	std::string to_string() const override;

	bool is_correct() const override;

	double length() const;

protected:
	double _real;
	double _imag;
};
