#pragma once
#include "TOperation.h"
#include "TFunction.h"

class INumber;

class TProc
{
public:
	TProc(INumber* Lop, INumber* Rop);

	~TProc();

	void reset();

	void exec();

	void exec_func(const TFunction& function);

	const INumber& get_Lop() const;

	const INumber& get_Rop() const;

	void set_Lop(const INumber& value);

	void set_Rop(const INumber& value);

	const TOperation& get_operation() const;

	void set_operation(const TOperation& operation);

protected:
	INumber& _Lop_Res;
	INumber& _Rop;
	TOperation _operation;
};
