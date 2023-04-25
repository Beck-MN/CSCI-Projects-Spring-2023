/*
@problem Spellchecker program for project 4
@author Beck Christensen
@starID rg6291gh
@duedate 3/2/2023
@instructor Jie Meichsner 
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <string>
#include <iterator>

//Use namespace

using namespace std;

//Define main

int main()

{

//Open file

fstream dictFile("dict.txt", ios::in);

//Create dictionary

set<string> dict;

//Define iterator

set<string>::iterator itr;

//Define string

string word = "";

//Read word

getline(dictFile, word);

//Loop

while (word.length() > 0)

{

//Call method

transform(word.begin(), word.end(), word.begin(), ::tolower);

//Add words

dict.insert(word);

//Make word empty

word = "";

//Get next word

getline(dictFile, word);

}

//Close file

dictFile.close();

//Define file name

const char* inputFileName = "myReport.txt";

//Open file

fstream inputFile(inputFileName, ios::in);

//If file not open

if (!inputFile.is_open())

{

//Display message

cout << "Input File could not be opened" << endl;

}

//Otherwise

else

{

//Assign value

word = "";

//Read

getline(inputFile, word);

//Display message

cout<<"The following words in file 'myReport.txt' are not spelled correctly"<<endl;

//Loop

while (word.length() > 0)

{

//Find

itr = dict.find(word);

//If value matches

if (itr == dict.end())

{

//Display word

cout << word << endl;

}

//Assign word

word = "";

//Get next word

getline(inputFile, word);

}

//Close

inputFile.close();

}


return 0;

}