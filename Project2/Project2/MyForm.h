#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^  tabPage2;
	protected:
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  folderPath;

	private: System::Windows::Forms::Label^  selectedFilePath;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;




	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->selectedFilePath = (gcnew System::Windows::Forms::Label());
			this->folderPath = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabPage2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(479, 349);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Images";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 15);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Results";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(35, 47);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(392, 265);
			this->textBox2->TabIndex = 0;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(487, 378);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->selectedFilePath);
			this->tabPage1->Controls->Add(this->folderPath);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(479, 349);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Search Tab";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// selectedFilePath
			// 
			this->selectedFilePath->AutoSize = true;
			this->selectedFilePath->Location = System::Drawing::Point(130, 84);
			this->selectedFilePath->Name = L"selectedFilePath";
			this->selectedFilePath->Size = System::Drawing::Size(93, 17);
			this->selectedFilePath->TabIndex = 4;
			this->selectedFilePath->Text = L"Select a file...";
			// 
			// folderPath
			// 
			this->folderPath->Location = System::Drawing::Point(130, 36);
			this->folderPath->Name = L"folderPath";
			this->folderPath->Size = System::Drawing::Size(190, 23);
			this->folderPath->TabIndex = 3;
			this->folderPath->Text = L"Select a file to textcrawl";
			this->folderPath->UseVisualStyleBackColor = true;
			this->folderPath->Click += gcnew System::EventHandler(this, &MyForm::folderPath_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 247);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(127, 195);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter what you want to search for";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(131, 215);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// openFileDialog1
			this->openFileDialog1->FileName = L"openFileDialog1";
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(488, 377);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {//label for search tab
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {//textbox for search tab
}
//c&p this for other future tabs
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {//textbox for images tab
	
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void folderPath_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog; //Open up directory broswer
	openFileDialog1->InitialDirectory = "C:\\"; //Choose directory
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|html files (*.html)|*.html|php files (*.php)|*.php"; //Make the list of available file types to choose from
	openFileDialog1->FilterIndex = 2; 
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) //Make sure the selection is successful
	{
		selectedFilePath->Text = openFileDialog1->FileName; //Set the label below the browsing button to the path of the selected file
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ fileName = selectedFilePath->Text; //The file name as a visual C++ string
	try
	{
		if (!(fileName->Contains(".html") || //Check the file type to make sure nothing funky is going on
			!fileName->Contains(".php") ||
			!fileName->Contains(".txt")))
		{
			textBox2->Text = "Please select a .html, .php, or .txt file";
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
			textBox2->Text = content; //Set the textbox to the content
		}
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<IO::FileNotFoundException^>(e)) //File not found
			textBox2->Text = fileName + " not found";
		else
			textBox2->Text = "Problem reading " + fileName; //Problem reading file
	}
}
};
}
