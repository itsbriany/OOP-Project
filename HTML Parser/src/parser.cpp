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

void parser(char *,string);
void parseLink(string, ostream&);
void parseIMG(string, ostream&);
string parseQuotes(string);


int main(int argc, char* argv[])
{
	parser(argv[1], argv[2]);
	return 0;
}


void parser(char *filename, string tag)
{
	ofstream output_file;	//Output file to write images to
	if (tag == "a") //determines title of output file
		output_file.open("links.txt");	//Will make file if it doesn't exist

	else //tag = "img"
		output_file.open("images.txt");


	string line; //Will read each line of file
	ifstream input_file (filename); //Will have this read in later
	if (input_file.is_open()) //If file is found and opened
	{
		while( getline(input_file, line)) //While more lines to get, read into line
		{
			if(tag == "a") //call correct parser method
				parseLink(line, output_file);
			else
				parseIMG(line, output_file);
		}
		input_file.close(); //close file when done
	}
	else
		cout << "Could not open file\n";
}

void parseLink(string line, ostream& output_file) //Reads in line to search
{
	string remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty


	int start = line.find("<a"); //Find anchor tags position, -1 if not found
	int end = line.find("</a>") + 4; //Gives position of first character of ending tag. Add 4 to shift position to point to the end of the tag
	int num_chars = end - start; //This is how many characters from start to include in substring


	if(start != -1 && end != 3) //If anchor tag is actually found. If end is not found, it would be (-1 + 4)
	{

		remaining_line = line.substr(num_chars+start); //Substring from end of closing tag to the end of the line
		string tag = line.substr(start,num_chars); //Isolate to just anchor tag
		tag = parseQuotes(tag); //Send anchor tag to get link parsed out
		output_file << tag << endl; //Print tag to the output file

	}
	if(remaining_line.length()>0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		parseLink(remaining_line, output_file);


}

void parseIMG(string line, ostream& output_file)
{
	string remaining_line = ""; //After one tag is found, will use this to keep searching line for more tags until empty

	int start = line.find("<img");
	int end = line.substr(start+1).find(">"); //Only look for close tag after <img open tag. Add one to start in case start=-1 so we dont get out of bounds error
	end+=start; //End is found based on a substring, so add the value of start to get the end location on full string
	int num_chars = end-start + 1; //How many characters to get after start point in substring

	if(start != -1 && end != -1)
	{
		//****** Parse image link like above ***********
		remaining_line = line.substr(num_chars+start-1); //Substring from end of closing tag to the end of the line
		string tag = line.substr(start, num_chars+1);

		start = tag.find("src=\""); //Find position of src in tag
		start +=4; //Move start point to first " after src
		tag = tag.substr(start+1); //Make new substring from 1 position after " to end
		num_chars = tag.find("\""); //Now can find num_charsing ", since substr only returns first instance
		string link_tag = tag.substr(0, num_chars); //Now get substring of just link, we already have the start point, go to end point just found


		//********* Parse the Alt part **************
		int alt = tag.find("alt"); //Check if alt is part of tag
		if(alt > 0)
		{
			string alt_tag = tag.substr(alt); //Parse string to just the alt component
			alt_tag = parseQuotes(alt_tag); //Send to parseQuote method to extract what's between the quotes
			link_tag += " " + alt_tag;
		}
		output_file << link_tag << endl;	//Add tag to output file

	}
	if(remaining_line.length()>0) //Recursive call, repeat above process with the remaining line after all text up to ending tag of first anchor is removed. If no anchors found, remaining_line will be empty
		parseIMG(remaining_line, output_file);
}

string parseQuotes(string line)
{
	int start = line.find("\"");
	string sub = line.substr(start+1);
	int num_chars = sub.find("\"");
	sub = sub.substr(0, num_chars);

	return sub;
}


