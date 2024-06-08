#pragma once

class TFunction
{
public:
	enum Functions : int {
		None = 200,
		Inverse,
		Sqr,
	};

public:
	TFunction(Functions operation = None);

	TFunction(int operation);

	bool operator==(TFunction operation) const;

	TFunction& operator=(Functions operation);

	operator int() const;

protected:
	Functions _function;
};
