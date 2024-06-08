#pragma once
#include "TCtrl.h"

namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void) : ctrl(new TCtrl<TPNumber>), PChanging(new bool(false))
		{
			InitializeComponent();

			textBox2->Text = gcnew String(ctrl->editor_value().c_str());

			this->numbersButtons[0] = button30;
			this->numbersButtons[1] = button24;
			this->numbersButtons[2] = button25;
			this->numbersButtons[3] = button26;
			this->numbersButtons[4] = button18;
			this->numbersButtons[5] = button19;
			this->numbersButtons[6] = button20;
			this->numbersButtons[7] = button13;
			this->numbersButtons[8] = button14;
			this->numbersButtons[9] = button15;
			this->numbersButtons[10] = button28;
			this->numbersButtons[11] = button23;
			this->numbersButtons[12] = button17;
			this->numbersButtons[13] = button12;
			this->numbersButtons[14] = button7;
			this->numbersButtons[15] = button1;
			UpdateButtons();
		}

	protected:
		~main_form()
		{
			if (components)
			{
				delete ctrl;
				delete components;
			}
		}

	private: TCtrl<TPNumber>* ctrl;
	private: bool* PChanging;
	private: array<Button^>^ numbersButtons = gcnew array<Button^>(16);
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::Button^ button50;
	private: System::Windows::Forms::Button^ button52;
	private: System::Windows::Forms::Button^ button53;
	private: System::Windows::Forms::Button^ button54;
	private: System::Windows::Forms::Button^ button55;
	private: System::Windows::Forms::Button^ button56;
	private: System::Windows::Forms::Button^ button57;
	private: System::Windows::Forms::Button^ button58;
	private: System::Windows::Forms::Button^ button59;
	private: System::Windows::Forms::Button^ button60;
	private: System::Windows::Forms::Button^ button61;
	private: System::Windows::Forms::Button^ button62;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TabControl^ tabControl1;
private: System::Windows::Forms::TabPage^ tabPage4;
private: System::Windows::Forms::Button^ button36;
private: System::Windows::Forms::Button^ button44;
private: System::Windows::Forms::Button^ button49;
private: System::Windows::Forms::Button^ button51;
private: System::Windows::Forms::Button^ button63;
private: System::Windows::Forms::Button^ button64;
private: System::Windows::Forms::Button^ button85;
private: System::Windows::Forms::Button^ button65;
private: System::Windows::Forms::Button^ button66;
private: System::Windows::Forms::Button^ button67;
private: System::Windows::Forms::Button^ button68;
private: System::Windows::Forms::Button^ button69;
private: System::Windows::Forms::Button^ button70;
private: System::Windows::Forms::Button^ button71;
private: System::Windows::Forms::Button^ button72;
private: System::Windows::Forms::Button^ button73;
private: System::Windows::Forms::Button^ button74;
private: System::Windows::Forms::Button^ button75;
private: System::Windows::Forms::Button^ button76;
private: System::Windows::Forms::Button^ button77;
private: System::Windows::Forms::Button^ button78;
private: System::Windows::Forms::Button^ button79;
private: System::Windows::Forms::Button^ button80;
private: System::Windows::Forms::Button^ button81;
private: System::Windows::Forms::Button^ button82;
private: System::Windows::Forms::Button^ button83;
private: System::Windows::Forms::Button^ button84;
private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::Label^ label1;



	private: System::ComponentModel::Container^ components;










































#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->button62 = (gcnew System::Windows::Forms::Button());
			   this->button61 = (gcnew System::Windows::Forms::Button());
			   this->button60 = (gcnew System::Windows::Forms::Button());
			   this->button59 = (gcnew System::Windows::Forms::Button());
			   this->button58 = (gcnew System::Windows::Forms::Button());
			   this->button57 = (gcnew System::Windows::Forms::Button());
			   this->button56 = (gcnew System::Windows::Forms::Button());
			   this->button55 = (gcnew System::Windows::Forms::Button());
			   this->button54 = (gcnew System::Windows::Forms::Button());
			   this->button53 = (gcnew System::Windows::Forms::Button());
			   this->button52 = (gcnew System::Windows::Forms::Button());
			   this->button50 = (gcnew System::Windows::Forms::Button());
			   this->button48 = (gcnew System::Windows::Forms::Button());
			   this->button47 = (gcnew System::Windows::Forms::Button());
			   this->button46 = (gcnew System::Windows::Forms::Button());
			   this->button45 = (gcnew System::Windows::Forms::Button());
			   this->button43 = (gcnew System::Windows::Forms::Button());
			   this->button42 = (gcnew System::Windows::Forms::Button());
			   this->button41 = (gcnew System::Windows::Forms::Button());
			   this->button40 = (gcnew System::Windows::Forms::Button());
			   this->button39 = (gcnew System::Windows::Forms::Button());
			   this->button38 = (gcnew System::Windows::Forms::Button());
			   this->button37 = (gcnew System::Windows::Forms::Button());
			   this->button35 = (gcnew System::Windows::Forms::Button());
			   this->button34 = (gcnew System::Windows::Forms::Button());
			   this->button33 = (gcnew System::Windows::Forms::Button());
			   this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button13 = (gcnew System::Windows::Forms::Button());
			   this->button18 = (gcnew System::Windows::Forms::Button());
			   this->button10 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button16 = (gcnew System::Windows::Forms::Button());
			   this->button21 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button14 = (gcnew System::Windows::Forms::Button());
			   this->button19 = (gcnew System::Windows::Forms::Button());
			   this->button11 = (gcnew System::Windows::Forms::Button());
			   this->button17 = (gcnew System::Windows::Forms::Button());
			   this->button22 = (gcnew System::Windows::Forms::Button());
			   this->button23 = (gcnew System::Windows::Forms::Button());
			   this->button24 = (gcnew System::Windows::Forms::Button());
			   this->button25 = (gcnew System::Windows::Forms::Button());
			   this->button26 = (gcnew System::Windows::Forms::Button());
			   this->button27 = (gcnew System::Windows::Forms::Button());
			   this->button28 = (gcnew System::Windows::Forms::Button());
			   this->button29 = (gcnew System::Windows::Forms::Button());
			   this->button30 = (gcnew System::Windows::Forms::Button());
			   this->button31 = (gcnew System::Windows::Forms::Button());
			   this->button32 = (gcnew System::Windows::Forms::Button());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button15 = (gcnew System::Windows::Forms::Button());
			   this->button20 = (gcnew System::Windows::Forms::Button());
			   this->button12 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			   this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			   this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			   this->button36 = (gcnew System::Windows::Forms::Button());
			   this->button44 = (gcnew System::Windows::Forms::Button());
			   this->button49 = (gcnew System::Windows::Forms::Button());
			   this->button51 = (gcnew System::Windows::Forms::Button());
			   this->button63 = (gcnew System::Windows::Forms::Button());
			   this->button64 = (gcnew System::Windows::Forms::Button());
			   this->button65 = (gcnew System::Windows::Forms::Button());
			   this->button66 = (gcnew System::Windows::Forms::Button());
			   this->button67 = (gcnew System::Windows::Forms::Button());
			   this->button68 = (gcnew System::Windows::Forms::Button());
			   this->button69 = (gcnew System::Windows::Forms::Button());
			   this->button70 = (gcnew System::Windows::Forms::Button());
			   this->button71 = (gcnew System::Windows::Forms::Button());
			   this->button72 = (gcnew System::Windows::Forms::Button());
			   this->button73 = (gcnew System::Windows::Forms::Button());
			   this->button74 = (gcnew System::Windows::Forms::Button());
			   this->button75 = (gcnew System::Windows::Forms::Button());
			   this->button76 = (gcnew System::Windows::Forms::Button());
			   this->button77 = (gcnew System::Windows::Forms::Button());
			   this->button78 = (gcnew System::Windows::Forms::Button());
			   this->button79 = (gcnew System::Windows::Forms::Button());
			   this->button80 = (gcnew System::Windows::Forms::Button());
			   this->button81 = (gcnew System::Windows::Forms::Button());
			   this->button82 = (gcnew System::Windows::Forms::Button());
			   this->button83 = (gcnew System::Windows::Forms::Button());
			   this->button84 = (gcnew System::Windows::Forms::Button());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->button85 = (gcnew System::Windows::Forms::Button());
			   this->tabPage3->SuspendLayout();
			   this->tabPage1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			   this->tabControl1->SuspendLayout();
			   this->tabPage4->SuspendLayout();
			   this->tabPage2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // tabPage3
			   // 
			   this->tabPage3->BackColor = System::Drawing::Color::White;
			   this->tabPage3->CausesValidation = false;
			   this->tabPage3->Controls->Add(this->button33);
			   this->tabPage3->Controls->Add(this->button34);
			   this->tabPage3->Controls->Add(this->button35);
			   this->tabPage3->Controls->Add(this->button37);
			   this->tabPage3->Controls->Add(this->button38);
			   this->tabPage3->Controls->Add(this->button39);
			   this->tabPage3->Controls->Add(this->button40);
			   this->tabPage3->Controls->Add(this->button41);
			   this->tabPage3->Controls->Add(this->button42);
			   this->tabPage3->Controls->Add(this->button43);
			   this->tabPage3->Controls->Add(this->button45);
			   this->tabPage3->Controls->Add(this->button46);
			   this->tabPage3->Controls->Add(this->button47);
			   this->tabPage3->Controls->Add(this->button48);
			   this->tabPage3->Controls->Add(this->button50);
			   this->tabPage3->Controls->Add(this->button52);
			   this->tabPage3->Controls->Add(this->button53);
			   this->tabPage3->Controls->Add(this->button54);
			   this->tabPage3->Controls->Add(this->button55);
			   this->tabPage3->Controls->Add(this->button56);
			   this->tabPage3->Controls->Add(this->button57);
			   this->tabPage3->Controls->Add(this->button58);
			   this->tabPage3->Controls->Add(this->button59);
			   this->tabPage3->Controls->Add(this->button60);
			   this->tabPage3->Controls->Add(this->button61);
			   this->tabPage3->Controls->Add(this->button62);
			   this->tabPage3->Controls->Add(this->textBox3);
			   this->tabPage3->Controls->Add(this->textBox4);
			   this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->tabPage3->Location = System::Drawing::Point(4, 29);
			   this->tabPage3->Margin = System::Windows::Forms::Padding(0);
			   this->tabPage3->Name = L"tabPage3";
			   this->tabPage3->Size = System::Drawing::Size(554, 633);
			   this->tabPage3->TabIndex = 2;
			   this->tabPage3->Text = L"Frac Numbers";
			   // 
			   // textBox4
			   // 
			   this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			   this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox4->CausesValidation = false;
			   this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox4->Location = System::Drawing::Point(10, 15);
			   this->textBox4->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->ReadOnly = true;
			   this->textBox4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox4->Size = System::Drawing::Size(530, 44);
			   this->textBox4->TabIndex = 1;
			   this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // textBox3
			   // 
			   this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox3->CausesValidation = false;
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox3->Location = System::Drawing::Point(10, 58);
			   this->textBox3->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox3->Size = System::Drawing::Size(530, 44);
			   this->textBox3->TabIndex = 2;
			   this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // button62
			   // 
			   this->button62->BackColor = System::Drawing::SystemColors::Control;
			   this->button62->CausesValidation = false;
			   this->button62->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button62->Location = System::Drawing::Point(48, 161);
			   this->button62->Margin = System::Windows::Forms::Padding(5);
			   this->button62->Name = L"button62";
			   this->button62->Size = System::Drawing::Size(80, 60);
			   this->button62->TabIndex = 6;
			   this->button62->Tag = L"-20";
			   this->button62->Text = L"MC";
			   this->button62->UseVisualStyleBackColor = false;
			   // 
			   // button61
			   // 
			   this->button61->BackColor = System::Drawing::SystemColors::Control;
			   this->button61->CausesValidation = false;
			   this->button61->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button61->Location = System::Drawing::Point(48, 301);
			   this->button61->Margin = System::Windows::Forms::Padding(5);
			   this->button61->Name = L"button61";
			   this->button61->Size = System::Drawing::Size(80, 60);
			   this->button61->TabIndex = 17;
			   this->button61->Tag = L"7";
			   this->button61->Text = L"7";
			   this->button61->UseVisualStyleBackColor = false;
			   // 
			   // button60
			   // 
			   this->button60->BackColor = System::Drawing::SystemColors::Control;
			   this->button60->CausesValidation = false;
			   this->button60->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button60->Location = System::Drawing::Point(48, 371);
			   this->button60->Margin = System::Windows::Forms::Padding(5);
			   this->button60->Name = L"button60";
			   this->button60->Size = System::Drawing::Size(80, 60);
			   this->button60->TabIndex = 22;
			   this->button60->Tag = L"4";
			   this->button60->Text = L"4";
			   this->button60->UseVisualStyleBackColor = false;
			   // 
			   // button59
			   // 
			   this->button59->BackColor = System::Drawing::SystemColors::Control;
			   this->button59->CausesValidation = false;
			   this->button59->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button59->Location = System::Drawing::Point(318, 231);
			   this->button59->Margin = System::Windows::Forms::Padding(5);
			   this->button59->Name = L"button59";
			   this->button59->Size = System::Drawing::Size(80, 60);
			   this->button59->TabIndex = 14;
			   this->button59->Tag = L"104";
			   this->button59->Text = L"/";
			   this->button59->UseVisualStyleBackColor = false;
			   // 
			   // button58
			   // 
			   this->button58->BackColor = System::Drawing::SystemColors::Control;
			   this->button58->CausesValidation = false;
			   this->button58->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button58->Location = System::Drawing::Point(48, 231);
			   this->button58->Margin = System::Windows::Forms::Padding(5);
			   this->button58->Name = L"button58";
			   this->button58->Size = System::Drawing::Size(125, 60);
			   this->button58->TabIndex = 12;
			   this->button58->Tag = L"201";
			   this->button58->Text = L"1/x";
			   this->button58->UseVisualStyleBackColor = false;
			   // 
			   // button57
			   // 
			   this->button57->BackColor = System::Drawing::SystemColors::Control;
			   this->button57->CausesValidation = false;
			   this->button57->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button57->Location = System::Drawing::Point(318, 301);
			   this->button57->Margin = System::Windows::Forms::Padding(5);
			   this->button57->Name = L"button57";
			   this->button57->Size = System::Drawing::Size(80, 60);
			   this->button57->TabIndex = 20;
			   this->button57->Tag = L"103";
			   this->button57->Text = L"*";
			   this->button57->UseVisualStyleBackColor = false;
			   // 
			   // button56
			   // 
			   this->button56->BackColor = System::Drawing::SystemColors::Control;
			   this->button56->CausesValidation = false;
			   this->button56->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button56->Location = System::Drawing::Point(318, 371);
			   this->button56->Margin = System::Windows::Forms::Padding(5);
			   this->button56->Name = L"button56";
			   this->button56->Size = System::Drawing::Size(80, 60);
			   this->button56->TabIndex = 25;
			   this->button56->Tag = L"102";
			   this->button56->Text = L"-";
			   this->button56->UseVisualStyleBackColor = false;
			   // 
			   // button55
			   // 
			   this->button55->BackColor = System::Drawing::SystemColors::Control;
			   this->button55->CausesValidation = false;
			   this->button55->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button55->Location = System::Drawing::Point(138, 161);
			   this->button55->Margin = System::Windows::Forms::Padding(5);
			   this->button55->Name = L"button55";
			   this->button55->Size = System::Drawing::Size(80, 60);
			   this->button55->TabIndex = 7;
			   this->button55->Tag = L"-23";
			   this->button55->Text = L"MR";
			   this->button55->UseVisualStyleBackColor = false;
			   // 
			   // button54
			   // 
			   this->button54->BackColor = System::Drawing::SystemColors::Control;
			   this->button54->CausesValidation = false;
			   this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button54->Location = System::Drawing::Point(138, 301);
			   this->button54->Margin = System::Windows::Forms::Padding(5);
			   this->button54->Name = L"button54";
			   this->button54->Size = System::Drawing::Size(80, 60);
			   this->button54->TabIndex = 18;
			   this->button54->Tag = L"8";
			   this->button54->Text = L"8";
			   this->button54->UseVisualStyleBackColor = false;
			   // 
			   // button53
			   // 
			   this->button53->BackColor = System::Drawing::SystemColors::Control;
			   this->button53->CausesValidation = false;
			   this->button53->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button53->Location = System::Drawing::Point(138, 371);
			   this->button53->Margin = System::Windows::Forms::Padding(5);
			   this->button53->Name = L"button53";
			   this->button53->Size = System::Drawing::Size(80, 60);
			   this->button53->TabIndex = 23;
			   this->button53->Tag = L"5";
			   this->button53->Text = L"5";
			   this->button53->UseVisualStyleBackColor = false;
			   // 
			   // button52
			   // 
			   this->button52->BackColor = System::Drawing::SystemColors::Control;
			   this->button52->CausesValidation = false;
			   this->button52->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button52->Location = System::Drawing::Point(408, 231);
			   this->button52->Margin = System::Windows::Forms::Padding(5);
			   this->button52->Name = L"button52";
			   this->button52->Size = System::Drawing::Size(80, 130);
			   this->button52->TabIndex = 15;
			   this->button52->Tag = L"-2";
			   this->button52->Text = L"CE";
			   this->button52->UseVisualStyleBackColor = false;
			   // 
			   // button50
			   // 
			   this->button50->BackColor = System::Drawing::SystemColors::Control;
			   this->button50->CausesValidation = false;
			   this->button50->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button50->Location = System::Drawing::Point(408, 371);
			   this->button50->Margin = System::Windows::Forms::Padding(5);
			   this->button50->Name = L"button50";
			   this->button50->Size = System::Drawing::Size(80, 130);
			   this->button50->TabIndex = 26;
			   this->button50->Tag = L"-1";
			   this->button50->Text = L"BS";
			   this->button50->UseVisualStyleBackColor = false;
			   // 
			   // button48
			   // 
			   this->button48->BackColor = System::Drawing::SystemColors::Control;
			   this->button48->CausesValidation = false;
			   this->button48->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button48->Location = System::Drawing::Point(48, 441);
			   this->button48->Margin = System::Windows::Forms::Padding(5);
			   this->button48->Name = L"button48";
			   this->button48->Size = System::Drawing::Size(80, 60);
			   this->button48->TabIndex = 28;
			   this->button48->Tag = L"1";
			   this->button48->Text = L"1";
			   this->button48->UseVisualStyleBackColor = false;
			   // 
			   // button47
			   // 
			   this->button47->BackColor = System::Drawing::SystemColors::Control;
			   this->button47->CausesValidation = false;
			   this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button47->Location = System::Drawing::Point(138, 441);
			   this->button47->Margin = System::Windows::Forms::Padding(5);
			   this->button47->Name = L"button47";
			   this->button47->Size = System::Drawing::Size(80, 60);
			   this->button47->TabIndex = 29;
			   this->button47->Tag = L"2";
			   this->button47->Text = L"2";
			   this->button47->UseVisualStyleBackColor = false;
			   // 
			   // button46
			   // 
			   this->button46->BackColor = System::Drawing::SystemColors::Control;
			   this->button46->CausesValidation = false;
			   this->button46->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button46->Location = System::Drawing::Point(228, 441);
			   this->button46->Margin = System::Windows::Forms::Padding(5);
			   this->button46->Name = L"button46";
			   this->button46->Size = System::Drawing::Size(80, 60);
			   this->button46->TabIndex = 30;
			   this->button46->Tag = L"3";
			   this->button46->Text = L"3";
			   this->button46->UseVisualStyleBackColor = false;
			   // 
			   // button45
			   // 
			   this->button45->BackColor = System::Drawing::SystemColors::Control;
			   this->button45->CausesValidation = false;
			   this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button45->Location = System::Drawing::Point(318, 441);
			   this->button45->Margin = System::Windows::Forms::Padding(5);
			   this->button45->Name = L"button45";
			   this->button45->Size = System::Drawing::Size(80, 60);
			   this->button45->TabIndex = 31;
			   this->button45->Tag = L"101";
			   this->button45->Text = L"+";
			   this->button45->UseVisualStyleBackColor = false;
			   // 
			   // button43
			   // 
			   this->button43->BackColor = System::Drawing::SystemColors::Control;
			   this->button43->CausesValidation = false;
			   this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button43->Location = System::Drawing::Point(48, 511);
			   this->button43->Margin = System::Windows::Forms::Padding(5);
			   this->button43->Name = L"button43";
			   this->button43->Size = System::Drawing::Size(80, 60);
			   this->button43->TabIndex = 33;
			   this->button43->Tag = L"-10";
			   this->button43->Text = L"+/-";
			   this->button43->UseVisualStyleBackColor = false;
			   // 
			   // button42
			   // 
			   this->button42->BackColor = System::Drawing::SystemColors::Control;
			   this->button42->CausesValidation = false;
			   this->button42->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button42->Location = System::Drawing::Point(138, 511);
			   this->button42->Margin = System::Windows::Forms::Padding(5);
			   this->button42->Name = L"button42";
			   this->button42->Size = System::Drawing::Size(80, 60);
			   this->button42->TabIndex = 34;
			   this->button42->Tag = L"0";
			   this->button42->Text = L"0";
			   this->button42->UseVisualStyleBackColor = false;
			   // 
			   // button41
			   // 
			   this->button41->BackColor = System::Drawing::SystemColors::Control;
			   this->button41->CausesValidation = false;
			   this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button41->Location = System::Drawing::Point(228, 511);
			   this->button41->Margin = System::Windows::Forms::Padding(5);
			   this->button41->Name = L"button41";
			   this->button41->Size = System::Drawing::Size(80, 60);
			   this->button41->TabIndex = 35;
			   this->button41->Tag = L"-12";
			   this->button41->Text = L"|";
			   this->button41->UseVisualStyleBackColor = false;
			   // 
			   // button40
			   // 
			   this->button40->BackColor = System::Drawing::SystemColors::Control;
			   this->button40->CausesValidation = false;
			   this->button40->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button40->Location = System::Drawing::Point(318, 511);
			   this->button40->Margin = System::Windows::Forms::Padding(5);
			   this->button40->Name = L"button40";
			   this->button40->Size = System::Drawing::Size(170, 60);
			   this->button40->TabIndex = 36;
			   this->button40->Tag = L"100";
			   this->button40->Text = L"=";
			   this->button40->UseVisualStyleBackColor = false;
			   // 
			   // button39
			   // 
			   this->button39->BackColor = System::Drawing::SystemColors::Control;
			   this->button39->CausesValidation = false;
			   this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button39->Location = System::Drawing::Point(183, 231);
			   this->button39->Margin = System::Windows::Forms::Padding(5);
			   this->button39->Name = L"button39";
			   this->button39->Size = System::Drawing::Size(125, 60);
			   this->button39->TabIndex = 13;
			   this->button39->Tag = L"202";
			   this->button39->Text = L"x^2";
			   this->button39->UseVisualStyleBackColor = false;
			   // 
			   // button38
			   // 
			   this->button38->BackColor = System::Drawing::SystemColors::Control;
			   this->button38->CausesValidation = false;
			   this->button38->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button38->Location = System::Drawing::Point(228, 301);
			   this->button38->Margin = System::Windows::Forms::Padding(5);
			   this->button38->Name = L"button38";
			   this->button38->Size = System::Drawing::Size(80, 60);
			   this->button38->TabIndex = 19;
			   this->button38->Tag = L"9";
			   this->button38->Text = L"9";
			   this->button38->UseVisualStyleBackColor = false;
			   // 
			   // button37
			   // 
			   this->button37->BackColor = System::Drawing::SystemColors::Control;
			   this->button37->CausesValidation = false;
			   this->button37->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button37->Location = System::Drawing::Point(228, 371);
			   this->button37->Margin = System::Windows::Forms::Padding(5);
			   this->button37->Name = L"button37";
			   this->button37->Size = System::Drawing::Size(80, 60);
			   this->button37->TabIndex = 24;
			   this->button37->Tag = L"6";
			   this->button37->Text = L"6";
			   this->button37->UseVisualStyleBackColor = false;
			   // 
			   // button35
			   // 
			   this->button35->BackColor = System::Drawing::SystemColors::Control;
			   this->button35->CausesValidation = false;
			   this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button35->Location = System::Drawing::Point(318, 161);
			   this->button35->Margin = System::Windows::Forms::Padding(5);
			   this->button35->Name = L"button35";
			   this->button35->Size = System::Drawing::Size(80, 60);
			   this->button35->TabIndex = 9;
			   this->button35->Tag = L"-21";
			   this->button35->Text = L"MS";
			   this->button35->UseVisualStyleBackColor = false;
			   // 
			   // button34
			   // 
			   this->button34->BackColor = System::Drawing::SystemColors::Control;
			   this->button34->CausesValidation = false;
			   this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button34->Location = System::Drawing::Point(228, 161);
			   this->button34->Margin = System::Windows::Forms::Padding(5);
			   this->button34->Name = L"button34";
			   this->button34->Size = System::Drawing::Size(80, 60);
			   this->button34->TabIndex = 8;
			   this->button34->Tag = L"-22";
			   this->button34->Text = L"M+";
			   this->button34->UseVisualStyleBackColor = false;
			   // 
			   // button33
			   // 
			   this->button33->BackColor = System::Drawing::SystemColors::Control;
			   this->button33->CausesValidation = false;
			   this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button33->Location = System::Drawing::Point(408, 161);
			   this->button33->Margin = System::Windows::Forms::Padding(5);
			   this->button33->Name = L"button33";
			   this->button33->Size = System::Drawing::Size(80, 60);
			   this->button33->TabIndex = 10;
			   this->button33->Tag = L"-100";
			   this->button33->Text = L"C";
			   this->button33->UseVisualStyleBackColor = false;
			   // 
			   // tabPage1
			   // 
			   this->tabPage1->BackColor = System::Drawing::Color::White;
			   this->tabPage1->CausesValidation = false;
			   this->tabPage1->Controls->Add(this->numericUpDown1);
			   this->tabPage1->Controls->Add(this->trackBar1);
			   this->tabPage1->Controls->Add(this->button6);
			   this->tabPage1->Controls->Add(this->button4);
			   this->tabPage1->Controls->Add(this->button5);
			   this->tabPage1->Controls->Add(this->button12);
			   this->tabPage1->Controls->Add(this->button20);
			   this->tabPage1->Controls->Add(this->button15);
			   this->tabPage1->Controls->Add(this->button9);
			   this->tabPage1->Controls->Add(this->button32);
			   this->tabPage1->Controls->Add(this->button31);
			   this->tabPage1->Controls->Add(this->button30);
			   this->tabPage1->Controls->Add(this->button29);
			   this->tabPage1->Controls->Add(this->button28);
			   this->tabPage1->Controls->Add(this->button27);
			   this->tabPage1->Controls->Add(this->button26);
			   this->tabPage1->Controls->Add(this->button25);
			   this->tabPage1->Controls->Add(this->button24);
			   this->tabPage1->Controls->Add(this->button23);
			   this->tabPage1->Controls->Add(this->button22);
			   this->tabPage1->Controls->Add(this->button17);
			   this->tabPage1->Controls->Add(this->button11);
			   this->tabPage1->Controls->Add(this->button19);
			   this->tabPage1->Controls->Add(this->button14);
			   this->tabPage1->Controls->Add(this->button3);
			   this->tabPage1->Controls->Add(this->button21);
			   this->tabPage1->Controls->Add(this->button16);
			   this->tabPage1->Controls->Add(this->button8);
			   this->tabPage1->Controls->Add(this->button10);
			   this->tabPage1->Controls->Add(this->button18);
			   this->tabPage1->Controls->Add(this->button13);
			   this->tabPage1->Controls->Add(this->button2);
			   this->tabPage1->Controls->Add(this->button7);
			   this->tabPage1->Controls->Add(this->button1);
			   this->tabPage1->Controls->Add(this->textBox2);
			   this->tabPage1->Controls->Add(this->textBox1);
			   this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->tabPage1->Location = System::Drawing::Point(4, 29);
			   this->tabPage1->Margin = System::Windows::Forms::Padding(0);
			   this->tabPage1->Name = L"tabPage1";
			   this->tabPage1->Size = System::Drawing::Size(554, 633);
			   this->tabPage1->TabIndex = 0;
			   this->tabPage1->Text = L"P Numbers";
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			   this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox1->CausesValidation = false;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox1->Location = System::Drawing::Point(10, 15);
			   this->textBox1->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->ReadOnly = true;
			   this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox1->Size = System::Drawing::Size(530, 44);
			   this->textBox1->TabIndex = 1;
			   this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // textBox2
			   // 
			   this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox2->CausesValidation = false;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox2->Location = System::Drawing::Point(10, 58);
			   this->textBox2->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox2->Size = System::Drawing::Size(530, 44);
			   this->textBox2->TabIndex = 2;
			   this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::SystemColors::Control;
			   this->button1->CausesValidation = false;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Location = System::Drawing::Point(10, 122);
			   this->button1->Margin = System::Windows::Forms::Padding(5);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(80, 60);
			   this->button1->TabIndex = 5;
			   this->button1->Tag = L"15";
			   this->button1->Text = L"F";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button7
			   // 
			   this->button7->BackColor = System::Drawing::SystemColors::Control;
			   this->button7->CausesValidation = false;
			   this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button7->Location = System::Drawing::Point(10, 192);
			   this->button7->Margin = System::Windows::Forms::Padding(5);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(80, 60);
			   this->button7->TabIndex = 11;
			   this->button7->Tag = L"14";
			   this->button7->Text = L"E";
			   this->button7->UseVisualStyleBackColor = false;
			   this->button7->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::SystemColors::Control;
			   this->button2->CausesValidation = false;
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button2->Location = System::Drawing::Point(100, 122);
			   this->button2->Margin = System::Windows::Forms::Padding(5);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(80, 60);
			   this->button2->TabIndex = 6;
			   this->button2->Tag = L"-20";
			   this->button2->Text = L"MC";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button13
			   // 
			   this->button13->BackColor = System::Drawing::SystemColors::Control;
			   this->button13->CausesValidation = false;
			   this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button13->Location = System::Drawing::Point(100, 262);
			   this->button13->Margin = System::Windows::Forms::Padding(5);
			   this->button13->Name = L"button13";
			   this->button13->Size = System::Drawing::Size(80, 60);
			   this->button13->TabIndex = 17;
			   this->button13->Tag = L"7";
			   this->button13->Text = L"7";
			   this->button13->UseVisualStyleBackColor = false;
			   this->button13->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button18
			   // 
			   this->button18->BackColor = System::Drawing::SystemColors::Control;
			   this->button18->CausesValidation = false;
			   this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button18->Location = System::Drawing::Point(100, 332);
			   this->button18->Margin = System::Windows::Forms::Padding(5);
			   this->button18->Name = L"button18";
			   this->button18->Size = System::Drawing::Size(80, 60);
			   this->button18->TabIndex = 22;
			   this->button18->Tag = L"4";
			   this->button18->Text = L"4";
			   this->button18->UseVisualStyleBackColor = false;
			   this->button18->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button10
			   // 
			   this->button10->BackColor = System::Drawing::SystemColors::Control;
			   this->button10->CausesValidation = false;
			   this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button10->Location = System::Drawing::Point(370, 192);
			   this->button10->Margin = System::Windows::Forms::Padding(5);
			   this->button10->Name = L"button10";
			   this->button10->Size = System::Drawing::Size(80, 60);
			   this->button10->TabIndex = 14;
			   this->button10->Tag = L"104";
			   this->button10->Text = L"/";
			   this->button10->UseVisualStyleBackColor = false;
			   this->button10->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button8
			   // 
			   this->button8->BackColor = System::Drawing::SystemColors::Control;
			   this->button8->CausesValidation = false;
			   this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button8->Location = System::Drawing::Point(100, 192);
			   this->button8->Margin = System::Windows::Forms::Padding(5);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(125, 60);
			   this->button8->TabIndex = 12;
			   this->button8->Tag = L"201";
			   this->button8->Text = L"1/x";
			   this->button8->UseVisualStyleBackColor = false;
			   this->button8->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button16
			   // 
			   this->button16->BackColor = System::Drawing::SystemColors::Control;
			   this->button16->CausesValidation = false;
			   this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button16->Location = System::Drawing::Point(370, 262);
			   this->button16->Margin = System::Windows::Forms::Padding(5);
			   this->button16->Name = L"button16";
			   this->button16->Size = System::Drawing::Size(80, 60);
			   this->button16->TabIndex = 20;
			   this->button16->Tag = L"103";
			   this->button16->Text = L"*";
			   this->button16->UseVisualStyleBackColor = false;
			   this->button16->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button21
			   // 
			   this->button21->BackColor = System::Drawing::SystemColors::Control;
			   this->button21->CausesValidation = false;
			   this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button21->Location = System::Drawing::Point(370, 332);
			   this->button21->Margin = System::Windows::Forms::Padding(5);
			   this->button21->Name = L"button21";
			   this->button21->Size = System::Drawing::Size(80, 60);
			   this->button21->TabIndex = 25;
			   this->button21->Tag = L"102";
			   this->button21->Text = L"-";
			   this->button21->UseVisualStyleBackColor = false;
			   this->button21->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::SystemColors::Control;
			   this->button3->CausesValidation = false;
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Location = System::Drawing::Point(190, 122);
			   this->button3->Margin = System::Windows::Forms::Padding(5);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(80, 60);
			   this->button3->TabIndex = 7;
			   this->button3->Tag = L"-23";
			   this->button3->Text = L"MR";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button14
			   // 
			   this->button14->BackColor = System::Drawing::SystemColors::Control;
			   this->button14->CausesValidation = false;
			   this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button14->Location = System::Drawing::Point(190, 262);
			   this->button14->Margin = System::Windows::Forms::Padding(5);
			   this->button14->Name = L"button14";
			   this->button14->Size = System::Drawing::Size(80, 60);
			   this->button14->TabIndex = 18;
			   this->button14->Tag = L"8";
			   this->button14->Text = L"8";
			   this->button14->UseVisualStyleBackColor = false;
			   this->button14->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button19
			   // 
			   this->button19->BackColor = System::Drawing::SystemColors::Control;
			   this->button19->CausesValidation = false;
			   this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button19->Location = System::Drawing::Point(190, 332);
			   this->button19->Margin = System::Windows::Forms::Padding(5);
			   this->button19->Name = L"button19";
			   this->button19->Size = System::Drawing::Size(80, 60);
			   this->button19->TabIndex = 23;
			   this->button19->Tag = L"5";
			   this->button19->Text = L"5";
			   this->button19->UseVisualStyleBackColor = false;
			   this->button19->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button11
			   // 
			   this->button11->BackColor = System::Drawing::SystemColors::Control;
			   this->button11->CausesValidation = false;
			   this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button11->Location = System::Drawing::Point(460, 192);
			   this->button11->Margin = System::Windows::Forms::Padding(5);
			   this->button11->Name = L"button11";
			   this->button11->Size = System::Drawing::Size(80, 130);
			   this->button11->TabIndex = 15;
			   this->button11->Tag = L"-2";
			   this->button11->Text = L"CE";
			   this->button11->UseVisualStyleBackColor = false;
			   this->button11->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button17
			   // 
			   this->button17->BackColor = System::Drawing::SystemColors::Control;
			   this->button17->CausesValidation = false;
			   this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button17->Location = System::Drawing::Point(10, 332);
			   this->button17->Margin = System::Windows::Forms::Padding(5);
			   this->button17->Name = L"button17";
			   this->button17->Size = System::Drawing::Size(80, 60);
			   this->button17->TabIndex = 21;
			   this->button17->Tag = L"12";
			   this->button17->Text = L"C";
			   this->button17->UseVisualStyleBackColor = false;
			   this->button17->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button22
			   // 
			   this->button22->BackColor = System::Drawing::SystemColors::Control;
			   this->button22->CausesValidation = false;
			   this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button22->Location = System::Drawing::Point(460, 332);
			   this->button22->Margin = System::Windows::Forms::Padding(5);
			   this->button22->Name = L"button22";
			   this->button22->Size = System::Drawing::Size(80, 130);
			   this->button22->TabIndex = 26;
			   this->button22->Tag = L"-1";
			   this->button22->Text = L"BS";
			   this->button22->UseVisualStyleBackColor = false;
			   this->button22->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button23
			   // 
			   this->button23->BackColor = System::Drawing::SystemColors::Control;
			   this->button23->CausesValidation = false;
			   this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button23->Location = System::Drawing::Point(10, 402);
			   this->button23->Margin = System::Windows::Forms::Padding(5);
			   this->button23->Name = L"button23";
			   this->button23->Size = System::Drawing::Size(80, 60);
			   this->button23->TabIndex = 27;
			   this->button23->Tag = L"11";
			   this->button23->Text = L"B";
			   this->button23->UseVisualStyleBackColor = false;
			   this->button23->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button24
			   // 
			   this->button24->BackColor = System::Drawing::SystemColors::Control;
			   this->button24->CausesValidation = false;
			   this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button24->Location = System::Drawing::Point(100, 402);
			   this->button24->Margin = System::Windows::Forms::Padding(5);
			   this->button24->Name = L"button24";
			   this->button24->Size = System::Drawing::Size(80, 60);
			   this->button24->TabIndex = 28;
			   this->button24->Tag = L"1";
			   this->button24->Text = L"1";
			   this->button24->UseVisualStyleBackColor = false;
			   this->button24->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button25
			   // 
			   this->button25->BackColor = System::Drawing::SystemColors::Control;
			   this->button25->CausesValidation = false;
			   this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button25->Location = System::Drawing::Point(190, 402);
			   this->button25->Margin = System::Windows::Forms::Padding(5);
			   this->button25->Name = L"button25";
			   this->button25->Size = System::Drawing::Size(80, 60);
			   this->button25->TabIndex = 29;
			   this->button25->Tag = L"2";
			   this->button25->Text = L"2";
			   this->button25->UseVisualStyleBackColor = false;
			   this->button25->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button26
			   // 
			   this->button26->BackColor = System::Drawing::SystemColors::Control;
			   this->button26->CausesValidation = false;
			   this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button26->Location = System::Drawing::Point(280, 402);
			   this->button26->Margin = System::Windows::Forms::Padding(5);
			   this->button26->Name = L"button26";
			   this->button26->Size = System::Drawing::Size(80, 60);
			   this->button26->TabIndex = 30;
			   this->button26->Tag = L"3";
			   this->button26->Text = L"3";
			   this->button26->UseVisualStyleBackColor = false;
			   this->button26->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button27
			   // 
			   this->button27->BackColor = System::Drawing::SystemColors::Control;
			   this->button27->CausesValidation = false;
			   this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button27->Location = System::Drawing::Point(370, 402);
			   this->button27->Margin = System::Windows::Forms::Padding(5);
			   this->button27->Name = L"button27";
			   this->button27->Size = System::Drawing::Size(80, 60);
			   this->button27->TabIndex = 31;
			   this->button27->Tag = L"101";
			   this->button27->Text = L"+";
			   this->button27->UseVisualStyleBackColor = false;
			   this->button27->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button28
			   // 
			   this->button28->BackColor = System::Drawing::SystemColors::Control;
			   this->button28->CausesValidation = false;
			   this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button28->Location = System::Drawing::Point(10, 472);
			   this->button28->Margin = System::Windows::Forms::Padding(5);
			   this->button28->Name = L"button28";
			   this->button28->Size = System::Drawing::Size(80, 60);
			   this->button28->TabIndex = 32;
			   this->button28->Tag = L"10";
			   this->button28->Text = L"A";
			   this->button28->UseVisualStyleBackColor = false;
			   this->button28->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button29
			   // 
			   this->button29->BackColor = System::Drawing::SystemColors::Control;
			   this->button29->CausesValidation = false;
			   this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button29->Location = System::Drawing::Point(100, 472);
			   this->button29->Margin = System::Windows::Forms::Padding(5);
			   this->button29->Name = L"button29";
			   this->button29->Size = System::Drawing::Size(80, 60);
			   this->button29->TabIndex = 33;
			   this->button29->Tag = L"-10";
			   this->button29->Text = L"+/-";
			   this->button29->UseVisualStyleBackColor = false;
			   this->button29->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button30
			   // 
			   this->button30->BackColor = System::Drawing::SystemColors::Control;
			   this->button30->CausesValidation = false;
			   this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button30->Location = System::Drawing::Point(190, 472);
			   this->button30->Margin = System::Windows::Forms::Padding(5);
			   this->button30->Name = L"button30";
			   this->button30->Size = System::Drawing::Size(80, 60);
			   this->button30->TabIndex = 34;
			   this->button30->Tag = L"0";
			   this->button30->Text = L"0";
			   this->button30->UseVisualStyleBackColor = false;
			   this->button30->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button31
			   // 
			   this->button31->BackColor = System::Drawing::SystemColors::Control;
			   this->button31->CausesValidation = false;
			   this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button31->Location = System::Drawing::Point(280, 472);
			   this->button31->Margin = System::Windows::Forms::Padding(5);
			   this->button31->Name = L"button31";
			   this->button31->Size = System::Drawing::Size(80, 60);
			   this->button31->TabIndex = 35;
			   this->button31->Tag = L"-11";
			   this->button31->Text = L".";
			   this->button31->UseVisualStyleBackColor = false;
			   this->button31->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button32
			   // 
			   this->button32->BackColor = System::Drawing::SystemColors::Control;
			   this->button32->CausesValidation = false;
			   this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button32->Location = System::Drawing::Point(370, 472);
			   this->button32->Margin = System::Windows::Forms::Padding(5);
			   this->button32->Name = L"button32";
			   this->button32->Size = System::Drawing::Size(170, 60);
			   this->button32->TabIndex = 36;
			   this->button32->Tag = L"100";
			   this->button32->Text = L"=";
			   this->button32->UseVisualStyleBackColor = false;
			   this->button32->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button9
			   // 
			   this->button9->BackColor = System::Drawing::SystemColors::Control;
			   this->button9->CausesValidation = false;
			   this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button9->Location = System::Drawing::Point(235, 192);
			   this->button9->Margin = System::Windows::Forms::Padding(5);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(125, 60);
			   this->button9->TabIndex = 13;
			   this->button9->Tag = L"202";
			   this->button9->Text = L"x^2";
			   this->button9->UseVisualStyleBackColor = false;
			   this->button9->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button15
			   // 
			   this->button15->BackColor = System::Drawing::SystemColors::Control;
			   this->button15->CausesValidation = false;
			   this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button15->Location = System::Drawing::Point(280, 262);
			   this->button15->Margin = System::Windows::Forms::Padding(5);
			   this->button15->Name = L"button15";
			   this->button15->Size = System::Drawing::Size(80, 60);
			   this->button15->TabIndex = 19;
			   this->button15->Tag = L"9";
			   this->button15->Text = L"9";
			   this->button15->UseVisualStyleBackColor = false;
			   this->button15->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button20
			   // 
			   this->button20->BackColor = System::Drawing::SystemColors::Control;
			   this->button20->CausesValidation = false;
			   this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button20->Location = System::Drawing::Point(280, 332);
			   this->button20->Margin = System::Windows::Forms::Padding(5);
			   this->button20->Name = L"button20";
			   this->button20->Size = System::Drawing::Size(80, 60);
			   this->button20->TabIndex = 24;
			   this->button20->Tag = L"6";
			   this->button20->Text = L"6";
			   this->button20->UseVisualStyleBackColor = false;
			   this->button20->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button12
			   // 
			   this->button12->BackColor = System::Drawing::SystemColors::Control;
			   this->button12->CausesValidation = false;
			   this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button12->Location = System::Drawing::Point(10, 262);
			   this->button12->Margin = System::Windows::Forms::Padding(5);
			   this->button12->Name = L"button12";
			   this->button12->Size = System::Drawing::Size(80, 60);
			   this->button12->TabIndex = 16;
			   this->button12->Tag = L"13";
			   this->button12->Text = L"D";
			   this->button12->UseVisualStyleBackColor = false;
			   this->button12->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button5
			   // 
			   this->button5->BackColor = System::Drawing::SystemColors::Control;
			   this->button5->CausesValidation = false;
			   this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button5->Location = System::Drawing::Point(370, 122);
			   this->button5->Margin = System::Windows::Forms::Padding(5);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(80, 60);
			   this->button5->TabIndex = 9;
			   this->button5->Tag = L"-21";
			   this->button5->Text = L"MS";
			   this->button5->UseVisualStyleBackColor = false;
			   this->button5->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button4
			   // 
			   this->button4->BackColor = System::Drawing::SystemColors::Control;
			   this->button4->CausesValidation = false;
			   this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button4->Location = System::Drawing::Point(280, 122);
			   this->button4->Margin = System::Windows::Forms::Padding(5);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(80, 60);
			   this->button4->TabIndex = 8;
			   this->button4->Tag = L"-22";
			   this->button4->Text = L"M+";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // button6
			   // 
			   this->button6->BackColor = System::Drawing::SystemColors::Control;
			   this->button6->CausesValidation = false;
			   this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button6->Location = System::Drawing::Point(460, 122);
			   this->button6->Margin = System::Windows::Forms::Padding(5);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(80, 60);
			   this->button6->TabIndex = 10;
			   this->button6->Tag = L"-100";
			   this->button6->Text = L"C";
			   this->button6->UseVisualStyleBackColor = false;
			   this->button6->Click += gcnew System::EventHandler(this, &main_form::button_P_Click);
			   // 
			   // trackBar1
			   // 
			   this->trackBar1->CausesValidation = false;
			   this->trackBar1->LargeChange = 2;
			   this->trackBar1->Location = System::Drawing::Point(10, 547);
			   this->trackBar1->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			   this->trackBar1->Maximum = 16;
			   this->trackBar1->Minimum = 2;
			   this->trackBar1->Name = L"trackBar1";
			   this->trackBar1->Size = System::Drawing::Size(440, 69);
			   this->trackBar1->TabIndex = 3;
			   this->trackBar1->Value = 10;
			   this->trackBar1->Scroll += gcnew System::EventHandler(this, &main_form::trackBar1_Scroll);
			   // 
			   // numericUpDown1
			   // 
			   this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->numericUpDown1->CausesValidation = false;
			   this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->numericUpDown1->Location = System::Drawing::Point(461, 547);
			   this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			   this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			   this->numericUpDown1->Name = L"numericUpDown1";
			   this->numericUpDown1->Size = System::Drawing::Size(79, 35);
			   this->numericUpDown1->TabIndex = 4;
			   this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			   this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &main_form::numericUpDown1_ValueChanged);
			   // 
			   // tabControl1
			   // 
			   this->tabControl1->Controls->Add(this->tabPage1);
			   this->tabControl1->Controls->Add(this->tabPage3);
			   this->tabControl1->Controls->Add(this->tabPage4);
			   this->tabControl1->Controls->Add(this->tabPage2);
			   this->tabControl1->Cursor = System::Windows::Forms::Cursors::Default;
			   this->tabControl1->Location = System::Drawing::Point(0, 0);
			   this->tabControl1->Margin = System::Windows::Forms::Padding(0);
			   this->tabControl1->Name = L"tabControl1";
			   this->tabControl1->SelectedIndex = 0;
			   this->tabControl1->Size = System::Drawing::Size(562, 666);
			   this->tabControl1->TabIndex = 0;
			   // 
			   // tabPage4
			   // 
			   this->tabPage4->BackColor = System::Drawing::Color::White;
			   this->tabPage4->CausesValidation = false;
			   this->tabPage4->Controls->Add(this->button36);
			   this->tabPage4->Controls->Add(this->button44);
			   this->tabPage4->Controls->Add(this->button49);
			   this->tabPage4->Controls->Add(this->button51);
			   this->tabPage4->Controls->Add(this->button63);
			   this->tabPage4->Controls->Add(this->button64);
			   this->tabPage4->Controls->Add(this->button85);
			   this->tabPage4->Controls->Add(this->button65);
			   this->tabPage4->Controls->Add(this->button66);
			   this->tabPage4->Controls->Add(this->button67);
			   this->tabPage4->Controls->Add(this->button68);
			   this->tabPage4->Controls->Add(this->button69);
			   this->tabPage4->Controls->Add(this->button70);
			   this->tabPage4->Controls->Add(this->button71);
			   this->tabPage4->Controls->Add(this->button72);
			   this->tabPage4->Controls->Add(this->button73);
			   this->tabPage4->Controls->Add(this->button74);
			   this->tabPage4->Controls->Add(this->button75);
			   this->tabPage4->Controls->Add(this->button76);
			   this->tabPage4->Controls->Add(this->button77);
			   this->tabPage4->Controls->Add(this->button78);
			   this->tabPage4->Controls->Add(this->button79);
			   this->tabPage4->Controls->Add(this->button80);
			   this->tabPage4->Controls->Add(this->button81);
			   this->tabPage4->Controls->Add(this->button82);
			   this->tabPage4->Controls->Add(this->button83);
			   this->tabPage4->Controls->Add(this->button84);
			   this->tabPage4->Controls->Add(this->textBox5);
			   this->tabPage4->Controls->Add(this->textBox6);
			   this->tabPage4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->tabPage4->Location = System::Drawing::Point(4, 29);
			   this->tabPage4->Margin = System::Windows::Forms::Padding(0);
			   this->tabPage4->Name = L"tabPage4";
			   this->tabPage4->Size = System::Drawing::Size(554, 633);
			   this->tabPage4->TabIndex = 4;
			   this->tabPage4->Text = L"Comp Numbers";
			   // 
			   // button36
			   // 
			   this->button36->BackColor = System::Drawing::SystemColors::Control;
			   this->button36->CausesValidation = false;
			   this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button36->Location = System::Drawing::Point(408, 163);
			   this->button36->Margin = System::Windows::Forms::Padding(5);
			   this->button36->Name = L"button36";
			   this->button36->Size = System::Drawing::Size(80, 60);
			   this->button36->TabIndex = 10;
			   this->button36->Tag = L"-100";
			   this->button36->Text = L"C";
			   this->button36->UseVisualStyleBackColor = false;
			   // 
			   // button44
			   // 
			   this->button44->BackColor = System::Drawing::SystemColors::Control;
			   this->button44->CausesValidation = false;
			   this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button44->Location = System::Drawing::Point(228, 163);
			   this->button44->Margin = System::Windows::Forms::Padding(5);
			   this->button44->Name = L"button44";
			   this->button44->Size = System::Drawing::Size(80, 60);
			   this->button44->TabIndex = 8;
			   this->button44->Tag = L"-22";
			   this->button44->Text = L"M+";
			   this->button44->UseVisualStyleBackColor = false;
			   // 
			   // button49
			   // 
			   this->button49->BackColor = System::Drawing::SystemColors::Control;
			   this->button49->CausesValidation = false;
			   this->button49->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button49->Location = System::Drawing::Point(318, 163);
			   this->button49->Margin = System::Windows::Forms::Padding(5);
			   this->button49->Name = L"button49";
			   this->button49->Size = System::Drawing::Size(80, 60);
			   this->button49->TabIndex = 9;
			   this->button49->Tag = L"-21";
			   this->button49->Text = L"MS";
			   this->button49->UseVisualStyleBackColor = false;
			   // 
			   // button51
			   // 
			   this->button51->BackColor = System::Drawing::SystemColors::Control;
			   this->button51->CausesValidation = false;
			   this->button51->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button51->Location = System::Drawing::Point(228, 373);
			   this->button51->Margin = System::Windows::Forms::Padding(5);
			   this->button51->Name = L"button51";
			   this->button51->Size = System::Drawing::Size(80, 60);
			   this->button51->TabIndex = 24;
			   this->button51->Tag = L"6";
			   this->button51->Text = L"6";
			   this->button51->UseVisualStyleBackColor = false;
			   // 
			   // button63
			   // 
			   this->button63->BackColor = System::Drawing::SystemColors::Control;
			   this->button63->CausesValidation = false;
			   this->button63->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button63->Location = System::Drawing::Point(228, 303);
			   this->button63->Margin = System::Windows::Forms::Padding(5);
			   this->button63->Name = L"button63";
			   this->button63->Size = System::Drawing::Size(80, 60);
			   this->button63->TabIndex = 19;
			   this->button63->Tag = L"9";
			   this->button63->Text = L"9";
			   this->button63->UseVisualStyleBackColor = false;
			   // 
			   // button64
			   // 
			   this->button64->BackColor = System::Drawing::SystemColors::Control;
			   this->button64->CausesValidation = false;
			   this->button64->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button64->Location = System::Drawing::Point(183, 233);
			   this->button64->Margin = System::Windows::Forms::Padding(5);
			   this->button64->Name = L"button64";
			   this->button64->Size = System::Drawing::Size(125, 60);
			   this->button64->TabIndex = 13;
			   this->button64->Tag = L"202";
			   this->button64->Text = L"x^2";
			   this->button64->UseVisualStyleBackColor = false;
			   // 
			   // button65
			   // 
			   this->button65->BackColor = System::Drawing::SystemColors::Control;
			   this->button65->CausesValidation = false;
			   this->button65->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button65->Location = System::Drawing::Point(408, 513);
			   this->button65->Margin = System::Windows::Forms::Padding(5);
			   this->button65->Name = L"button65";
			   this->button65->Size = System::Drawing::Size(80, 60);
			   this->button65->TabIndex = 36;
			   this->button65->Tag = L"100";
			   this->button65->Text = L"=";
			   this->button65->UseVisualStyleBackColor = false;
			   // 
			   // button66
			   // 
			   this->button66->BackColor = System::Drawing::SystemColors::Control;
			   this->button66->CausesValidation = false;
			   this->button66->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button66->Location = System::Drawing::Point(228, 513);
			   this->button66->Margin = System::Windows::Forms::Padding(5);
			   this->button66->Name = L"button66";
			   this->button66->Size = System::Drawing::Size(80, 60);
			   this->button66->TabIndex = 35;
			   this->button66->Tag = L"-11";
			   this->button66->Text = L".";
			   this->button66->UseVisualStyleBackColor = false;
			   // 
			   // button67
			   // 
			   this->button67->BackColor = System::Drawing::SystemColors::Control;
			   this->button67->CausesValidation = false;
			   this->button67->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button67->Location = System::Drawing::Point(138, 513);
			   this->button67->Margin = System::Windows::Forms::Padding(5);
			   this->button67->Name = L"button67";
			   this->button67->Size = System::Drawing::Size(80, 60);
			   this->button67->TabIndex = 34;
			   this->button67->Tag = L"0";
			   this->button67->Text = L"0";
			   this->button67->UseVisualStyleBackColor = false;
			   // 
			   // button68
			   // 
			   this->button68->BackColor = System::Drawing::SystemColors::Control;
			   this->button68->CausesValidation = false;
			   this->button68->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button68->Location = System::Drawing::Point(48, 513);
			   this->button68->Margin = System::Windows::Forms::Padding(5);
			   this->button68->Name = L"button68";
			   this->button68->Size = System::Drawing::Size(80, 60);
			   this->button68->TabIndex = 33;
			   this->button68->Tag = L"-10";
			   this->button68->Text = L"+/-";
			   this->button68->UseVisualStyleBackColor = false;
			   // 
			   // button69
			   // 
			   this->button69->BackColor = System::Drawing::SystemColors::Control;
			   this->button69->CausesValidation = false;
			   this->button69->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button69->Location = System::Drawing::Point(318, 443);
			   this->button69->Margin = System::Windows::Forms::Padding(5);
			   this->button69->Name = L"button69";
			   this->button69->Size = System::Drawing::Size(80, 60);
			   this->button69->TabIndex = 31;
			   this->button69->Tag = L"101";
			   this->button69->Text = L"+";
			   this->button69->UseVisualStyleBackColor = false;
			   // 
			   // button70
			   // 
			   this->button70->BackColor = System::Drawing::SystemColors::Control;
			   this->button70->CausesValidation = false;
			   this->button70->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button70->Location = System::Drawing::Point(228, 443);
			   this->button70->Margin = System::Windows::Forms::Padding(5);
			   this->button70->Name = L"button70";
			   this->button70->Size = System::Drawing::Size(80, 60);
			   this->button70->TabIndex = 30;
			   this->button70->Tag = L"3";
			   this->button70->Text = L"3";
			   this->button70->UseVisualStyleBackColor = false;
			   // 
			   // button71
			   // 
			   this->button71->BackColor = System::Drawing::SystemColors::Control;
			   this->button71->CausesValidation = false;
			   this->button71->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button71->Location = System::Drawing::Point(138, 443);
			   this->button71->Margin = System::Windows::Forms::Padding(5);
			   this->button71->Name = L"button71";
			   this->button71->Size = System::Drawing::Size(80, 60);
			   this->button71->TabIndex = 29;
			   this->button71->Tag = L"2";
			   this->button71->Text = L"2";
			   this->button71->UseVisualStyleBackColor = false;
			   // 
			   // button72
			   // 
			   this->button72->BackColor = System::Drawing::SystemColors::Control;
			   this->button72->CausesValidation = false;
			   this->button72->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button72->Location = System::Drawing::Point(48, 443);
			   this->button72->Margin = System::Windows::Forms::Padding(5);
			   this->button72->Name = L"button72";
			   this->button72->Size = System::Drawing::Size(80, 60);
			   this->button72->TabIndex = 28;
			   this->button72->Tag = L"1";
			   this->button72->Text = L"1";
			   this->button72->UseVisualStyleBackColor = false;
			   // 
			   // button73
			   // 
			   this->button73->BackColor = System::Drawing::SystemColors::Control;
			   this->button73->CausesValidation = false;
			   this->button73->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button73->Location = System::Drawing::Point(408, 373);
			   this->button73->Margin = System::Windows::Forms::Padding(5);
			   this->button73->Name = L"button73";
			   this->button73->Size = System::Drawing::Size(80, 130);
			   this->button73->TabIndex = 26;
			   this->button73->Tag = L"-1";
			   this->button73->Text = L"BS";
			   this->button73->UseVisualStyleBackColor = false;
			   // 
			   // button74
			   // 
			   this->button74->BackColor = System::Drawing::SystemColors::Control;
			   this->button74->CausesValidation = false;
			   this->button74->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button74->Location = System::Drawing::Point(408, 233);
			   this->button74->Margin = System::Windows::Forms::Padding(5);
			   this->button74->Name = L"button74";
			   this->button74->Size = System::Drawing::Size(80, 130);
			   this->button74->TabIndex = 15;
			   this->button74->Tag = L"-2";
			   this->button74->Text = L"CE";
			   this->button74->UseVisualStyleBackColor = false;
			   // 
			   // button75
			   // 
			   this->button75->BackColor = System::Drawing::SystemColors::Control;
			   this->button75->CausesValidation = false;
			   this->button75->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button75->Location = System::Drawing::Point(138, 373);
			   this->button75->Margin = System::Windows::Forms::Padding(5);
			   this->button75->Name = L"button75";
			   this->button75->Size = System::Drawing::Size(80, 60);
			   this->button75->TabIndex = 23;
			   this->button75->Tag = L"5";
			   this->button75->Text = L"5";
			   this->button75->UseVisualStyleBackColor = false;
			   // 
			   // button76
			   // 
			   this->button76->BackColor = System::Drawing::SystemColors::Control;
			   this->button76->CausesValidation = false;
			   this->button76->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button76->Location = System::Drawing::Point(138, 303);
			   this->button76->Margin = System::Windows::Forms::Padding(5);
			   this->button76->Name = L"button76";
			   this->button76->Size = System::Drawing::Size(80, 60);
			   this->button76->TabIndex = 18;
			   this->button76->Tag = L"8";
			   this->button76->Text = L"8";
			   this->button76->UseVisualStyleBackColor = false;
			   // 
			   // button77
			   // 
			   this->button77->BackColor = System::Drawing::SystemColors::Control;
			   this->button77->CausesValidation = false;
			   this->button77->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button77->Location = System::Drawing::Point(138, 163);
			   this->button77->Margin = System::Windows::Forms::Padding(5);
			   this->button77->Name = L"button77";
			   this->button77->Size = System::Drawing::Size(80, 60);
			   this->button77->TabIndex = 7;
			   this->button77->Tag = L"-23";
			   this->button77->Text = L"MR";
			   this->button77->UseVisualStyleBackColor = false;
			   // 
			   // button78
			   // 
			   this->button78->BackColor = System::Drawing::SystemColors::Control;
			   this->button78->CausesValidation = false;
			   this->button78->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button78->Location = System::Drawing::Point(318, 373);
			   this->button78->Margin = System::Windows::Forms::Padding(5);
			   this->button78->Name = L"button78";
			   this->button78->Size = System::Drawing::Size(80, 60);
			   this->button78->TabIndex = 25;
			   this->button78->Tag = L"102";
			   this->button78->Text = L"-";
			   this->button78->UseVisualStyleBackColor = false;
			   // 
			   // button79
			   // 
			   this->button79->BackColor = System::Drawing::SystemColors::Control;
			   this->button79->CausesValidation = false;
			   this->button79->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button79->Location = System::Drawing::Point(318, 303);
			   this->button79->Margin = System::Windows::Forms::Padding(5);
			   this->button79->Name = L"button79";
			   this->button79->Size = System::Drawing::Size(80, 60);
			   this->button79->TabIndex = 20;
			   this->button79->Tag = L"103";
			   this->button79->Text = L"*";
			   this->button79->UseVisualStyleBackColor = false;
			   // 
			   // button80
			   // 
			   this->button80->BackColor = System::Drawing::SystemColors::Control;
			   this->button80->CausesValidation = false;
			   this->button80->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button80->Location = System::Drawing::Point(48, 233);
			   this->button80->Margin = System::Windows::Forms::Padding(5);
			   this->button80->Name = L"button80";
			   this->button80->Size = System::Drawing::Size(125, 60);
			   this->button80->TabIndex = 12;
			   this->button80->Tag = L"201";
			   this->button80->Text = L"1/x";
			   this->button80->UseVisualStyleBackColor = false;
			   // 
			   // button81
			   // 
			   this->button81->BackColor = System::Drawing::SystemColors::Control;
			   this->button81->CausesValidation = false;
			   this->button81->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button81->Location = System::Drawing::Point(318, 233);
			   this->button81->Margin = System::Windows::Forms::Padding(5);
			   this->button81->Name = L"button81";
			   this->button81->Size = System::Drawing::Size(80, 60);
			   this->button81->TabIndex = 14;
			   this->button81->Tag = L"104";
			   this->button81->Text = L"/";
			   this->button81->UseVisualStyleBackColor = false;
			   // 
			   // button82
			   // 
			   this->button82->BackColor = System::Drawing::SystemColors::Control;
			   this->button82->CausesValidation = false;
			   this->button82->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button82->Location = System::Drawing::Point(48, 373);
			   this->button82->Margin = System::Windows::Forms::Padding(5);
			   this->button82->Name = L"button82";
			   this->button82->Size = System::Drawing::Size(80, 60);
			   this->button82->TabIndex = 22;
			   this->button82->Tag = L"4";
			   this->button82->Text = L"4";
			   this->button82->UseVisualStyleBackColor = false;
			   // 
			   // button83
			   // 
			   this->button83->BackColor = System::Drawing::SystemColors::Control;
			   this->button83->CausesValidation = false;
			   this->button83->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button83->Location = System::Drawing::Point(48, 303);
			   this->button83->Margin = System::Windows::Forms::Padding(5);
			   this->button83->Name = L"button83";
			   this->button83->Size = System::Drawing::Size(80, 60);
			   this->button83->TabIndex = 17;
			   this->button83->Tag = L"7";
			   this->button83->Text = L"7";
			   this->button83->UseVisualStyleBackColor = false;
			   // 
			   // button84
			   // 
			   this->button84->BackColor = System::Drawing::SystemColors::Control;
			   this->button84->CausesValidation = false;
			   this->button84->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button84->Location = System::Drawing::Point(48, 163);
			   this->button84->Margin = System::Windows::Forms::Padding(5);
			   this->button84->Name = L"button84";
			   this->button84->Size = System::Drawing::Size(80, 60);
			   this->button84->TabIndex = 6;
			   this->button84->Tag = L"-20";
			   this->button84->Text = L"MC";
			   this->button84->UseVisualStyleBackColor = false;
			   // 
			   // textBox5
			   // 
			   this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox5->CausesValidation = false;
			   this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox5->Location = System::Drawing::Point(10, 58);
			   this->textBox5->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox5->Size = System::Drawing::Size(530, 44);
			   this->textBox5->TabIndex = 2;
			   this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // textBox6
			   // 
			   this->textBox6->BackColor = System::Drawing::SystemColors::Window;
			   this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->textBox6->CausesValidation = false;
			   this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textBox6->Location = System::Drawing::Point(10, 15);
			   this->textBox6->Margin = System::Windows::Forms::Padding(5, 15, 10, 15);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->ReadOnly = true;
			   this->textBox6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->textBox6->Size = System::Drawing::Size(530, 44);
			   this->textBox6->TabIndex = 1;
			   this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // tabPage2
			   // 
			   this->tabPage2->BackColor = System::Drawing::Color::White;
			   this->tabPage2->CausesValidation = false;
			   this->tabPage2->Controls->Add(this->label1);
			   this->tabPage2->Location = System::Drawing::Point(4, 29);
			   this->tabPage2->Name = L"tabPage2";
			   this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			   this->tabPage2->Size = System::Drawing::Size(554, 633);
			   this->tabPage2->TabIndex = 5;
			   this->tabPage2->Text = L"About";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->Location = System::Drawing::Point(25, 25);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(116, 50);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"NSTU 2024\nAMI 11 5";
			   // 
			   // button85
			   // 
			   this->button85->BackColor = System::Drawing::SystemColors::Control;
			   this->button85->CausesValidation = false;
			   this->button85->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button85->Location = System::Drawing::Point(318, 513);
			   this->button85->Margin = System::Windows::Forms::Padding(5);
			   this->button85->Name = L"button85";
			   this->button85->Size = System::Drawing::Size(80, 60);
			   this->button85->TabIndex = 36;
			   this->button85->Tag = L"-12";
			   this->button85->Text = L"i";
			   this->button85->UseVisualStyleBackColor = false;
			   // 
			   // main_form
			   // 
			   this->AcceptButton = this->button32;
			   this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(558, 664);
			   this->Controls->Add(this->tabControl1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->KeyPreview = true;
			   this->MaximizeBox = false;
			   this->Name = L"main_form";
			   this->Text = L"Calculator";
			   this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &main_form::PNumbers_KeyPress);
			   this->tabPage3->ResumeLayout(false);
			   this->tabPage3->PerformLayout();
			   this->tabPage1->ResumeLayout(false);
			   this->tabPage1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			   this->tabControl1->ResumeLayout(false);
			   this->tabPage4->ResumeLayout(false);
			   this->tabPage4->PerformLayout();
			   this->tabPage2->ResumeLayout(false);
			   this->tabPage2->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion Windows Form Designer generated code

	private:
		System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e);

	private:
		System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private:
		System::Void PChanged();

	private:
		System::Void PNumbers_KeyPress(System::Object^ sender, KeyPressEventArgs^ e);

	private:
		System::Void exec_P(Int32 command);

	private:
		System::Void button_P_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		System::Void UpdateButtons();
	};
}
