#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	while (cin >> n) {
	
		if (n < 1 || n > 6) continue;
		
		string vars;

		switch (n) {
			case 1:
				vars = "a"; break;
			case 2:
				vars = "a,b"; break;
			case 3:
				vars = "a,b,c"; break;
			case 4:
				vars = "a,b,c,d"; break;
			case 5:
				vars = "a,b,c,d,e"; break;
			case 6: 
				vars = "a,b,c,d,e,f"; break;
		}

		cout <<  "program sort(input, output);" << endl
			<< "var" << endl 
			<< vars + " : integer;" << endl
			 << "begin" << endl
			<< "\treadln(" + vars + ");" << endl;

		if (n > 1) {
			cout << "\tif a < b then" << endl; 
			if (n > 2) {
				cout << "\t\tif b < c then" << endl;
				cout << "\t\t\twriteln(a,b,c)" << endl;
				cout << "\t\telse if a < c then" << endl;
				cout << "\t\t\twriteln(a,c,b)" << endl;
				cout << "\t\telse" << endl;
				cout << "\t\t\twriteln(c,a,b)" << endl;
			}
			else {
				cout << "\t\twriteln(a,b)" << endl;
			}
			cout << "\telse" << endl;
			if (n > 2) {
				cout << "\t\tif a < c then" << endl;
				cout << "\t\t\twriteln(b,a,c)" << endl;
				cout << "\t\telse if b < c then" << endl;
				cout << "\t\t\twriteln(b,c,a)" << endl;
				cout << "\t\telse" << endl;
				cout << "\t\t\twriteln(c,b,a)" << endl;
			}
			else {
				cout << "\t\twriteln(b,a)" << endl;
			}
		}		
		else {		
			cout << "\twriteln(a)" << endl;
		}


		cout << "end." << endl;

	}

	return 0;
}
