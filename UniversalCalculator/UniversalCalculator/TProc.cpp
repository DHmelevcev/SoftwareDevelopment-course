#include "TProc.h"
#include "TPNumber.h"
#include "TFracNumber.h"
#include "TCompNumber.h"

TProc::TProc
(
	INumber* Lop,
	INumber* Rop
) :
	_Lop_Res(*Lop),
	_Rop(*Rop),
	_operation(TOperation::None)
{}

TProc::~TProc()
{
	delete& _Lop_Res;
	delete& _Rop;
}

void TProc::reset()
{
	const TPNumber* castedPNumber = dynamic_cast<const TPNumber*>(&_Lop_Res);
	if (castedPNumber) {
		TPNumber temp;
		temp.base() = castedPNumber->base();
		_Lop_Res = _Rop = temp;
		_operation = TOperation::None;

		return;
	}

	const TFracNumber* castedFrucNumber = dynamic_cast<const TFracNumber*>(&_Lop_Res);
	if (castedFrucNumber) {
		_Lop_Res = _Rop = TFracNumber();
		_operation = TOperation::None;

		return;
	}

	const TCompNumber* castedCompNumber = dynamic_cast<const TCompNumber*>(&_Lop_Res);
	if (castedCompNumber) {
		_Lop_Res = _Rop = TCompNumber();
		_operation = TOperation::None;

		return;
	}
}

void TProc::exec()
{
	switch (_operation)
	{
	case TOperation::Add:
		_Lop_Res += _Rop;
		break;
	case TOperation::Sub:
		_Lop_Res -= _Rop;
		break;
	case TOperation::Mul:
		_Lop_Res *= _Rop;
		break;
	case TOperation::Div:
		_Lop_Res /= _Rop;
		break;
	default:
		break;
	}

	if (!_Lop_Res.is_correct() || !_Rop.is_correct())
		_operation = TOperation::Error;
}

void TProc::exec_func
(
	const TFunction& function
)
{
	switch (function)
	{
	case TFunction::Inverse:
		_Rop.inverse();
		break;
	case TFunction::Sqr:
		_Rop.sqr();
		break;
	default:
		break;
	}

	if (!_Lop_Res.is_correct() || !_Rop.is_correct())
		_operation = TOperation::Error;
}

const INumber& TProc::get_Lop() const
{
	return _Lop_Res;
}

const INumber& TProc::get_Rop() const
{
	return _Rop;
}

void TProc::set_Lop
(
	const INumber& value
)
{
	_Lop_Res = value;
}

void TProc::set_Rop
(
	const INumber& value
)
{
	_Rop = value;
}

const TOperation& TProc::get_operation() const
{
	return _operation;
}

void TProc::set_operation(const TOperation& operation)
{
	_operation = operation;
}
