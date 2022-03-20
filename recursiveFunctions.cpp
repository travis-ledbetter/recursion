/*
	Title:  Lab3.cpp
	Author: Travis Ledbetter
	Purpose:  Demonstrate recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << sumOfNumbers(num) << endl;
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				if(isMember(myArray,num,ARRAY_SIZE) == 1) {
				    cout << "Value Found!" << endl;
				}
				else {
				    cout << "Value Not Found!" << endl;
				}

				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString,userString.length());

				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ')
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',')
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if(isPalindrome(userStrModified) == 1) {
					cout << "\n" << userString << " is a palindrome!" << endl;
				}
				else {
					cout << "\n" << userString << " is NOT a palindrome!" << endl;
				}
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "\n" << multiply(num1,num2) << endl;
				break;
				
		}
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

int sumOfNumbers(int num) {
    
    if(num <= 0) {
        return 0;
    }
    else {
        return sumOfNumbers(num-1) + num;
    }
    
}

bool isMember(int* myArray, int num, int ARRAY_SIZE) {
    
    int pos = ARRAY_SIZE - 1;
    
    if(pos >= 0) {
        if(myArray[pos] == num) {
            return true;
        }
        else {
            return isMember(myArray,num,ARRAY_SIZE-1);
        }
    }
    else {
        return false;
    }
}

void stringReverser(string userString, int stringLen) {
    
    int pos = stringLen - 1;

    if(pos >= 0) {
        cout << userString.at(pos);
        return stringReverser(userString,stringLen-1);
    }
    else {
        return;
    }
}

bool isPalindrome(string modifiedString) {
	
	int stringLength = modifiedString.size();
	int pos = 1;
	
	if(modifiedString.at(stringLength-pos) == modifiedString.at(pos)) {
		
		++pos;
		return isPalindrome(modifiedString);
	}
	else if(pos == (stringLength/2)) {
		
		return true;
	}
	else {
		
		return false;
	}
}

int multiply(int x,int y) {
	
	if(x > 0) {
		
		return multiply(x-1,y) + y;
	}
	else {
		
		return 0;
	}
}