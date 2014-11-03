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
	ifstream input_file ("html.txt"); //Will have this read in later
	if (input_file.is_open()) //If file is found and opened
	{
		while( getline(input_file, line)) //While more lines to get, read into line
		{
			searchLine(line); //Send line to searchLine method
		}
		input_file.close(); //close file when done
	}
	else
		cout << "Could not open file\n";
	return 0;
}

void searchLine(string line)
{
	int start = line.find("<a"); //Find anchor tags position
	int end = line.find("</a>"); //returns -1 if not found

	if(start != -1 && end != -1) //If anchor tag is actually found
	{
		string tag = line.substr(start,end); //Isolate to just anchor tag
		start = tag.find("\""); //Find position of fist ", start of actual link
		tag = tag.substr(start+1); //Make new substring from 1 position after " to end
		end = tag.find("\""); //Now can find ending ", since substr only returns first instance
		tag = tag.substr(0, end); //Now get substring of just link, we already have the start point, go to end point just found
		cout << tag << endl; //Print tag for now, will add to Queue for processing later
	}
}



