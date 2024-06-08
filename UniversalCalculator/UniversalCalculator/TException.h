#pragma once
#include <exception>
#include <string>

class TException : std::exception
{
public:
	TException(const std::string& exception_string = "");

	const std::string& What() const;

protected:
	std::string _exception_string;
};
