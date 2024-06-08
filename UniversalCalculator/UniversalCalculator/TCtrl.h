#pragma once
#include "TPNumber.h"
#include "TFracNumber.h"
#include "TCompNumber.h"
#include "TPEditor.h"
#include "TFracEditor.h"
#include "TCompEditor.h"
#include "TMemory.h"
#include "TProc.h"
#include "TException.h"

template<typename T>
class TCtrl
{
public:
	enum State : int {
		cStart,
		cEditing,
		cOpDone,
		cOpChange,
		cError,
	};

public:
	TCtrl();

	TCtrl(const TCtrl& other) = delete;

	const TCtrl& operator=(const TCtrl& other) = delete;

	~TCtrl();

	const State& state() const;

	const typename TMemory::State& state_memory() const;

	const typename TOperation& next_operation() const;

	const INumber& result() const;

	const std::string& editor_value() const;

	void reset();

	void set_base(int base) = delete;

	void exec(int command);

private:
	void exec_operation(int command);

	void exec_func(int command);

	void exec_memory(int command);

	void exec_editor(int command);

private:
	TProc*   _proc;
	TMemory* _memory;
	IEditor* _editor;

	State _state;
};

template<>
inline TCtrl<TPNumber>::TCtrl() :
	_proc(new TProc(new TPNumber(), new TPNumber())),
	_memory(new TMemory(new TPNumber())),
	_editor(new TPEditor),
	_state(cStart)
{}

template<>
inline TCtrl<TFracNumber>::TCtrl() :
	_proc(new TProc(new TFracNumber(), new TFracNumber())),
	_memory(new TMemory(new TFracNumber())),
	_editor(new TFracEditor),
	_state(cStart)
{}

template<>
inline TCtrl<TCompNumber>::TCtrl() :
	_proc(new TProc(new TCompNumber(), new TCompNumber())),
	_memory(new TMemory(new TCompNumber())),
	_editor(new TCompEditor),
	_state(cStart)
{}

template<typename T>
inline TCtrl<T>::~TCtrl()
{
	delete _editor;
	delete _memory;
	delete _proc;
}

template<typename T>
inline const typename TCtrl<T>::State& TCtrl<T>::state() const
{
	return _state;
}

template<typename T>
inline const typename TMemory::State& TCtrl<T>::state_memory() const
{
	return _memory->get_state();
}

template<typename T>
inline const typename TOperation& TCtrl<T>::next_operation() const
{
	return _proc->get_operation();
}

template<typename T>
inline const INumber& TCtrl<T>::result() const
{
	return _proc->get_Lop();
}

template<typename T>
inline const std::string& TCtrl<T>::editor_value() const
{
	return _editor->value();
}

template<typename T>
inline void TCtrl<T>::reset()
{
	_proc->reset();
	_editor->clear();
	_state = TCtrl<T>::State::cStart;
}

template<typename T>
inline void TCtrl<T>::exec(int command)
{
	if (TFunction::None <= command) {
		if (_state != cError)
			exec_func(command);
	}
	else if (TOperation::None <= command) {
		if (_state != cError)
			exec_operation(command);
	}
	else if (-20 < command) {
		if (_state == cError)
			reset();

		exec_editor(command);
	}
	else if (-30 < command) {
		if (_state != cError)
			exec_memory(command);
	}
	else if (-100 == command) {
		reset();
	}
	else {
		throw TException("Unknown command: " + std::to_string(command));
	}
}

template<typename T>
inline void TCtrl<T>::exec_operation(int command)
{
	switch (_state)
	{
	case cStart: {
		_proc->set_operation(command);
		_state = cOpChange;
		break;
	}
	case cEditing: {
		_proc->set_Rop(T(_editor->value()));
		if (_proc->get_operation() != TOperation::None) {
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		else {
			_proc->set_Lop(_proc->get_Rop());
			_state = cOpDone;
		}
		if (command != TOperation::None)
			_proc->set_operation(command);
		break;
	}
	case cOpDone: {
		if (command != TOperation::None) {
			_proc->set_operation(command);
			_state = cOpChange;
			_editor->set_value(_proc->get_Lop().to_string());
		}
		else {
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		break;
	}
	case cOpChange: {
		if (command != TOperation::None) {
			_proc->set_operation(command);
		}
		else {
			_proc->set_Rop(_proc->get_Lop());
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		break;
	}
	default:
		break;
	}
}

template<typename T>
inline void TCtrl<T>::exec_func(int command)
{
	_proc->set_Rop(T(_editor->value()));
	_proc->exec_func(command);
	_editor->set_value(_proc->get_Rop().to_string());
	_state = cEditing;
}

template<typename T>
inline void TCtrl<T>::exec_memory(int command)
{
	switch (command)
	{
	case -20:
		_memory->clear();
		break;
	case -21:
		if (_state == cEditing)
			_memory->save(T(_editor->value()));
		else
			_memory->save(_proc->get_Lop());
		break;
	case -22:
		if (_state == cEditing)
			_memory->add(T(_editor->value()));
		else
			_memory->add(_proc->get_Lop());
		break;
	case -23:
		_editor->set_value(_memory->read().to_string());
		_state = cEditing;
		break;
	default:
		throw TException("Unknown memory command: " + std::to_string(command));
		break;
	}
}

template<typename T>
inline void TCtrl<T>::exec_editor(int command)
{
	if (_state != cEditing && command != IEditor::addSign)
		_editor->clear();
	_editor->do_edit(command);
	_state = cEditing;
}

#pragma region TPNumber
class TPNumber;

template<>
inline void TCtrl<TPNumber>::set_base(int base)
{
	TPNumber& lop = const_cast<TPNumber&>(
						dynamic_cast<const TPNumber&>(
							_proc->get_Lop()
						)
					);

	TPNumber& rop = const_cast<TPNumber&>(
						dynamic_cast<const TPNumber&>(
							_proc->get_Rop()
						)
					);

	lop.base() = base;
	TPNumber temp(_editor->value(), rop.base());
	temp.base() = base;
	rop.base() = base;

	_editor->set_value(temp.to_string());
}

template<>
inline void TCtrl<TPNumber>::exec_operation(int command)
{
	switch (_state)
	{
	case cStart: {
		_proc->set_operation(command);
		_state = cOpChange;
		break;
	}
	case cEditing: {
		TPNumber& rop = const_cast<TPNumber&>(
			dynamic_cast<const TPNumber&>(
				_proc->get_Rop()
				)
			);

		_proc->set_Rop(TPNumber(_editor->value(), rop.base()));
		if (_proc->get_operation() != TOperation::None) {
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		else {
			_proc->set_Lop(_proc->get_Rop());
			_state = cOpDone;
		}
		if (command != TOperation::None)
			_proc->set_operation(command);
		break;
	}
	case cOpDone: {
		if (command != TOperation::None) {
			_proc->set_operation(command);
			_state = cOpChange;
			_editor->set_value(_proc->get_Lop().to_string());
		}
		else {
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		break;
	}
	case cOpChange: {
		if (command != TOperation::None) {
			_proc->set_operation(command);
		}
		else {
			_proc->set_Rop(_proc->get_Lop());
			_proc->exec();
			if (_proc->get_operation() != TOperation::Error)
				_state = cOpDone;
			else
				_state = cError;
		}
		break;
	}
	default:
		break;
	}
}

template<>
inline void TCtrl<TPNumber>::exec_func(int command)
{
	TPNumber& rop = const_cast<TPNumber&>(
		dynamic_cast<const TPNumber&>(
			_proc->get_Rop()
			)
		);

	_proc->set_Rop(TPNumber(_editor->value(), rop.base()));
	_proc->exec_func(command);
	_editor->set_value(_proc->get_Rop().to_string());
	_state = cEditing;
}

template<>
inline void TCtrl<TPNumber>::exec_memory(int command)
{
	switch (command)
	{
	case -20:
		_memory->clear();
		break;
	case -21: {
		TPNumber& rop = const_cast<TPNumber&>(
			dynamic_cast<const TPNumber&>(
				_proc->get_Rop()
				)
			);

		if (_state == cEditing)
			_memory->save(TPNumber(_editor->value(), rop.base()));
		else
			_memory->save(_proc->get_Lop());
		break;
	}
	case -22: {
		TPNumber& rop = const_cast<TPNumber&>(
			dynamic_cast<const TPNumber&>(
				_proc->get_Rop()
				)
			);

		if (_state == cEditing)
			_memory->add(TPNumber(_editor->value(), rop.base()));
		else
			_memory->add(_proc->get_Lop());
		break;
	}
	case -23: {
		TPNumber& rop = const_cast<TPNumber&>(
			dynamic_cast<const TPNumber&>(
				_proc->get_Rop()
				)
			);

		TPNumber& readed = const_cast<TPNumber&>(
			dynamic_cast<const TPNumber&>(
				_memory->read()
				)
			);
		readed.base() = rop.base();

		_editor->set_value(readed.to_string());
		_state = cEditing;
		break;
	}
	default:
		throw TException("Unknown memory command: " + std::to_string(command));
		break;
	}
}

#pragma endregion TPNumber