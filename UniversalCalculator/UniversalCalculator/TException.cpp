#include "TException.h"

TException::TException
(
	const std::string& exception_string
) :
	_exception_string(exception_string)
{}

const std::string& TException::What() const
{
	return _exception_string;
}
