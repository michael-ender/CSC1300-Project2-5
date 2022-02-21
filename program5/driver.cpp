/***********************************
 * File Name:			driver.cpp *
 * Author:			Michael Steets *
 * Date Created:		11/16/2020 *
 * Date Modified:		11/30/2020 *
 * Purpose:		   Inventory Check *
 * *********************************/

#include "item.h"

int main() {

	ifstream inFile;
	ofstream outFile;
	int maxNum;
	int menu_;
	int menu2 = 0;
	int upToMax = 0;
	string temp;
	int numOfLoops = 0;
	string path;

	cout << "GEEK FACTORY" << endl;
	cout << "\nWhat is the maximum number of items your factory can hold?" << endl;
	cin >> maxNum;																				//ASKS THE USER THE CAPACITY OF THE INVENTORY
	while (maxNum < 1){
		cout << "\nThe number of items has to be greater than 0" << endl;
		cout << "\nWhat is the maximum number of items your factor can hold?" << endl;
		cin >> maxNum;
	}

	Item* array = new Item[maxNum];																//CREATES ON ARRAY OF THE ITEM STRUCT
	Money* array2 = new Money[maxNum];															//CREATES ON ARRAY OF THE MONEY STRUCT

	while (menu_ != 3){

		bool menuTrue = true;
		while (menuTrue){
			cout << "\nPlease choose from the following options:" << endl;						//THE BEGINNING OF THE PROGRAM THAT ASKS THE USER WHAT THEY WOULD LIKE TO DO
			cout << "1.	Add awesome item(s)." << endl;
			cout << "2.	Print all items." << endl;
			cout << "3.	End the program." << endl;
			cout << "\nCHOOSE 1-3:	";
			cin >> menu_;
			cin.ignore();
			if (menu_ > 3 || menu_ < 1){
				cout << "\n****Enter in a number between 1 - 3****\n";
			}
			else {
				menuTrue = false;
			}
		}


		switch (menu_) {
			case 1:
				switch (menu(menu2)) {
					case 1:
						cout << "\n\nWhat is the name of the file that contains your inventory items?\n";
						cin >> path;
						inFile.open(path.c_str());
						if(!inFile){
							cout << "\nI am unable to open the file data\n";
							break;
						}
						if (upToMax >= maxNum){
							cout << "\n\nOOPS! There's no more space for items!\n";
						}
						else {
							while (!inFile.eof() || upToMax > maxNum){					//READS IN ALL THE ITEMS IN THE TEXT FILE
								getline(inFile, temp, '#');
								array[upToMax].item = temp;
								getline(inFile, temp, '#');
								array[upToMax].description = temp;
								getline(inFile, temp, '#');
								array2[upToMax].rawPrice = std::stof(temp);
								getline(inFile, temp, '#');
								array2[upToMax].salePrice = std::stof(temp);
								getline(inFile, temp, '#');
								array2[upToMax].profit = std::stof(temp);
								getline(inFile, temp, '#');
								array[upToMax].numStores = std::stoi(temp);

								array[upToMax].storeNames = new string[array[upToMax].numStores];

								for(int i = 0; i < array[upToMax].numStores; ++i){
									getline(inFile, temp, '#');
									array[upToMax].storeNames[i] = temp;
								}
								
								getline(inFile, temp, '#');
								array[upToMax].createDate = temp;

								++numOfLoops;			//KEEPS TRACK OF HOW MANY ITEMS ARE PUT INTO THE INVENTORY
								++upToMax;				//KEEPS TRACK OF HOW MANY OPEN SPACES ARE AVAILABLE FOR ITEMS
								if (upToMax >= maxNum){
									break;
								}
							}
						}

						cout << "\n\n" << numOfLoops << " items were found\n\n";

						break;
					case 2:
						if (upToMax >= maxNum){
							cout << "\n\nOOPS! There's no more space for items!\n";
						}
						else {
							addItems(array, array2, upToMax);
						}	
						++upToMax;					
						break;
					case 3:
						cout << "\nReturning to Menu\n";
						break;
				}
				break;
			case 2:
				if (upToMax == 0){
					cout << "\nThere are no items to print\n";						//PRINTS NOTHING IF upToMax is 0
					break;
				}
				else {
					printItems(array, array2, upToMax);
				}
				break;
			case 3:
				if (upToMax == 0){
					cout << "\nThere are no items to save to a file.";
				}
				else {
					cout << "What would you like to name your inventory file? (example.txt)\n";
					cin >> path;
					cin.ignore();
					outFile.open(path.c_str());										//NAMES THE FILE TO PUT THE INVENTORY INTO
					cout << "ALL ITEMS:\n\n";
					for (int i = 0; i < upToMax; ++i){					
						outFile << "------------------------------------------------------------------" << endl;
						outFile << "                                                          	 ITEM " << i + 1 << endl;
						outFile << "NAME:	" << array[i].item;
						outFile << "\n\nDESCRIPTION:	" << array[i].description;
						outFile << "\n\nGOODS PRICE:	$" << array2[i].rawPrice;
						outFile << "\n\nSALE PRICE:	$" << array2[i].salePrice;
						outFile << "\n\nPROFIT:	$" << array2[i].profit;
						outFile << "\n\nSTORES WHO SALE THIS ITEM:";
						for (int x = 0; x < array[i].numStores; ++x){
							outFile << "\n" << "	STORE " << x + 1 << " NAME: " << array[i].storeNames[x];
						}
						outFile << "\n\nCREATION DATE:	" << array[i].createDate << endl;						
					}
					cout << "\nAll your weird items have been saved to " << path << ".\n";
				}
				cout << "\nGoodbye!";
				outFile.close();
				return 0;
			default:
				cout << "\nhow did you get here?\n";
				return 0;
		}
	}

	for (int i = 0; i < upToMax; i++){								//DELETES THE POINTER ARRAY SO THERE'S NO MEMORY CRASHING
		delete [] array[i].storeNames;
	}

	delete [] array;
	delete [] array2;

	inFile.close();

	return 0;
}
