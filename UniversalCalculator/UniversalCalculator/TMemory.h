#pragma once

class INumber;

class TMemory
{
public:
	enum State {
		_Off,
		_On,
	};

public:
	TMemory(INumber* ptr);

	~TMemory();

	void save(const INumber& value);

	const INumber& read() const;

	void add(const INumber& value);

	void clear();

	const State& get_state() const;

protected:
	INumber& _value;

	State _state;
};
