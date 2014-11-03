/*
 * parser.cpp
 *
 *  Created on: 2014-11-02
 *      Author: connor
 */
//Basic parser for now, will break up into headers and such later, just testing for now
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void searchLine(string);


int main()
{
	string line; //Will read each line of file
	ifstream input_file ("text.txt"); //Will have this read in later
	if (input_file.is_open()) //If file is found and opened
	{
		while( getline(input_file, line)) //While more lines to get, read into line
		{
			searchLine(line); //Snum_chars line to searchLine method
		}
		input_file.close(); //close file when done
	}
	else
		cout << "Could not open file\n";
	return 0;
}
//Doesn't account for multiple tags on one line
void searchLine(string line)
{
	string remaining_line = ""; //After one tag is found, will use this to keep search line for more tags until empty

	int start = line.find("<a"); //Find anchor tags position, -1 if not found
	int end = line.find("</a>") + 4; //Gives position of first character of ending tag. Add 4 to shift position to point to the end of the tag
	int num_chars = end - start; //This is how many characters from start to include in substring



	if(start != -1 && num_chars != -1) //If anchor tag is actually found
	{

		string tag = line.substr(start,num_chars); //Isolate to just anchor tag
		remaining_line = line.substr(num_chars+start); //Substring from end of closing tag to the end of the line

		start = tag.find("\""); //Find position of fist ", start of actual link
		tag = tag.substr(start+1); //Make new substring from 1 position after " to num_chars
		num_chars = tag.find("\""); //Now can find num_charsing ", since substr only returns first instance
		tag = tag.substr(0, num_chars); //Now get substring of just link, we already have the start point, go to num_chars point just found
		cout << tag << endl; //Print tag for now, will add to Queue for processing later

	}
	if(remaining_line.length()>0)
		searchLine(remaining_line);
}



