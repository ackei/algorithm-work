#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

float stof(string s) {
	int bfdecimal[s.length()], bfc = 0;
	int afdecimal[s.length()], afc = 0;
	bool bfmode = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '.' && bfmode) {
			bfdecimal[bfc++] = (int)s[i] - 48;
		}
		else if (s[i] == '.') { bfmode = false; }
		else {
			afdecimal[afc++] = (int)s[i] - 48;
		}
	}

	float ans, tensplace = 1;
	for (int i = bfc - 1; i > -1; i--) {
		ans += bfdecimal[i]*(tensplace);
		tensplace *= 10;
	}
	tensplace = 0.1;
	for (int i = 0; i < afc; i++) {
		ans += afdecimal[i]*tensplace;
		tensplace /= 10;
	}
	return ans ; // May need to change this

}

string to_string(float f) {

	int digit = (int)f%10; string ans;
	
	for (float tensplace = 10; digit != 0; tensplace *= 10) {
		ans.insert(0, 1, (char)digit + 48);
		digit = (int)(f / tensplace);
	}
	ans.push_back('.');
	ans.push_back((char)((int)(f*10)%10) + 48);
	ans.push_back((char)((int)(f*100)%10) + 48); 
	return ans;
}
/*
int main() {
	
	cout << to_string(stof("1.21")*stof("1.21"));

	return 0;
}
*/
int main() {

	string cmd; map<string, map<int, string> > inv; float totalProfitLastReport = 0; 

	while (cin >> cmd) {
			
		if (cmd == "new") {
			string pn, bc, sc;
			cin >> pn; cin >> bc; cin >> sc;
			inv[pn];
			for (int i = 0; i < 6; i++) {
				string temp = "0";
				inv[pn][i] = temp;
			}
			inv[pn][0] = bc;
			inv[pn][1] = sc;
		}
		else if (cmd == "buy") {
			string pName, q;
			cin >> pName; cin >> q;
			for(map<string, map<int, string> >::iterator it = inv.begin(); it != inv.end(); it++) {
				if (it->first == pName) {
					it->second[2] = q;
					it->second[4] = to_string(stof(it->second[0])* stof(it->second[2]));
				}
			}
		}
		else if (cmd == "sell") {
			string pN, qs;
			cin >> pN; cin >> qs;
			for (map<string, map<int, string> >::iterator it = inv.begin(); it != inv.end(); it++) {
				if (it->first == pN) {
					it->second[3] = qs;
					it->second[2] = to_string(stof(it->second[2]) - stof(qs));
					it->second[4] = to_string(stof(it->second[0])*stof(it->second[2]));
					it->second[5] = to_string((stof(it->second[1]) - stof(it->second[0]))*stof(it->second[3]));
				}
			}
		}
		else if (cmd == "delete") {
			string pNm; cin >> pNm;
			inv.erase(pNm);
		}
		else if (cmd == "report") {
				cout << setw(34) << "INVENTORY REPORT" << endl;
				cout << "Item Name" << setw(11) << "Buy At" << setw(12) << "Sell At" << setw(12) << "On Hand" << setw(10) << "Value" << endl;
				cout << "---------" << setw(11) << "------" << setw(12) << "-------" << setw(12) << "-------" << setw(10) << "-----" << endl;
				float totalv = 0, totalp = 0;
				for (map<string, map<int, string> >::iterator it = inv.begin(); it != inv.end(); it++) {
					cout << it->first << setw(11) << it->second[0] << setw(12) << it->second[1] << setw(12) << it->second[2] << setw(10) 
						<< it->second[3] << endl;
					totalv += stof(it->second[4]);
					totalp += stof(it->second[5]);
				}
				cout << "------------------------" << endl;
				cout << "Total Value of Inventory" << setw(30) << totalv << endl;
				cout << "Profit Since Last Report" << setw(30) << totalp - totalProfitLastReport << endl;
				totalProfitLastReport = totalp;
		}
		else {
				cout <<  "Something is Wrong " << cmd << endl;
		}

	}

	return 0;
}
