#include <iostream>
#include <vector>

using namespace std;

bool checkRed(int speed, const vector<vector<double> > &lightInfo);
void outputAcceptable(const vector<bool> &acceptable);

int main(){
	int numLights, caseNum = 1;
	vector<vector<double> > lightInfo;
	while (cin >> numLights){
		if (numLights == -1){
			break;
		}
		for (int i = 0; i < numLights; i++){
			vector<double> temp;
			double info1;
		        int info2;
			cin >> info1;
			temp.push_back(info1);
			cin >> info1;
			cin >> info2;
			temp.push_back(info1+info2);
			cin >> info1;
			temp.push_back(info1);
			lightInfo.push_back(temp);
			temp.clear();
		}
		vector<bool> acceptable;
		for (int i = 0; i < 31; i++){
			acceptable.push_back(true);
		}
		for (int i = 0; i < 31; i++){
			if (checkRed(i+30,lightInfo)){
				acceptable[i] = false;
			}
		}
		cout << "Case " << caseNum++ << ": ";
		outputAcceptable(acceptable);
		cout << endl;
	}
	
	return 0;
}

bool checkRed(int speed, const vector<vector<double> > &lightInfo){
	for (int i = 0; i < lightInfo.size(); i++){
		double time = 3600 * lightInfo[i][0]/speed;
		int cycle = lightInfo[i][1] + lightInfo[i][2];
		while (time > cycle)
			time -= cycle;
		if (time > lightInfo[i][1]){
			return false;
		}
	}
	return true;
}

void outputAcceptable(const vector<bool> &acceptable){
	int firstAcceptable = -1, length = 0, firstTime = true;
	for (int i = 0; i < 31; i++){
		if (!acceptable[i]){
			if (length == 0)
				firstAcceptable = i;
			length++;
		}
		else if (firstAcceptable != -1 && length != 0){
			if (!firstTime){
				cout << ", ";
			}
			firstTime = false;
			cout << firstAcceptable+30;
			if (length > 1){
				cout << '-' << firstAcceptable+length+29;
			}
			length = 0;

		}
	}
	if (firstAcceptable == -1){
		cout << "No acceptable speeds.";
	}	
	else if (length != 0){
		cout << ", ";
		cout << firstAcceptable+30;
		if (length > 1){
			cout << '-' << firstAcceptable+length+29;
		}
		length = 0;
	}
}
