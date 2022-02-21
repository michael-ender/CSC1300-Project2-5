/***************************************************
 * File Name:								item.h *
 * Author:							Michael Steets *
 * Date Created:						11/16/2020 *
 * Date Modified:						11/30/2020 *
 * Purpose:		   Header file for Inventory Check *
 * *************************************************/

#ifndef _ITEM
#define _ITEM

#include <iostream>
#include <fstream>

using namespace std;

struct Item {                           //STRUCTURE FOR ITEM VARIABLES
	string item;
	string description;
	double cost;
	int numStores;
	string *storeNames;
	string createDate;
};

struct Money {                          //STRUCTURE FOR MONEY VARIABLES
	float rawPrice;
	float salePrice;
	float profit;
};

//function prototypes 
int menu(int menu2);
void addItems(Item* array, Money* array2, int& upToMax);
void printItems(Item* array, Money* array2, int& upToMax);

#endif