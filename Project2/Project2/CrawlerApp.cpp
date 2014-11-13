#include "MyForm.h"

using namespace System;					
using namespace System::Windows::Forms; //Makes code easier to read when using Windows
										//Froms API

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles(); //Add windows styling
	Application::SetCompatibleTextRenderingDefault(false); //Do not default the rendering 

	Project2::MyForm app; //The application
	Application::Run(%app); //Run the application
}
