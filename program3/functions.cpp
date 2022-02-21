/************************************************************
 *	File Name:		functions.cpp                           *
 *	Author:         Michael Steets                          *
 *	Date Created:   10/23/2020                              *
 *	Date Modified:  10/26/2020                              *
 *	Purpose:  Game of Hangman functions						*
 ************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

void printWord(char word[], char underScores[]){										//FUNCTION FOR PRINTING THE BLANK WORD WITH UNDERSCORES
	cout << "\n****************************************" << endl;
	cout << "WORD: ";

	for (int i = 0; i < strlen(word); ++i) {
		cout << underScores[i] << " ";
	}
	cout << endl << endl;
	return;
}

void printLettersGuessed(bool userGuesses[], char alphabet[]){							//FUNCTION FOR PRINTING OUT THE LETTERS ALREADY GUESSED
	cout << "LETTERS YOU HAVE ALREADY GUESSED: ";
	for (int y = 0; y < strlen(alphabet); ++y){
		if (userGuesses[y] == true){
			cout << alphabet[y] << " ";
		}
	}

	cout << endl << endl;
}

/*	FUNCTION:  printStage
	This function prints out the diagram representing each
	stage of the game.  There are seven different diagrams.
*/
void printStage(int stage)
{
	switch(stage)
	{	
		case 0:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;
		
		case 1:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 2:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 3:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 4:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 5:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |      \\      \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 6:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |    / \\      \n";
					cout << "     |              \n";
					cout << "     |   DEAD!      \n";
					cout << "  --------------    \n";
					break;	
	}
	cout << "\n\n";
}