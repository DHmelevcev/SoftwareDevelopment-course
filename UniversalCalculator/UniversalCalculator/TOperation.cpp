#include "TOperation.h"
#include "TException.h"

TOperation::TOperation
(
	Operations operation
) :
	_operation(operation)
{}

TOperation::TOperation
(
	int operation
)
{
	if (None <= operation && operation <= Error)
		_operation = static_cast<Operations>(operation);
	else
		throw TException("Unknown processor operation: " + std::to_string(operation));
}

bool TOperation::operator==
(
	TOperation operation
)
const
{
	return _operation == operation._operation;
}

TOperation& TOperation::operator=
(
	Operations operation
)
{
	_operation = operation;

	return *this;
}

TOperation::operator int() const
{
	return _operation;
}