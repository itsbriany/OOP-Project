#ifndef CRAWLER_H
#define CRAWLER_H

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;


namespace Crawler
{
	void browse(Label^ pathResult);
	void readFile(Label^ selectedFilePath, TextBox^ textBox2, TabControl^ tabControl1);
}

#endif
