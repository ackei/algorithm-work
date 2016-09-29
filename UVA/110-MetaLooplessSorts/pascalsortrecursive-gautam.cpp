#include <iostream>
#include <string>
#define PRINT false
using namespace std;

int n;

//array = Smallest to largest
// Current Character index 
void printifelse(string array[], int currentCharacterIndex, string tabs) {

	if (n == 1) { cout << tabs + "  " << "writeln(" << array[0] << ")" << endl; return; } 

	for (int i = currentCharacterIndex - 1; i > -2; i--) {
	
#if PRINT
cout << "Writing out if statements" << endl;
#endif
		if (i == currentCharacterIndex - 1) {
			cout << tabs << "if " << array[i] <<  " < " << array[currentCharacterIndex] << " then" << endl;
		}
		else if (i > -1) {
			cout << tabs << "else if " << array[i] <<  " < " << array[currentCharacterIndex] << " then" << endl;
		}
		else {
			cout << tabs << "else" << endl;
		}
#if PRINT
cout << "Declaring new array for recursive step" << endl;
#endif
	
		string newarray[n]; for (int j = 0; j < n; j++) { newarray[j] = array[j]; }
		string temp = newarray[currentCharacterIndex]; 
		for (int j = currentCharacterIndex - 1; j > i; j--) {
			newarray[j+1] = newarray[j];
		}	
		newarray[i+1] = temp;
		

#if PRINT
cout << "Recursive step or writeline" << endl;
#endif
		
		if (currentCharacterIndex != n-1) {
			printifelse(newarray, currentCharacterIndex+1, tabs + "  ");
		}
		else {
			cout << tabs + "  " << "writeln(";
			for (int j = 0; j < n; j++) { 
				if (j != n-1) { cout << newarray[j] << ","; }
				else { cout << newarray[j]; }
			}
			cout << ")" << endl;
		}
	}

}


int main() { 
	int num; cin >> num;
	while (num--) {
		cin >> n;
		if (n < 1 || n > 8) { continue; }

		cout << "program sort(input,output);" << endl;
		cout << "var" << endl;


		string array[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
		

		for (int i = 0; i < n; i++) {
			if (i != n-1)
				cout << array[i] << ",";
			else
				cout << array[i];
		}
			
		cout << " : integer;" << endl
			 << "begin" << endl
			 << "  readln(";
		
		for (int i = 0; i < n; i++) {
			if (i != n-1)
				cout << array[i] << ",";
			else
				cout << array[i];
		}
		cout << ");" << endl;

		printifelse(array, 1, "  ");
		cout << "end.";

		if (num != 0)
			cout << endl << endl;
		else
			cout << endl;


	}

	return 0;
}
