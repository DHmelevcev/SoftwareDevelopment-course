#pragma once
#include <memory>
#include "FTools.h"

class INumber
{
public:
	using return_ptr = std::unique_ptr<INumber>;

public:
	virtual INumber& operator=(const INumber& other) = 0;

	virtual bool operator==(const INumber& other) const = 0;

	virtual bool is_zero() const = 0;

	virtual return_ptr operator+(const INumber& other) const = 0;

	virtual return_ptr operator-(const INumber& other) const = 0;

	virtual return_ptr operator*(const INumber& other) const = 0;

	virtual return_ptr operator/(const INumber& other) const = 0;

	virtual return_ptr operator-() const = 0;

	virtual INumber& operator+=(const INumber& other) = 0;

	virtual INumber& operator-=(const INumber& other) = 0;

	virtual INumber& operator*=(const INumber& other) = 0;

	virtual INumber& operator/=(const INumber& other) = 0;

	virtual INumber& negate() = 0;

	virtual INumber& sqr() = 0;

	virtual INumber& inverse() = 0;

	virtual std::string to_string() const = 0;

	virtual bool is_correct() const = 0;

	virtual ~INumber() {};
};
