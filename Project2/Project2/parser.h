#ifndef PARSER_H
#define PARSER_H

#include "Crawler.h" //This way we can have Visual C++ functionalities

namespace Parse
{
	public ref class Parser  //public reference class so that other includes can be used
	{
		private:
			String^ parserTag;
		public:
			Parser();
			void parse(String^ filename, TextBox^ finalResult, TabControl^ tabControl1);
			void parseLink(String^ line, TextBox^ finalResult, TabControl^ tabControl1);
			void parseIMG(String^ line, TextBox^ finalResult, TabControl^ tabControl1);
			String^ parseQuotes(String^ line);

			/*Getters and Setters*/
			String^ getTag();
			void setTag(String^ s);
	};
}

		
#endif