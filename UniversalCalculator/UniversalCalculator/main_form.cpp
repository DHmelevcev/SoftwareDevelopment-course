#include "main_form.h"

System::Void calculator::main_form::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	if (*PChanging == false) {
		*PChanging = true;
		numericUpDown1->Value = dynamic_cast<TrackBar^>(sender)->Value;
		PChanged();
		*PChanging = false;
	}
}

System::Void calculator::main_form::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (*PChanging == false) {
		*PChanging = true;
		trackBar1->Value = System::Convert::ToInt32(dynamic_cast<NumericUpDown^>(sender)->Value);
		PChanged();
		*PChanging = false;
	}
}

System::Void calculator::main_form::PChanged()
{
	ctrl->set_base(trackBar1->Value);
	textBox1->Text = gcnew String(ctrl->result().to_string().c_str());
	switch (ctrl->next_operation())
	{
	case TOperation::Add:
	{
		textBox1->Text += "+";
		break;
	}
	case TOperation::Sub:
	{
		textBox1->Text += "-";
		break;
	}
	case TOperation::Mul:
	{
		textBox1->Text += "*";
		break;
	}
	case TOperation::Div:
	{
		textBox1->Text += "/";
		break;
	}
	default:
		break;
	}
	textBox2->Text = gcnew String(ctrl->editor_value().c_str());
	UpdateButtons();
}

System::Void calculator::main_form::PNumbers_KeyPress(System::Object^ sender, KeyPressEventArgs^ e)
{
	if (tabControl1->SelectedTab != tabPage1)
		return;

	// copy
	if (e->KeyChar == 3) {
		return;
	}

	Int32 command;
	e->Handled = true;

	// paste
	if (e->KeyChar == 22) {

		ctrl->exec(IEditor::doClear);
		textBox2->Paste();

		for (Int32 i = 0; i < textBox2->Text->Length; ++i) {
			try {
				command = char_to_uint8(static_cast<const unsigned char>(textBox2->Text[i]));
				if (command >= trackBar1->Value)
					break;
				ctrl->exec(command);
			}
			catch (std::exception e) {
				break;
			}
		}

		textBox2->Text = gcnew String(ctrl->editor_value().c_str());
		return;
	}

	if (e->KeyChar >= 'a' && e->KeyChar <= 'f') {
		e->KeyChar += 'A' - 'a';
	}

	switch (e->KeyChar)
	{
	case '\b':
	{
		command = IEditor::doBS;
		break;
	}
	case '.':
	{
		command = IEditor::addDot;
		break;
	}
	case '=':
	case '\r':
	{
		command = TOperation::None;
		break;
	}
	case '+':
	{
		command = TOperation::Add;
		break;
	}
	case '-':
	{
		command = TOperation::Sub;
		break;
	}
	case '*':
	{
		command = TOperation::Mul;
		break;
	}
	case '/':
	{
		command = TOperation::Div;
		break;
	}
	default:
		try {
			command = char_to_uint8(static_cast<const unsigned char>(e->KeyChar));
			if (command >= trackBar1->Value)
				return;
		}
		catch (std::exception e) {
			return;
		}
		break;
	}

	exec_P(command);
}

System::Void calculator::main_form::exec_P(Int32 command)
{
	ctrl->exec(command);
	switch (ctrl->state())
	{
	case TCtrl<TPNumber>::cStart: {
		textBox1->Text = "";
		textBox2->Text = gcnew String(ctrl->editor_value().c_str());

		break;
	}
	case TCtrl<TPNumber>::cEditing: {
		if (textBox1->Text == "Error")
			textBox1->Text = "";
		textBox2->Text = gcnew String(ctrl->editor_value().c_str());

		break;
	}
	case TCtrl<TPNumber>::cOpDone: {
		textBox1->Text = gcnew String(ctrl->result().to_string().c_str());

		switch (ctrl->next_operation())
		{
		case TOperation::Add:
		{
			textBox1->Text += "+";
			break;
		}
		case TOperation::Sub:
		{
			textBox1->Text += "-";
			break;
		}
		case TOperation::Mul:
		{
			textBox1->Text += "*";
			break;
		}
		case TOperation::Div:
		{
			textBox1->Text += "/";
			break;
		}
		default:
			break;
		}

		break;
	}
	case TCtrl<TPNumber>::cOpChange: {
		textBox1->Text = gcnew String(ctrl->result().to_string().c_str());
		textBox2->Text = gcnew String(ctrl->result().to_string().c_str());

		switch (ctrl->next_operation())
		{
		case TOperation::Add:
		{
			textBox1->Text += "+";
			break;
		}
		case TOperation::Sub:
		{
			textBox1->Text += "-";
			break;
		}
		case TOperation::Mul:
		{
			textBox1->Text += "*";
			break;
		}
		case TOperation::Div:
		{
			textBox1->Text += "/";
			break;
		}
		default:
			break;
		}

		break;
	}
	case TCtrl<TPNumber>::cError: {
		textBox1->Text = "Error";
		break;
	}
	default:
		break;
	}
}

System::Void calculator::main_form::button_P_Click(System::Object^ sender, System::EventArgs^ e)
{
	exec_P(System::Convert::ToInt32(dynamic_cast<Button^>(sender)->Tag->ToString()));
	UpdateButtons();
}

System::Void calculator::main_form::UpdateButtons()
{
	button2->Enabled = ctrl->state_memory();
	button3->Enabled = ctrl->state_memory();

	for (Int32 i = 0; i < numbersButtons->Length; ++i) {
		numbersButtons[i]->Enabled
			= System::Convert::ToInt32(numbersButtons[i]->Tag->ToString()) < trackBar1->Value
			? true : false;
	}
}
