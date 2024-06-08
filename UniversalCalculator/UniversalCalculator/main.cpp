#include "main_form.h"

//int main()
//{
//	try {
//		TPNumber number1("100.00", 8);
//		TPNumber number2(number1);
//		TPNumber number3(*dynamic_cast<TPNumber*>((number1 + number2).get()));
//		TPNumber number4("100.00", 8);
//		number4 += number3;
//		std::cout << number4.to_string() << '\n';
//
//		TFracNumber number01("3|9");
//		TFracNumber number04("3|-7");
//		TFracNumber number05(*dynamic_cast<TFracNumber*>((number01 + number04).get()));
//		std::cout << number05.to_string() << '\n';
//
//		TCompNumber number02("3.14i10");
//		TCompNumber number03("3.14");
//		number02 += number03;
//		number02.inverse();
//		number02.inverse();
//		std::cout << number02.to_string() << '\n';
//
//		TMemory mem (new TCompNumber());
//		mem.add(number02);
//		std::cout << mem.read().to_string() << '\n';
//
//		TPEditor ed;
//
//		TProc proc(new TCompNumber(), new TCompNumber());
//		proc.set_Rop(number03);
//		proc.set_operation(TOperation::Add);
//		proc.exec();
//		proc.exec_func(TFunction::Sqr);
//	}
//	catch (const TException& e) {
//		std::cout << e.What();
//	}
//
//	return 0;
//}


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	calculator::main_form form;
	Application::Run(% form);
	return 0;
}
