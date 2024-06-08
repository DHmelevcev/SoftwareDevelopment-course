#pragma once

class TOperation
{
public:
	enum Operations : int {
		None = 100,
		Add,
		Sub,
		Mul,
		Div,
		Error,
	};

public:
	TOperation(Operations operation = None);

	TOperation(int operation);

	bool operator==(TOperation operation) const;

	TOperation& operator=(Operations operation);

	operator int() const;

protected:
	Operations _operation;
};
