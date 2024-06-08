#pragma once
#include "FTools.h"

class IEditor
{
public:
	inline static const char zero = '0';
	inline static const char  one = '1';
	inline static const char sign = '-';

	enum Commands
	{
		addZero = 0,
		addDigit,
		addSign = -10,
		addDot = -11,
		addDelimer = -12,
		doBS = -1,
		doClear = -2,
	};

public:
	virtual const std::string& value() = 0;

	virtual void set_value(const std::string& value) = 0;

	virtual bool is_zero() const = 0;

	virtual void add_sign() = 0;

	virtual void add_dot() = 0;
	
	virtual void add_delimer() = 0;

	virtual void add_digit(uint8_t n) = 0;

	virtual void add_zero() = 0;

	virtual void BS() = 0;

	virtual void clear() = 0;

	virtual void do_edit(int command) = 0;

protected:
	std::string _value = "0";
};
