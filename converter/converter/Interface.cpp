#include <iostream>
#include "Interface.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	try {
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		converter::Interface form;
		Application::Run(% form);
	}
	catch (System::String^ err) {
		Console::WriteLine(err);
		return 1;
	}
	return 0;
}