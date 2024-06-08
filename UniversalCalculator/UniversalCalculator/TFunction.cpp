#include "TFunction.h"
#include "TException.h"

TFunction::TFunction
(
	Functions function
) :
	_function(function)
{}

TFunction::TFunction
(
	int function
)
{
	if (None <= function && function <= Sqr)
		_function = static_cast<Functions>(function);
	else
		throw TException("Unknown processor function: " + std::to_string(function));
}

bool TFunction::operator==
(
	TFunction function
)
const
{
	return _function == function._function;
}

TFunction& TFunction::operator=
(
	Functions function
)
{
	_function = function;

	return *this;
}

TFunction::operator int() const
{
	return _function;
}