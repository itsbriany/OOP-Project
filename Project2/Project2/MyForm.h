#pragma once

#include "Crawler.h" //include the functionalities to select the folder path
#include "parser.h" //include the functionalities of the parser

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Crawler; //use the Crawler namespace
	using namespace Parse;   //use the Parse namespace

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
	private: System::Windows::Forms::TextBox^  finalResult;





	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  browseFileButton;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  selectFileLabel;

	private: System::Windows::Forms::Button^  parseButton;
	private: System::Windows::Forms::Button^  anchorTagButton;
	private: System::Windows::Forms::Button^  imageTagButton;






	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  selectedTagLabel;

	private: System::Windows::Forms::Button^  readFileButton;
	private: System::Windows::Forms::Label^  pathResult;
	private: System::Windows::Forms::Label^  tagResult;








	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


	/*OUR PRIVATE VARIABLES*/
	private:
		Parser parser; //Initialize parser
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->finalResult = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tagResult = (gcnew System::Windows::Forms::Label());
			this->pathResult = (gcnew System::Windows::Forms::Label());
			this->selectedTagLabel = (gcnew System::Windows::Forms::Label());
			this->readFileButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->anchorTagButton = (gcnew System::Windows::Forms::Button());
			this->imageTagButton = (gcnew System::Windows::Forms::Button());
			this->parseButton = (gcnew System::Windows::Forms::Button());
			this->selectFileLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->browseFileButton = (gcnew System::Windows::Forms::Button());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabPage2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->finalResult);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
			this->tabPage2->Size = System::Drawing::Size(676, 349);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Results";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// finalResult
			// 
			this->finalResult->Location = System::Drawing::Point(35, 47);
			this->finalResult->Margin = System::Windows::Forms::Padding(4);
			this->finalResult->Multiline = true;
			this->finalResult->Name = L"finalResult";
			this->finalResult->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->finalResult->Size = System::Drawing::Size(616, 265);
			this->finalResult->TabIndex = 0;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(684, 378);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->tagResult);
			this->tabPage3->Controls->Add(this->pathResult);
			this->tabPage3->Controls->Add(this->selectedTagLabel);
			this->tabPage3->Controls->Add(this->readFileButton);
			this->tabPage3->Controls->Add(this->label5);
			this->tabPage3->Controls->Add(this->anchorTagButton);
			this->tabPage3->Controls->Add(this->imageTagButton);
			this->tabPage3->Controls->Add(this->parseButton);
			this->tabPage3->Controls->Add(this->selectFileLabel);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Controls->Add(this->browseFileButton);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(676, 349);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Parse";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tagResult
			// 
			this->tagResult->AutoSize = true;
			this->tagResult->Location = System::Drawing::Point(140, 231);
			this->tagResult->Name = L"tagResult";
			this->tagResult->Size = System::Drawing::Size(0, 17);
			this->tagResult->TabIndex = 10;
			// 
			// pathResult
			// 
			this->pathResult->AutoSize = true;
			this->pathResult->Location = System::Drawing::Point(140, 71);
			this->pathResult->Name = L"pathResult";
			this->pathResult->Size = System::Drawing::Size(0, 17);
			this->pathResult->TabIndex = 9;
			// 
			// selectedTagLabel
			// 
			this->selectedTagLabel->AutoSize = true;
			this->selectedTagLabel->Location = System::Drawing::Point(25, 231);
			this->selectedTagLabel->Name = L"selectedTagLabel";
			this->selectedTagLabel->Size = System::Drawing::Size(96, 17);
			this->selectedTagLabel->TabIndex = 8;
			this->selectedTagLabel->Text = L"Selected Tag:";
			// 
			// readFileButton
			// 
			this->readFileButton->Location = System::Drawing::Point(350, 25);
			this->readFileButton->Name = L"readFileButton";
			this->readFileButton->Size = System::Drawing::Size(113, 33);
			this->readFileButton->TabIndex = 7;
			this->readFileButton->Text = L"Read File!";
			this->readFileButton->UseVisualStyleBackColor = true;
			this->readFileButton->Click += gcnew System::EventHandler(this, &MyForm::readFileButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Select tags to filer";
			// 
			// anchorTagButton
			// 
			this->anchorTagButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
																				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->anchorTagButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->anchorTagButton->Location = System::Drawing::Point(195, 134);
			this->anchorTagButton->Name = L"anchorTagButton";
			this->anchorTagButton->Size = System::Drawing::Size(113, 33);
			this->anchorTagButton->TabIndex = 5;
			this->anchorTagButton->Text = L"anchor";
			this->anchorTagButton->UseVisualStyleBackColor = false;
			this->anchorTagButton->Click += gcnew System::EventHandler(this, &MyForm::anchorTagButton_Click);
			// 
			// imageTagButton
			// 
			this->imageTagButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
																			   static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->imageTagButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->imageTagButton->Location = System::Drawing::Point(350, 134);
			this->imageTagButton->Name = L"imageTagButton";
			this->imageTagButton->Size = System::Drawing::Size(113, 33);
			this->imageTagButton->TabIndex = 4;
			this->imageTagButton->Text = L"image";
			this->imageTagButton->UseVisualStyleBackColor = false;
			this->imageTagButton->Click += gcnew System::EventHandler(this, &MyForm::imageTagButton_Click);
			// 
			// parseButton
			// 
			this->parseButton->Location = System::Drawing::Point(27, 285);
			this->parseButton->Name = L"parseButton";
			this->parseButton->Size = System::Drawing::Size(113, 33);
			this->parseButton->TabIndex = 3;
			this->parseButton->Text = L"Parse!";
			this->parseButton->UseVisualStyleBackColor = true;
			this->parseButton->Click += gcnew System::EventHandler(this, &MyForm::parseButton_Click);
			// 
			// selectFileLabel
			// 
			this->selectFileLabel->AutoSize = true;
			this->selectFileLabel->Location = System::Drawing::Point(24, 71);
			this->selectFileLabel->Name = L"selectFileLabel";
			this->selectFileLabel->Size = System::Drawing::Size(97, 17);
			this->selectFileLabel->TabIndex = 2;
			this->selectFileLabel->Text = L"Selected File: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Select a file to parse";
			// 
			// browseFileButton
			// 
			this->browseFileButton->Location = System::Drawing::Point(195, 25);
			this->browseFileButton->Name = L"browseFileButton";
			this->browseFileButton->Size = System::Drawing::Size(113, 33);
			this->browseFileButton->TabIndex = 0;
			this->browseFileButton->Text = L"Browse...";
			this->browseFileButton->UseVisualStyleBackColor = true;
			this->browseFileButton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 379);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Crawler Application";
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	browse(pathResult); //Browse directory for a file to input
}
private: System::Void readFileButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	readFile(pathResult, finalResult, tabControl1); //Read the inputed file and output it
}

private: System::Void anchorTagButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	tagResult->Text = "anchor";
	parser.setTag("a"); //Set the parser's tag
}
private: System::Void imageTagButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	tagResult->Text = "image";
	parser.setTag("img"); //Set the parser's tag
}
private: System::Void parseButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	parser.parse(pathResult->Text, finalResult, tabControl1); //Parse the input according the
															  //parsing tag
}
};
}
