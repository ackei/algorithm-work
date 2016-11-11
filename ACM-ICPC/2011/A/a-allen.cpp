#include <iostream>
#include <string>

using namespace std;

int main(){
	int TC, c, n;
	string str;
	cin >> TC;
	while (TC--){
		cin >> c >> n >> str;
		cout << c << " ";
		for (int i = 0; i < str.length(); i++){
			for (int j = 0; j < n; j++)
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
