#pragma once
#include "IEditor.h"

class TCompEditor : public IEditor
{
public:
	inline static const char dot = '.';

	inline static const char delimer = 'i';

public:
	const std::string& value() override;

	void set_value(const std::string& value) override;

	bool is_zero() const override;

	void add_sign() override;

	void add_dot() override;

	void add_delimer() override;

	void add_digit(uint8_t n) override;

	void add_zero() override;

	void BS() override;

	void clear() override;

	void do_edit(int command) override;

public:
	static bool is_zero(std::string value);

private:
	bool _dot1 = false;
	bool _dot2 = false;

	size_t _delimer = -1;
};
