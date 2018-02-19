/* 
 *Name: Nathaniel Dore
 *Class: CSCI 2421
 *Description: A fun filled ADT class called ArrayBag. I have added operator overloads and a function to parse file input. 
 *Lab Partner: N/A
 *Status: development complete: final release build 
 */

#include "ArrayBag.h"

using namespace std;

//function definitions

//this is about to get crazy... dynamically parses correctly formated data from input.dat into a list of bags
vector<ArrayBag> parseInputIntoBags();

int main( )
{
	vector<ArrayBag> bagList;
	ArrayBag bagOfInt1, bagOfInt2, bagOfInt3;
	
	bagList = parseInputIntoBags();

	bagOfInt1 = bagList[0];
	bagOfInt2 = bagList[1];

	bagOfInt3 = (bagOfInt1 + bagOfInt2);

    return 0;
}

//function definitions
vector<ArrayBag>  parseInputIntoBags()
{
	ifstream fin;
	vector< vector<int> > MatrixOfInt;
	vector< vector<string> > MatrixOfStr;
	vector<string> listOfLines, tempStrVector;
	vector<int> tempIntVector;
	vector<ArrayBag> bagList;
	ArrayBag tempBag;
	int numberOfLines = 0, nextInt = 0;
	char nextChar;

	//opening input file
	fin.open("input.dat");
	if (fin.fail())
	{
		cout << "error connecting instream to input file. \n";
	}

	//collecting data
	std::ifstream file("input.dat");

	if (file)
	{
		stringstream buffer;

		buffer << file.rdbuf();

		file.close();

		// operations on the buffer...
		
		//seperating the input into a vector list w/ each line an element.
		string s;
		s = buffer.str();
		string delimiter = "\n";

		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos)
		{
			token = s.substr(0, pos);
			listOfLines.push_back(token);
			s.erase(0, pos + delimiter.length());
		}

		//sperating the vector list of lines into a vector list of individual numbers
		for (int i = 0; i < listOfLines.size(); i++)
		{
			string s = listOfLines[i];
			string delimiter = " ";

			size_t pos = 0;
			string token;
			tempStrVector.clear();
			while ((pos = s.find(delimiter)) != string::npos)
			{
				token = s.substr(0, pos);
				tempStrVector.push_back(token);
				s.erase(0, pos + delimiter.length());
			}
			MatrixOfStr.push_back(tempStrVector);
		}

	}
	
	//converting the string matrix into an int matrix

	for (int i = 0; i < MatrixOfStr.size(); i++)
	{
		for (int n = 0; n < MatrixOfStr[i].size(); n++)
		{
			tempIntVector.push_back(stoi(MatrixOfStr[i][n]));
		}
		MatrixOfInt.push_back(tempIntVector);
	}

	//parse matrix of ints into bags
	for (int i = 0; i < MatrixOfInt.size(); i++)
	{
		tempBag.clear();
		tempBag.addList(MatrixOfInt[i]);
		bagList.push_back(tempBag);
	}

	return bagList;
}




