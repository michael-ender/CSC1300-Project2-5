/************************************************************
 *	File Name:		program4.cpp                            *
 *	Author:         Michael Steets                          *
 *	Date Created:   11/05/2020                              *
 *	Date Modified:  11/08/2020                              *
 *	Purpose:  Game of MADLIBS								*
 ************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int showMenuGetChoice (int choose);
string* createStringArray(int arraySize);
string* getInfoFromUser(int arraySize, string* userQuestions, string* userOptions, ifstream& text, string line);
void printStory(ifstream& inFile2, string* userChoices, int arraySize, string lines);

int main() {


	ifstream inFile;
	ifstream inFile2;
	int arraySize;
	string line;
	string lines;
	int choose = 0;

	do{

		switch(showMenuGetChoice(choose)) {										//The showMenuGetChoice function is embedded inside of the switch statement
			case 1:																//to save the most space
				{
				inFile.open("starWars.txt");
				inFile2.open("starwarsText.txt");
				if(!inFile){													//Checking to see if the file exists
					cout << "\nI am unable to open the file data for starWars";
					return 0;
				}
				if(!inFile2){
					cout << "\nI am unable to open the file data for starwarsText";
					return 0;
				}
				inFile >> arraySize;
				inFile.ignore();

				string* userOptions = createStringArray(arraySize);				//Creates a string function to put in the questions from the text files
				string* userChoices = createStringArray(arraySize);				//and creates another string function to put in the answers to the questions
																				//this was made for each case except 4 and default
				cout << "\n\nPlease give a response for each request.\n\n";

				getInfoFromUser(arraySize, userOptions, userChoices, inFile, line);		//This is where the user would input their answers for the questions
				cout << endl;
				printStory(inFile2, userChoices, arraySize, lines);						//Where the story would be printed with the answers from the questions
				cout << endl << endl;													//These two were also put on each case except 4 and default

				inFile.close();															//Closes the files incase the user wants to play the same MadLibs again
				inFile2.close();														//or play a different MadLibs

				delete [] userOptions;													//Deletes the question and answer array so there's no memory overlap
				delete [] userChoices;
		
				}
				break;
			case 2: 
				{
				inFile.open("dog.txt");
				inFile2.open("dogText.txt");
				inFile >> arraySize;
				inFile.ignore();
				if(!inFile){													//Checking to see if the file exists
					cout << "\nI am unable to open the file data for dog";
					return 0;
				}
				if(!inFile2){
					cout << "\nI am unable to open the file data for dogText";
					return 0;
				}				

				string* userOptions2 = createStringArray(arraySize);
				string* userChoices2 = createStringArray(arraySize);

				cout << "\n\nPlease give a response for each request.\n\n";

				getInfoFromUser(arraySize, userOptions2, userChoices2, inFile, line);
				cout << endl;
				printStory(inFile2, userChoices2, arraySize, lines);
				cout << endl << endl;

				inFile.close();
				inFile2.close();				

				delete [] userOptions2;
				delete [] userChoices2;
			
				}
				break;
			case 3:
				{
				inFile.open("pirate.txt");
				inFile2.open("pirateText.txt");
				inFile >> arraySize;
				inFile.ignore();
				if(!inFile){													//Checking to see if the file exists
					cout << "\nI am unable to open the file data for pirate";
					return 0;
				}
				if(!inFile2){
					cout << "\nI am unable to open the file data for pirateText";
					return 0;
				}				

				string* userOptions3 = createStringArray(arraySize);
				string* userChoices3 = createStringArray(arraySize);

				cout << "\n\nPlease give a response for each request.\n\n";

				getInfoFromUser(arraySize, userOptions3, userChoices3, inFile, line);
				cout << endl;
				printStory(inFile2, userChoices3, arraySize, lines);
				cout << endl << endl;

				inFile.close();
				inFile2.close();

				delete [] userOptions3;
				delete [] userChoices3;
				
				}
				break;
			case 4:
				cout << "\nAlrightie well bye\n";
				return 0;
			default:
				cout << "\n\n***ENTER A VALID NUMBER***\n\n";
				break;
		}

	}while(choose != 4);

	return 0;
}

int showMenuGetChoice (int choose){												//Function where the user picks which MadLibs they want to play 
	cout << "Let's Play some MADLIBS!!" << endl << endl;						//or to end the program
	cout << "Choose a MAD LIBS game:" << endl;
	cout << "1.	The Power of the Force (Star Wars Mad Libs)" << endl;
	cout << "2.	Dog Days (Dog Ate My Mad Libs)" << endl;
	cout << "3.	Talk Like a Pirate (Pirates Mad Libs)" << endl;
	cout << "4.	END GAME" << endl;
	cout << "\nCHOOSE 1-4:	";
	
	bool choice = true;
	cin >> choose;
	while(choice){
		
		if (cin.fail()){														//Authenticates user input
			cin.clear();
			cin.ignore();
			cout << "\nEnter in a number between 1 - 4:";
			cin >> choose;
		}
		else {
			choice = false;
		}
	}

	return choose;
}

string* createStringArray(int arraySize){										//Function that creates a blank array for questions and answers
	string* array = new string[arraySize];
	return array;
}

string* getInfoFromUser(int arraySize, string* userQuestions, string* userChoices, ifstream& text, string line){	//Where the user input would take place
	for (int i = 0; i < arraySize; ++i){
		if(text){
			getline(text, line);
			userQuestions[i] = line;
			cout << userQuestions[i] << ":	";
			cin >> userChoices[i];
		}
	}
	return userChoices;
}

void printStory(ifstream& inFile2, string *userChoices, int arraySize, string lines){	//Where the story would be printed along side of the answers to
	for(int z = 0; z <= arraySize; ++z){												//be put where needed
		getline(inFile2, lines);
		cout << lines;
		if (z < arraySize){
			cout << userChoices[z];
		}	
	}
}