#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	//Beginning statement
	cout << "Pick from the following menu: " << endl;
	cout << "1. Let's play MASH!" << endl;
	cout << "2. End program." << endl;
	//Variables for the beginning while loop
	bool mashTheGame = true;
	bool again = true;
	int choose12;
	cin >> choose12;
	while (again){		
		if (choose12 == 1){
			again = false;
			cout << "\nYou chose to play MASH!\n" << endl;
			}
		else if (choose12 == 2){
			again = false;
			cout << "You chose to end the program. \nBye!";
			mashTheGame = false;
		}
		else if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid choice. Select 1 or 2." << endl;
			cin >> choose12;
		}
		else {
			cout << "Invalid choice. Select 1 or 2." << endl;
			cin >> choose12;
		}
	}

	
	while (mashTheGame){
	//Random number setup
	int randomNum;
	srand(time(0));

	//M.A.S.H. portion
	string mash;
	bool mashLoop = true;
	while (mashLoop){
		randomNum = rand() % 4 + 1;
		if (randomNum == 1){
			mash = "in a mansion";
			mashLoop = false;
		}
		else if (randomNum == 2){
			mash = "in an partment";
			mashLoop = false;
		}
		else if (randomNum == 3){
			mash = "in a shack";
			mashLoop = false;
		}
		else {
			mash = "in a house";
			mashLoop = false;
		}		
	}
	
	//Person 1, 2 and 3
	string p1, p2, p3;
	cout << "Enter in one person you like: ";
	cin.ignore();
	getline(cin, p1);
	cout << "Enter in another person you like: ";
	getline(cin, p2);
	cout << "Enter in a person you hate: ";
	getline(cin, p3);
	cout << endl;

	//PERSON CALCULATIONS
	bool mashLoop2 = true;
	string person;
	while (mashLoop2){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			person = p1;
			mashLoop2 = false;
		}
		else if (randomNum == 2){
			person = p2;
			mashLoop2 = false;
		}
		else {
			person = p3;
			mashLoop2 = false;
		}
	}

	//CHILDREN USER INPUT
	int child1, child2, child3;
	bool childA = true;
	bool childB = true;
	bool childC = true;
	cout << "Enter three numbers between 1 and 100, separated by a space." << endl;
	cin >> child1;
	while (childA) {												//USER VALIDATION FOR CHILD1
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid argument for number 1." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child1;
		}
		else if (child1 < 1 || child1 > 100){
			cout << "The first number you entered was invalid." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child1;
		}
		else 
			childA = false;
	}	

	cin >> child2;
	while (childB) {												//USER VALIDATION FOR CHILD2
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid argument for number 2." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child2;
		}
		else if (child2 < 1 || child2 > 100){
			cout << "The second number you entered was invalid." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child2;
		}
		else 
			childB = false;
	}

	cin >> child3;
	while (childC) {												//USER VALIDATION FOR CHILD3
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid argument for number 3." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child3;
		}
		else if (child3 < 1 || child3 > 100) {
			cout << "The third number you entered was invalid." << endl;
			cout << "Please enter a number between 1 and 100." << endl;
			cin >> child3;
		}
		else 
			childC = false;
	}
	cout << endl;

	//CHILD CALCULATION
	bool mashLoop3 = true;
	int children;
	while (mashLoop3){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			children = child1;
			mashLoop3 = false;
		}
		else if (randomNum == 2){
			children = child2;
			mashLoop3 = false;
		}
		else {
			children = child3;
			mashLoop3 = false;
		}
	}

	//CITY AND STATE
	string cs1, cs2, cs3;
	cout << "Enter in one city, state you like: ";
	cin.ignore();
	getline(cin, cs1);
	cout << "Enter in another city, state you like: ";
	getline(cin, cs2);
	cout << "Enter in one city, state you hate: ";
	getline(cin, cs3);
	cout << endl;

	//CITY STATE CALCULATIONS
	string cityState;
	bool mashLoop4 = true;
	while (mashLoop4){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			cityState = cs1;
			mashLoop4 = false;
		}
		else if (randomNum == 2){
			cityState = cs2;
			mashLoop4 = false;
		}
		else {
			cityState = cs3;
			mashLoop4 = false;
		}
	}

	//OCCUPATION INPUT
	string oc1, oc2, oc3;
	cout << "Enter a company or restaurant you like: ";
	getline (cin, oc1);
	cout << "Enter another company or restaurant you like: ";
	getline (cin, oc2);
	cout << "Enter a company or restaurant you hate: ";
	getline (cin, oc3);
	cout << endl;

	//OCCUPATION CALCULATIONS
	string occupation;
	bool mashLoop5 = true;
	while (mashLoop5){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			occupation = oc1;
			mashLoop5 = false;
		}
		else if (randomNum == 2){
			occupation = oc2;
			mashLoop5 = false;
		}
		else {
			occupation = oc3;
			mashLoop5 = false;
		}
	}

	//SALARY INPUT
	int sal1, sal2, sal3;
	bool salA = true;
	bool salB = true;
	bool salC = true;
	cout << "Enter three numbers between 10,000 and 500,000, separated by a space." << endl;
	cin >> sal1;
	while (salA) {													//VALIDATION FOR SAL1
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "The first number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal1;
		}
		else if (sal1 < 10000 || sal1 > 500000){
			cout << "The first number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal1;
		}
		else 
			salA = false;
	}
	
	cin >> sal2;
	while (salB) {												//VALIDATION FOR SAL2
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "The second number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal2;
		}
		else if (sal2 < 10000 || sal2 > 500000){
			cout << "The second number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal2;
		}
		else 
			salB = false;
	}

	cin >> sal3;
	while (salC) {												//USER VALIDATION FOR SAL3
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "The third number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal3;
		}
		else if (sal3 < 10000 || sal3 > 500000){
			cout << "The third number you entered was invalid." << endl;
			cout << "Please enter a number between 10000 and 500000." << endl;
			cin >> sal3;
		}
		else 
			salC = false;
	}
	cout << endl;

	//SALARY CALCULATIONS
	int salary;
	bool mashLoop6 = true;
	while (mashLoop6){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			salary = sal1;
			mashLoop6 = false;
		}
		else if (randomNum == 2){
			salary = sal2;
			mashLoop6 = false;
		}
		else {
			salary = sal3;
			mashLoop6 = false;
		}
	}

	//CARS USER INPUT
	string car1, car2, car3;
	cout << "Enter in a car that you like: ";
	cin.ignore();
	getline(cin, car1);
	cout << "Enter in another car that you like: ";
	getline(cin, car2);
	cout << "Enter in a car that you hate: ";
	getline(cin, car3);
	cout << endl;

	//CAR CALCULATIONS
	string car;
	bool mashLoop7 = true;
	while (mashLoop7){
		randomNum = rand() % 3 + 1;
		if (randomNum == 1){
			car = car1;
			mashLoop7 = false;
		}
		else if (randomNum == 2){
			car = car2;
			mashLoop = false;
		}
		else {
			car = car3;
			mashLoop7 = false;
		}
	}

	//ENDING CREDITS
	int i;
	for (i = 0; i < 6; ++i){
		cout << "*";
	}
	cout << "	MASH RESULTS	";
	for (i = 0; i < 6; ++i){
		cout << "*";
	}

	//ENDING RESULTS
	cout << "\nYou will live " << mash << endl;
	cout << "You will be happily married to " << person << endl;
	cout << "You will have " << children << " child/children" << endl;
	cout << "You will live in " << cityState << endl;
	cout << "You will own a " << occupation << " chain and make $" << salary << " annually" << endl;
	cout << "You will drive a " << car << endl;

	//REPEAT THE GAME
	cout << "\n\nPick from the following menu: " << endl;
	cout << "1. 	Let's play MASH!" << endl;
	cout << "2. 	End program." << endl;
	int chooseagain;
	cin >> chooseagain;
	bool again1 = true;
	while (again1){
		if (chooseagain == 1){
			again1 = false;
			mashTheGame = true;
			cout << "\nYou chose to play MASH!\n" << endl;
		}
		else if (chooseagain == 2){
			again1 = false;
			mashTheGame = false;
			cout << "\nYou chose to end the program. \nBye!";
		}
		else if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid choice. Type 1 or 2" << endl;
			cin >> chooseagain;
		}
		else {
			cout << "Invalid choice. Type 1 or 2" << endl;
			cin >> chooseagain;
		}
	}

	}
	return 0;	
}