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

void searchLine(string, string);
void parseIMG(string);


int main()
{
	string line; //Will read each line of file
	ifstream input_file ("text.txt"); //Will have this read in later
	if (input_file.is_open()) //If file is found and opened
	{
		while( getline(input_file, line)) //While more lines to get, read into line
		{
			//searchLine(line, "a"); //Send each line to searchLine method
			parseIMG(line);
		}
		input_file.close(); //close file when done
	}
	else
		cout << "Could not open file\n";
	return 0;
}

//To add: detect input char and use appropriate searching method. img parser will search for different criteria than a link
void searchLine(string line, string key) //Reads in line to search and which tag to search for, i.e. 'a' for link, 'img' for image
{

	string open_tag = "<" + key;
	string close_tag = "</" + key + ">";

	string remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty

	int start = line.find(open_tag); //Find anchor tags position, -1 if not found
	int end = line.find(close_tag) + 4; //Gives position of first character of ending tag. Add 4 to shift position to point to the end of the tag
	int num_chars = end - start; //This is how many characters from start to include in substring

	//substr(int,int) does not take in start and end pos. Takes in start pos, and the number of characters to include from the start position


	if(start != -1 && end != 3) //If anchor tag is actually found. If end is not found, it would be (-1 + 4)
	{

		remaining_line = line.substr(num_chars+start); //Substring from end of closing tag to the end of the line

		string tag = line.substr(start,num_chars); //Isolate to just anchor tag
		start = tag.find("\""); //Find position of fist ", start of actual link
		tag = tag.substr(start+1); //Make new substring from 1 position after " to num_chars
		num_chars = tag.find("\""); //Now can find num_charsing ", since substr only returns first instance
		tag = tag.substr(0, num_chars); //Now get substring of just link, we already have the start point, go to num_chars point just found
		cout << tag << endl; //Print tag for now, will add to Queue for processing later

	}
	if(remaining_line.length()>0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		searchLine(remaining_line, key);

}

void parseIMG(string line)
{
	string remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty

	int start = line.find("<img");
	int end = line.find(">");
	int num_chars = end-start + 1;

	if(start != -1 && end != -1)
	{
		remaining_line = line.substr(num_chars+start); //Substring from end of closing tag to the end of the line

		string tag = line.substr(start, num_chars);

		start = tag.find("\""); //Find position of fist ", start of actual link
		tag = tag.substr(start+1); //Make new substring from 1 position after " to num_chars
		num_chars = tag.find("\""); //Now can find num_charsing ", since substr only returns first instance
		tag = tag.substr(0, num_chars); //Now get substring of just link, we already have the start point, go to end point just found
		cout << tag << endl; //Print tag for now, will add to Queue for processing later

	}
	if(remaining_line.length()>0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		parseIMG(remaining_line);
}



