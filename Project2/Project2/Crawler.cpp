#include "Crawler.h"

void Crawler::readFile(Label^ pathResult, TextBox^ finalResult, TabControl^ tabControl1)
{
	String^ fileName = pathResult->Text; //The file name as a visual C++ string
	try
	{
		if (!(fileName->Contains(".html") || //Check the file type to make sure nothing funky is going on
			!fileName->Contains(".php") ||
			!fileName->Contains(".txt")))
		{
			MessageBox::Show("Please select a .html, .php, or .txt file", "Try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else
		{
			IO::StreamReader^ reader = IO::File::OpenText(fileName); //Visual C++ IO reader
			String^ content; //The final output result
			String^ currentLine; //The current line being read
			while ((currentLine = reader->ReadLine()) != nullptr) //Read until EOF
			{
				content += currentLine + Environment::NewLine; //Concatenate the current line to the content
			}
			finalResult->Text = content; //Set the textbox to the content
			tabControl1->SelectTab(1); //Switch to the results tab
		}
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<IO::FileNotFoundException^>(e)) //File not found
			MessageBox::Show(fileName + " not found", "Try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else
			MessageBox::Show("Problem reading " + fileName, "Try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation); //Problem reading file
	}
}

/*
	Desc:		Browses the windows file directory for a .txt or .html file
	Param:		The label that will shouw the output path
*/
void Crawler::browse(Label^ pathResult)
{
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog; //Open up directory broswer
	openFileDialog1->InitialDirectory = "C:\\"; //Choose directory
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|html files (*.html)|*.html|php files (*.php)|*.php"; //Make the list of available file types to choose from
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) //Make sure 
		//the selection is successful
	{
		pathResult->Text = openFileDialog1->FileName->ToString(); //Set the label below 
						//the browsing button to the path of the selected file
	}
}