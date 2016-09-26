#include <iostream>
#include <string>

using namespace std;

int main(){
	int TC, c, b;
	string d;
	cin >> TC;
	while (TC--){
		cin >> c >> b >> d;
		int sum = 0;
		for (int i = 0; i < d.length(); i++){
			sum += (d[i] - '0');
		}
		cout << c << ' ' << sum % (b-1) << endl;
	}
}
