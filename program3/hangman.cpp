/************************************************************
 *	File Name:		hangman.cpp                             *
 *	Author:         Michael Steets                          *
 *	Date Created:   10/23/2020                              *
 *	Date Modified:  10/26/2020                              *
 *	Purpose:  Game of Hangman								*
 ************************************************************/

#include "hangman.h"

using namespace std;

int main(){

    char yesNo;                                             //USED AT THE END TO ASK THE USER IF THEY WANT TO PLAY AGAIN
    ifstream inFile;                                           
    inFile.open("wordBank.txt");

    do {

     

        char letter;
        int stage = 0;
        char word[21];
        char underScores[21];
        char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        bool userGuesses[26] = {false};

        for (int i = 0; i < 21; ++i){
            underScores[i] = '_';
        }
        
        inFile >> word;                                     //GETS A NEW WORD FROM THE FILE
        while (!inFile){
            cout << "\nwordBank.txt cannot be open! Closing program!\n";
            return 0;
        }

        while (stage != 7){ 

            bool answerFlag = false;                        //BOOL USED TO PRINT CORRECT/WRONG ONCE
            
            printWord(word, underScores);
            printStage (stage);                
            printLettersGuessed(userGuesses, alphabet);           //USED TO PRINT GUESSED LETTERS
            
            if (stage != 6){
                cout << "WHAT LETTER DO YOU GUESS?  ";
                cin >> letter;
                letter = toupper(letter);
            
                for (int i = 0; i < strlen(alphabet); i++){         //USED TO CHECK IF THE SAME LETTER IS USED TWICE
                    if (letter == alphabet[i])                      //When we find the letter's position in the alphabet...
                    {
                        if (userGuesses[i] == true)
                        {
                            cout << "That letter has already been guessed! Please try a new letter!" << endl;       //If userGuesses was initialized at true in the else statement below
                            cout << "WHAT LETTER DO YOU GUESS?   ";                                                 //Then the it will print out that the letter has already been used
                            cin >> letter;
                            letter = toupper(letter);
                            i = 0;
                            continue;                               //Continue brings us back to the top of the for loop
                        }                      

                        else                                        //If our letter hasn't been guessed yet...
                        {
                            userGuesses[i] = true;                  //Now the game knows the letter was guessed. We can leave this loop.
                            break;
                        }
                    }
                } 

                for (int b = 0; b < strlen(word); ++b){
                    if(letter == word[b]){
                        underScores[b] = letter;

                        answerFlag = true;                          //USED TO PRINT ONLY ONE TRUE OR FALSE STATEMENT
                    }
                }

                if (answerFlag == true){
                    cout << "\n<<<<<<<<<<<<<<< CORRECT <<<<<<<<<<<<<\n" << endl;
                }
                else {
                    cout << "\n<<<<<<<<<<<<< WRONG <<<<<<<<<<<<<<<\n" << endl;
                    stage++;
                    if (stage == 6){
                        printStage(stage);
                        cout << "The word was " << word << endl;
                    }
                }
                cout << "Press ENTER to continue";
                cin.sync();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (stage == 6) {
                    break;
                }
            }
            if (strncmp(word, underScores, strlen(word)) == 0) {
                cout << "Congrats! You've won the game!\n\n";
                cout << "The word was " << word << endl << endl;
                break;
            }
        }

            bool again = true;                                         //LOOP TO ASK USER IF THEY WANT TO PLAY AGAIN
            cout << "Would you like to play again? (Y/N) ";
            while (again){
                cin >> yesNo;
                if (yesNo == 'y' || yesNo == 'Y'){
                    again = false;
                }
                else if (yesNo == 'n' || yesNo == 'N'){
                    cout << "\nGoodbye!" << endl;
                    again = false;
                }
                else if (cin.fail()){
                    cin.ignore();
                    cin.clear();
                    cout << "Enter a valid argument" << endl;
                }
                else {
                    cout << "Enter a valid argument" << endl;
                }
            }

    } while(yesNo == 'y' || yesNo == 'Y');
    
    inFile.close();
    return 0;
}