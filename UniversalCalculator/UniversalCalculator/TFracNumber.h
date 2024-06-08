#pragma once
#include "INumber.h"

class TFracNumber : public INumber
{
public:
	inline static const char delimer = '|';

public:
	TFracNumber();

	TFracNumber(const TFracNumber& other);

	TFracNumber(const std::string& string_value);

	TFracNumber& operator=(const INumber& other) override;

	bool operator==(const INumber& other) const override;

	bool is_zero() const override;

	return_ptr operator+(const INumber& other) const override;

	return_ptr operator-(const INumber& other) const override;

	return_ptr operator*(const INumber& other) const override;

	return_ptr operator/(const INumber& other) const override;

	return_ptr operator-() const override;

	TFracNumber& operator+=(const INumber& other) override;

	TFracNumber& operator-=(const INumber& other) override;

	TFracNumber& operator*=(const INumber& other) override;

	TFracNumber& operator/=(const INumber& other) override;

	TFracNumber& negate() override;

	TFracNumber& sqr() override;

	TFracNumber& inverse() override;

	std::string to_string() const override;

	bool is_correct() const override;

private:
	void reduce();

protected:
	int64_t _num;
	int64_t _den;
};
