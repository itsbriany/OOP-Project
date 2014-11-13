/*
 * parser.cpp
 *
 *  Created on: 2014-11-02
 *      Author: connor (logic), brian (translation to Visual C++) 
 *
 */

#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
using namespace Parse;

/*Constructor initializing the variables*/
Parse::Parser::Parser()
{
	parserTag = "";
}

/*
	Param:		The filename of the file to be parsed
				The tag that we want to parse
*/
void Parse::Parser::parse(String^ filename, TextBox^ finalResult, TabControl^ tabControl1)
{
	if (parserTag == "")
	{
		MessageBox::Show("Please select a tag!", "Please try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	else
	{
		finalResult->Text = "";
		String^ line; //Will read each line of file
		try
		{
			IO::StreamReader^ sr = IO::File::OpenText(filename); //Create a new StreamReader and open the file
			while ((line = sr->ReadLine()) != nullptr) //While more lines to get, read into line
			{
				if (parserTag == "a") //call correct parser method
					parseLink(line, finalResult, tabControl1);
				else
					parseIMG(line, finalResult, tabControl1);
			}
		}
		catch (Exception^ e)
		{
			if (filename == "")
			{
				MessageBox::Show("No file selected", "Please try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else
			{
				MessageBox::Show("Could not open file", "Please try again", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
		}
	}		
}

/*
	Param:		The line to parse
				The StreamWriter to write to its given file
*/
void Parse::Parser::parseLink(String^ line, TextBox^ finalResult, TabControl^ tabControl1) //Reads in line to search
{
	String^ remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty

	int start = line->IndexOf("<a"); //Find anchor tags position, -1 if not found
	int end = line->IndexOf("</a>") + 4; //Gives position of first character of ending tag. Add 4 to shift position to point to the end of the tag
	int num_chars = end - start; //This is how many characters from start to include in substring


	if(start != -1 && end != 3) //If anchor tag is actually found. If end is not found, it would be (-1 + 4)
	{

		remaining_line = line->Substring(num_chars+start); //Substring from end of closing tag to the end of the line
		String^ tag = line->Substring(start,num_chars); //Isolate to just anchor tag
		tag = parseQuotes(tag); //Send anchor tag to get link parsed out
		finalResult->Text += tag + Environment::NewLine; //Print tag to the output file
		tabControl1->SelectTab(1); //Switch to the results tab
	}
	if(remaining_line->Length > 0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		parseLink(remaining_line, finalResult, tabControl1);


}

void Parse::Parser::parseIMG(String^ line, TextBox^ finalResult, TabControl^ tabControl1)
{
	String^ remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty
	
	int start = line->IndexOf("<img");
	int end = line->Substring(start+1)->IndexOf(">"); //Only look for close tag after <img open tag. Add one to start in case start=-1 so we dont get out of bounds error
	end+=start; //End is found based on a substring, so add the value of start to get the end location on full string
	int num_chars = end-start + 1; //How many characters to get after start point in substring

	if(start != -1 && end != -1)
	{
		//****** Parse image link like above ***********
		remaining_line = line->Substring(num_chars+start-1); //Substring from end of closing tag to the end of the line
		String^ tag = line->Substring(start, num_chars+1);

		start = tag->IndexOf("src=\""); //Find position of src in tag
		start +=4; //Move start point to first " after src
		tag = tag->Substring(start+1); //Make new substring from 1 position after " to end
		num_chars = tag->IndexOf("\""); //Now can find num_charsing ", since substr only returns first instance
		String^ link_tag = tag->Substring(0, num_chars); //Now get substring of just link, we already have the start point, go to end point just found


		//********* Parse the Alt part **************
		int alt = tag->IndexOf("alt"); //Check if alt is part of tag
		if(alt > 0)
		{
			String^ alt_tag = tag->Substring(alt); //Parse string to just the alt component
			alt_tag = parseQuotes(alt_tag); //Send to parseQuote method to extract what's between the quotes
			link_tag += " " + alt_tag;
		}
		finalResult->Text += link_tag + Environment::NewLine; //Add tag to output
		tabControl1->SelectTab(1); //Switch to the results tab
	}
	if(remaining_line->Length > 0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		parseIMG(remaining_line, finalResult, tabControl1);
}

String^ Parse::Parser::parseQuotes(String^ line)
{
	int start = line->IndexOf("\"");
	String^ sub = line->Substring(start+1);
	int num_chars = sub->IndexOf("\"");
	if (num_chars >= 0)
	{
		sub = sub->Substring(0, num_chars);
		return sub;
	}

	return "";
}

String^ Parse::Parser::getTag()
{
	return parserTag;
}

void Parse::Parser::setTag(String^ s)
{
	parserTag = s;
}


