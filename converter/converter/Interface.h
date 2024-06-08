#pragma once
#include "Control.h"

namespace converter {

	using namespace System;
	using namespace System::Windows::Forms;

	/// <summary>
	/// —водка дл€ Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void)
		{
			InitializeComponent();

			textBoxInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Interface::textBoxInput_KeyPress);;
			this->buttonHistoryClear->Click += gcnew System::EventHandler(this, &Interface::clear_History);
			this->buttonExecute->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->buttonClear->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->buttonDot->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->buttonBS->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->button00->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[0] = button00;
			this->button01->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[1] = button01;
			this->button02->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[2] = button02;
			this->button03->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[3] = button03;
			this->button04->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[4] = button04;
			this->button05->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[5] = button05;
			this->button06->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[6] = button06;
			this->button07->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[7] = button07;
			this->button08->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[8] = button08;
			this->button09->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[9] = button09;
			this->button10->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[10] = button10;
			this->button11->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[11] = button11;
			this->button12->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[12] = button12;
			this->button13->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[13] = button13;
			this->button14->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[14] = button14;
			this->button15->Click += gcnew System::EventHandler(this, &Interface::button_Click);
			this->numberButtons[15] = button15;
			this->trackBarP1->ValueChanged += gcnew System::EventHandler(this, &Interface::trackBarP1_Changed);
			this->numericUpDownP1->ValueChanged += gcnew System::EventHandler(this, &Interface::numericUpDownP1_Changed);
			this->trackBarP2->ValueChanged += gcnew System::EventHandler(this, &Interface::trackBarP2_Changed);
			this->numericUpDownP2->ValueChanged += gcnew System::EventHandler(this, &Interface::numericUpDownP2_Changed);

			UpdateButtons();
		}

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPageConverter;
	private: System::Windows::Forms::TabPage^ tabPageHelp;
	private: System::Windows::Forms::TabPage^ tabPageHistory;
	private: System::Windows::Forms::TextBox^ textBoxInput;
	private: System::Windows::Forms::TextBox^ textBoxOutput;
	private: System::Windows::Forms::TrackBar^ trackBarP1;
	private: System::Windows::Forms::TrackBar^ trackBarP2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownP1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownP2;
	private: System::Windows::Forms::Label^ labelP1;
	private: System::Windows::Forms::Label^ labelP2;
	private: System::Windows::Forms::Button^ buttonExecute;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Button^ buttonBS;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button03;
	private: System::Windows::Forms::Button^ button04;
	private: System::Windows::Forms::Button^ button09;
	private: System::Windows::Forms::Button^ button00;
	private: System::Windows::Forms::Button^ button02;
	private: System::Windows::Forms::Button^ button05;
	private: System::Windows::Forms::Button^ button08;
	private: System::Windows::Forms::Button^ button01;
	private: System::Windows::Forms::Button^ button06;
	private: System::Windows::Forms::Button^ button07;
	private: System::Windows::Forms::Label^ labelInfo;
	private: System::Windows::Forms::TextBox^ textBoxHistory;
	private: System::Windows::Forms::Button^ buttonHistoryClear;

	private: array<Button^>^ numberButtons = gcnew array<Button^>(16);;

	private: NumberConverter::Control* ctrl = new NumberConverter::Control;

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		DoCmnd(System::Convert::ToInt32(dynamic_cast<Button^>(sender)->Tag->ToString()));
	}

	private: System::Void trackBarP1_Changed(System::Object^ sender, System::EventArgs^ e) {
		numericUpDownP1->Value = dynamic_cast<TrackBar^>(sender)->Value;
		this->UpdateP1();
	}

	private: System::Void numericUpDownP1_Changed(System::Object^ sender, System::EventArgs^ e) {
		trackBarP1->Value = System::Convert::ToByte(dynamic_cast<NumericUpDown^>(sender)->Value);
		this->UpdateP1();
	}

	private: System::Void trackBarP2_Changed(System::Object^ sender, System::EventArgs^ e) {
		numericUpDownP2->Value = dynamic_cast<TrackBar^>(sender)->Value;
		this->UpdateP2();
	}

	private: System::Void numericUpDownP2_Changed(System::Object^ sender, System::EventArgs^ e) {
		trackBarP2->Value = System::Convert::ToByte(dynamic_cast<NumericUpDown^>(sender)->Value);
		this->UpdateP2();
	}

	private: System::Void clear_History(System::Object^ sender, System::EventArgs^ e) {
		ctrl->history().clear();
		textBoxHistory->Text = "»стори€ пуста";
	}

	private: System::Void textBoxInput_KeyPress(System::Object^ sender, KeyPressEventArgs^ e) {
		e->Handled = true;

		if (e->KeyChar >= 'a' && e->KeyChar <= 'f') {
			e->KeyChar += 'A' - 'a';
		}

		Int32 cmnd = NumberConverter::Converter_base_10::char_to_int(static_cast<const unsigned char>(e->KeyChar));
		if (e->KeyChar == '\b')
		{
			cmnd = -2;
		}
		if (e->KeyChar == '.')
		{
			cmnd = -1;
		}

		DoCmnd(cmnd);
	}

	private: System::Void DoCmnd(Int32 cmnd) {
		if (cmnd == -4 || cmnd == -6) {
			textBoxOutput->Text = gcnew System::String(ctrl->do_cmnd(cmnd).c_str());

			// if a conversion has realy occurred and new record appeared
			if (ctrl->state() == NumberConverter::Control::State::converted) {
				// first record -> erase placeholder
				if (ctrl->history().count() == 1)
					textBoxHistory->Text = "";

				auto record = ctrl->history().get(ctrl->history().count() - 1);
				auto record_string
					= gcnew System::String(record.from.c_str())
					+ " (" + record.p1 + ") -> "
					+ gcnew System::String(record.to.c_str())
					+ " (" + record.p2 + ")";
				textBoxHistory->Text += record_string + "\r\n";
			}
		}
		else {
			// new input after conversion -> clear results
			if (ctrl->state() == NumberConverter::Control::State::converted) {
				textBoxInput->Text = gcnew System::String(ctrl->do_cmnd(-3).c_str());
				textBoxOutput->Text = "0";
			}
			textBoxInput->Text = gcnew System::String(ctrl->do_cmnd(cmnd).c_str());
		}
	}

	private: System::Void UpdateP1() {
		auto tmp = ctrl->get_p2();
		ctrl->set_p2(trackBarP1->Value);
		textBoxInput->Text = gcnew System::String(ctrl->do_cmnd(-5).c_str());
		ctrl->set_p1(trackBarP1->Value);
		ctrl->set_p2(tmp);

		this->UpdateButtons();
	}

	private: System::Void UpdateP2() {
		ctrl->set_p2(trackBarP2->Value);
		DoCmnd(-6);
	}
		
	private: System::Void UpdateButtons()
	{
		for (Int32 i = 0; i < numberButtons->Length; ++i) {
			numberButtons[i]->Enabled
				= System::Convert::ToInt32(numberButtons[i]->Tag->ToString()) < ctrl->get_p1()
				? true : false;
		}
	}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Interface()
		{
			if (components)
			{
				delete components;
			}

			delete ctrl;
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageConverter = (gcnew System::Windows::Forms::TabPage());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->buttonExecute = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonBS = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button03 = (gcnew System::Windows::Forms::Button());
			this->button04 = (gcnew System::Windows::Forms::Button());
			this->button09 = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->button00 = (gcnew System::Windows::Forms::Button());
			this->button02 = (gcnew System::Windows::Forms::Button());
			this->button05 = (gcnew System::Windows::Forms::Button());
			this->button08 = (gcnew System::Windows::Forms::Button());
			this->button01 = (gcnew System::Windows::Forms::Button());
			this->button06 = (gcnew System::Windows::Forms::Button());
			this->button07 = (gcnew System::Windows::Forms::Button());
			this->labelP2 = (gcnew System::Windows::Forms::Label());
			this->labelP1 = (gcnew System::Windows::Forms::Label());
			this->trackBarP2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarP1 = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDownP2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownP1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPageHistory = (gcnew System::Windows::Forms::TabPage());
			this->buttonHistoryClear = (gcnew System::Windows::Forms::Button());
			this->textBoxHistory = (gcnew System::Windows::Forms::TextBox());
			this->tabPageHelp = (gcnew System::Windows::Forms::TabPage());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPageConverter->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarP2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarP1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownP2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownP1))->BeginInit();
			this->tabPageHistory->SuspendLayout();
			this->tabPageHelp->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageConverter);
			this->tabControl1->Controls->Add(this->tabPageHistory);
			this->tabControl1->Controls->Add(this->tabPageHelp);
			resources->ApplyResources(this->tabControl1, L"tabControl1");
			this->tabControl1->HotTrack = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			// 
			// tabPageConverter
			// 
			this->tabPageConverter->Controls->Add(this->textBoxInput);
			this->tabPageConverter->Controls->Add(this->textBoxOutput);
			this->tabPageConverter->Controls->Add(this->buttonExecute);
			this->tabPageConverter->Controls->Add(this->buttonClear);
			this->tabPageConverter->Controls->Add(this->buttonBS);
			this->tabPageConverter->Controls->Add(this->button13);
			this->tabPageConverter->Controls->Add(this->button14);
			this->tabPageConverter->Controls->Add(this->button15);
			this->tabPageConverter->Controls->Add(this->button10);
			this->tabPageConverter->Controls->Add(this->button11);
			this->tabPageConverter->Controls->Add(this->button12);
			this->tabPageConverter->Controls->Add(this->button03);
			this->tabPageConverter->Controls->Add(this->button04);
			this->tabPageConverter->Controls->Add(this->button09);
			this->tabPageConverter->Controls->Add(this->buttonDot);
			this->tabPageConverter->Controls->Add(this->button00);
			this->tabPageConverter->Controls->Add(this->button02);
			this->tabPageConverter->Controls->Add(this->button05);
			this->tabPageConverter->Controls->Add(this->button08);
			this->tabPageConverter->Controls->Add(this->button01);
			this->tabPageConverter->Controls->Add(this->button06);
			this->tabPageConverter->Controls->Add(this->button07);
			this->tabPageConverter->Controls->Add(this->labelP2);
			this->tabPageConverter->Controls->Add(this->labelP1);
			this->tabPageConverter->Controls->Add(this->trackBarP2);
			this->tabPageConverter->Controls->Add(this->trackBarP1);
			this->tabPageConverter->Controls->Add(this->numericUpDownP2);
			this->tabPageConverter->Controls->Add(this->numericUpDownP1);
			resources->ApplyResources(this->tabPageConverter, L"tabPageConverter");
			this->tabPageConverter->Name = L"tabPageConverter";
			this->tabPageConverter->UseVisualStyleBackColor = true;
			// 
			// textBoxInput
			// 
			resources->ApplyResources(this->textBoxInput, L"textBoxInput");
			this->textBoxInput->Name = L"textBoxInput";
			// 
			// textBoxOutput
			// 
			resources->ApplyResources(this->textBoxOutput, L"textBoxOutput");
			this->textBoxOutput->Name = L"textBoxOutput";
			this->textBoxOutput->ReadOnly = true;
			// 
			// buttonExecute
			// 
			resources->ApplyResources(this->buttonExecute, L"buttonExecute");
			this->buttonExecute->Name = L"buttonExecute";
			this->buttonExecute->Tag = L"-4";
			this->buttonExecute->UseVisualStyleBackColor = true;
			// 
			// buttonClear
			// 
			resources->ApplyResources(this->buttonClear, L"buttonClear");
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Tag = L"-3";
			this->buttonClear->UseVisualStyleBackColor = true;
			// 
			// buttonBS
			// 
			resources->ApplyResources(this->buttonBS, L"buttonBS");
			this->buttonBS->Name = L"buttonBS";
			this->buttonBS->Tag = L"-2";
			this->buttonBS->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			resources->ApplyResources(this->button13, L"button13");
			this->button13->Name = L"button13";
			this->button13->Tag = L"13";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			resources->ApplyResources(this->button14, L"button14");
			this->button14->Name = L"button14";
			this->button14->Tag = L"14";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			resources->ApplyResources(this->button15, L"button15");
			this->button15->Name = L"button15";
			this->button15->Tag = L"15";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			resources->ApplyResources(this->button10, L"button10");
			this->button10->Name = L"button10";
			this->button10->Tag = L"10";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			resources->ApplyResources(this->button11, L"button11");
			this->button11->Name = L"button11";
			this->button11->Tag = L"11";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			resources->ApplyResources(this->button12, L"button12");
			this->button12->Name = L"button12";
			this->button12->Tag = L"12";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button03
			// 
			resources->ApplyResources(this->button03, L"button03");
			this->button03->Name = L"button03";
			this->button03->Tag = L"3";
			this->button03->UseVisualStyleBackColor = true;
			// 
			// button04
			// 
			resources->ApplyResources(this->button04, L"button04");
			this->button04->Name = L"button04";
			this->button04->Tag = L"4";
			this->button04->UseVisualStyleBackColor = true;
			// 
			// button09
			// 
			resources->ApplyResources(this->button09, L"button09");
			this->button09->Name = L"button09";
			this->button09->Tag = L"9";
			this->button09->UseVisualStyleBackColor = true;
			// 
			// buttonDot
			// 
			resources->ApplyResources(this->buttonDot, L"buttonDot");
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Tag = L"-1";
			this->buttonDot->UseVisualStyleBackColor = true;
			// 
			// button00
			// 
			resources->ApplyResources(this->button00, L"button00");
			this->button00->Name = L"button00";
			this->button00->Tag = L"0";
			this->button00->UseVisualStyleBackColor = true;
			// 
			// button02
			// 
			resources->ApplyResources(this->button02, L"button02");
			this->button02->Name = L"button02";
			this->button02->Tag = L"2";
			this->button02->UseVisualStyleBackColor = true;
			// 
			// button05
			// 
			resources->ApplyResources(this->button05, L"button05");
			this->button05->Name = L"button05";
			this->button05->Tag = L"5";
			this->button05->UseVisualStyleBackColor = true;
			// 
			// button08
			// 
			resources->ApplyResources(this->button08, L"button08");
			this->button08->Name = L"button08";
			this->button08->Tag = L"8";
			this->button08->UseVisualStyleBackColor = true;
			// 
			// button01
			// 
			resources->ApplyResources(this->button01, L"button01");
			this->button01->Name = L"button01";
			this->button01->Tag = L"1";
			this->button01->UseVisualStyleBackColor = true;
			// 
			// button06
			// 
			resources->ApplyResources(this->button06, L"button06");
			this->button06->Name = L"button06";
			this->button06->Tag = L"6";
			this->button06->UseVisualStyleBackColor = true;
			// 
			// button07
			// 
			this->button07->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->button07, L"button07");
			this->button07->Name = L"button07";
			this->button07->Tag = L"7";
			this->button07->UseVisualStyleBackColor = false;
			// 
			// labelP2
			// 
			resources->ApplyResources(this->labelP2, L"labelP2");
			this->labelP2->Name = L"labelP2";
			// 
			// labelP1
			// 
			resources->ApplyResources(this->labelP1, L"labelP1");
			this->labelP1->Name = L"labelP1";
			// 
			// trackBarP2
			// 
			resources->ApplyResources(this->trackBarP2, L"trackBarP2");
			this->trackBarP2->BackColor = System::Drawing::SystemColors::Window;
			this->trackBarP2->LargeChange = 2;
			this->trackBarP2->Maximum = 16;
			this->trackBarP2->Minimum = 2;
			this->trackBarP2->Name = L"trackBarP2";
			this->trackBarP2->Value = 2;
			// 
			// trackBarP1
			// 
			resources->ApplyResources(this->trackBarP1, L"trackBarP1");
			this->trackBarP1->BackColor = System::Drawing::SystemColors::Window;
			this->trackBarP1->LargeChange = 2;
			this->trackBarP1->Maximum = 16;
			this->trackBarP1->Minimum = 2;
			this->trackBarP1->Name = L"trackBarP1";
			this->trackBarP1->Value = 10;
			// 
			// numericUpDownP2
			// 
			resources->ApplyResources(this->numericUpDownP2, L"numericUpDownP2");
			this->numericUpDownP2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDownP2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownP2->Name = L"numericUpDownP2";
			this->numericUpDownP2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownP1
			// 
			resources->ApplyResources(this->numericUpDownP1, L"numericUpDownP1");
			this->numericUpDownP1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDownP1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownP1->Name = L"numericUpDownP1";
			this->numericUpDownP1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// tabPageHistory
			// 
			this->tabPageHistory->Controls->Add(this->buttonHistoryClear);
			this->tabPageHistory->Controls->Add(this->textBoxHistory);
			resources->ApplyResources(this->tabPageHistory, L"tabPageHistory");
			this->tabPageHistory->Name = L"tabPageHistory";
			this->tabPageHistory->UseVisualStyleBackColor = true;
			// 
			// buttonHistoryClear
			// 
			resources->ApplyResources(this->buttonHistoryClear, L"buttonHistoryClear");
			this->buttonHistoryClear->Name = L"buttonHistoryClear";
			this->buttonHistoryClear->UseVisualStyleBackColor = true;
			// 
			// textBoxHistory
			// 
			this->textBoxHistory->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxHistory->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->textBoxHistory, L"textBoxHistory");
			this->textBoxHistory->Name = L"textBoxHistory";
			this->textBoxHistory->ReadOnly = true;
			// 
			// tabPageHelp
			// 
			this->tabPageHelp->Controls->Add(this->labelInfo);
			resources->ApplyResources(this->tabPageHelp, L"tabPageHelp");
			this->tabPageHelp->Name = L"tabPageHelp";
			this->tabPageHelp->UseVisualStyleBackColor = true;
			// 
			// labelInfo
			// 
			resources->ApplyResources(this->labelInfo, L"labelInfo");
			this->labelInfo->Name = L"labelInfo";
			// 
			// Interface
			// 
			this->AcceptButton = this->buttonExecute;
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::Teal;
			this->Controls->Add(this->tabControl1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"Interface";
			this->tabControl1->ResumeLayout(false);
			this->tabPageConverter->ResumeLayout(false);
			this->tabPageConverter->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarP2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarP1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownP2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownP1))->EndInit();
			this->tabPageHistory->ResumeLayout(false);
			this->tabPageHistory->PerformLayout();
			this->tabPageHelp->ResumeLayout(false);
			this->tabPageHelp->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
