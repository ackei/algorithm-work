#include <iostream>
#include <string>
using namespace std;

// Input differs from problem statement - Here I use command line arguments

void OneLevel(string TopLevelVarNames, string varNames, string tabs, int& num);

int main() {

	int x;
	cin >> x;
	if (x < 1 || x > 6) { return 1; }

	int num = 0;

	OneLevel("abc", "abc", "\t", num);

	//string w = "abcdef";
	//cout << w[2] << endl;
	return 0;
}

void OneLevel(string TopLevelVarNames, string varNames, string tabs, int& num)
{
	string x = varNames;
	string w = TopLevelVarNames;

	if (x.length() == 1 && w.length() == 1)
	{
		cout << tabs << num++ << endl;
		return;
	}
	else if (x.length() == 1)
	{
		string z = w.substr(0, w.length() - 1);
		OneLevel(z, z, tabs, num);
		return;
	}
	
	char y = x[x.length() - 1];

	cout << tabs << "if " << varNames[0] << " < " << y << " then" << endl;
	x = x.erase(0, 1);
	OneLevel(w, x, tabs + "\t", num);
	cout << tabs << "else "  << endl;
	OneLevel(w, x, tabs + "\t", num);
	
	
}



