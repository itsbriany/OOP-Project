#include "SimpleCalculator.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ args)
{
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);

CalculatorExample::SimpleCalculator simpleCalculatorForm;
Application::Run(%simpleCalculatorForm);
}