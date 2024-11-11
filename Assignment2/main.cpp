#include <string>
#include <iostream>
using namespace std;

void revStr(string &str, int s, int i) {
	//base case
	if (s >= i) {
		return;
	}
	//swaps the first letter and last letter
	swap(str[s], str[i]);
	//call back the method to do the same for the other letters
	revStr(str, s + 1, i - 1);
}

int maxValue(int *nums, int i) {
	if (i == 1) {
		return *nums;
	}
	int value = maxValue(nums + 1, i - 1);

	if (*nums > value) {
		return *nums;
	}
	else {
		return value;
	}
}

int main() {
	string userInput;
	string initialInput;
	const int nums = 5;
	int j;
	//Recursion to reverse a string
	int choice;
	do {
		cout << "------------------------------------------------" << endl;
		cout << "Main Menu" << endl;
		cout << "" << endl;
		cout << "1) Reverse a string" << endl;
		cout << "2) Find max value in a array of 5 numbers" << endl;
		cout << "3) Exit Program" << endl;
		cout << "" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Enter choice: " << endl;
		cout << "" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "------------------------------------------------" << endl;
			cout << "Enter string to be reversed: " << endl;
			cout << endl;
			cin >> userInput;
			cout << "------------------------------------------------" << endl;
			initialInput = userInput;
			revStr(userInput, 0, userInput.length() - 1);
			cout << "The string " << userInput << " has been reversed" << endl;
			cout << "Reversed string: " << userInput << endl;
			break;
		case 2:
			int arrayofNums[nums];
			cout << "------------------------------------------------" << endl;
			cout << "Enter the numbers one by one: " << endl;
			for (int i = 0; i < nums; i++) {
				cin >> arrayofNums[i];
			}
			j = sizeof(arrayofNums) / sizeof(arrayofNums[0]);
			cout << "The maximum value in this list of 5 numbers is: " << maxValue(arrayofNums, j) << endl;
			break;
		case 3:
			cout << "Program terminated" << endl;
			break;
		default:
			cout << "Please select one of the options above." << endl;
		}
		cout << "" << endl;
	} while (choice != 3);
	
	return 0;
}