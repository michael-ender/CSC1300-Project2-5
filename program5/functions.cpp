/*******************************************
 * File Name:			     functions.cpp *
 * Author:			        Michael Steets *
 * Date Created:		        11/16/2020 *
 * Date Modified:		        11/30/2020 *
 * Purpose:		  Inventory Check Functions*
 * *****************************************/

#include "item.h"

int menu (int menu2) {											//READS IN THE OPTIONS WITH USER INPUT
	cout << "\nDo you want to...." << endl;
	cout << "1. Add items from a file?" << endl;
	cout << "2. Add one item manually?" << endl;
	cout << "3. Return to main menu?" << endl;
	cout << "\nCHOOSE 1-3: ";
	while (menu2 < 1 || menu2 > 3){
		cin >> menu2;
		if (menu2 < 1 || menu2 > 3){
			cout << "\nEnter in a valid number (1-3)" << endl;
		}
	}

	return menu2;
}

void addItems (Item* array, Money* array2, int& upToMax){		//FUNCTION TO ADD ITEMS MANUALLY TO THE INVENTORY
	cout << "\nPlease enter the item details below:\n\n";
	cout << "NAME: ";
	cin.ignore();
	getline (cin, array[upToMax].item);
	cout << "\nDESCRIPTION: ";
	getline (cin, array[upToMax].description);
	cout << "\nRAW MATERIALS COST (cost to make item):  $";
	cin >> array2[upToMax].rawPrice;
	cout << "\nSALE PRICE (price when you sell item):  $";
	cin >> array2[upToMax].salePrice;
	array2[upToMax].profit = array2[upToMax].salePrice - array2[upToMax].rawPrice;
	cout << "\nENTER THE NUMBER OF STORES THAT SUPPLY THIS ITEM." << endl;
	cin >> array[upToMax].numStores;
	cin.ignore();

	array[upToMax].storeNames = new string[array[upToMax].numStores];

	for (int i = 0; i < array[upToMax].numStores; ++i){
		cout << "\nSTORE " << i + 1 << " NAME:  ";
		getline(cin, array[upToMax].storeNames[i]);
	}
	cout << "\nCREATION DATE (example:  04 02 16)" << endl;
	getline(cin, array[upToMax].createDate);
	cout << endl;
}

void printItems(Item* array, Money* array2, int& upToMax){			//PRINTS ALL ITEMS IN THE INVENTORY
	cout << "ALL ITEMS:\n\n";
	for (int i = 0; i < upToMax; ++i){
		cout << "------------------------------------------------------------------" << endl;
		cout << "                                                          	 ITEM " << i + 1 << endl;
		cout << "NAME:	" << array[i].item;
		cout << "\n\nDESCRIPTION:	" << array[i].description;
		cout << "\n\nGOODS PRICE:	$" << array2[i].rawPrice;
		cout << "\n\nSALE PRICE:	$" << array2[i].salePrice;
		cout << "\n\nPROFIT:	$" << array2[i].profit;
		cout << "\n\nSTORES WHO SALE THIS ITEM:";
		for (int x = 0; x < array[i].numStores; ++x){
			cout << "\n" << "	STORE " << x + 1 << " NAME: " << array[i].storeNames[x];
		}
		cout << "\n\nCREATION DATE:	" << array[i].createDate << endl;
	}
}