#include <iostream>
#include <string>
#include <vector>

using namespace std;

int value(char c){
	if (c == 'X' || c == '/')
		return 10;
	else
		return c - '0';
}

int main(){
	string input;
	while (getline(cin,input) && input != "Game Over"){
		string l;
		for (int i = 0; i < input.length(); i+=2){
			l += input[i];
			if (input[i] == 'X')
				l += '0';
		}
		string frames;
		for (int i = 0; i < l.length(); i+=2){
			if (l[i] == 'X')
				frames+='X';
			else if (l[i+1] == '/'){
				frames+='/';
			}
			else{
				frames+=(char)('0' + value(l[i]) + value(l[i+1]));
			}
		}
		int score = 0;
		for (int i = 0; i < 10; i++){
			if (frames[i] == 'X'){
				if (frames[i+1] == '/'){
					score += 20;
				}
				else if (frames[i+1] == 'X'){
					score += (20 + value(l[(i+2)*2]));
				}
				else{
					int val = (10 + value(l[(i+1)*2]) + value(l[(i+1)*2+1]));
					score += val;
				}
			}
			else if (frames[i] == '/'){
				int val = (10 + value(l[(i+1)*2]));
				score += val;
			}
			else{
				score += value(frames[i]);
			}
		}
		cout << score << endl;
	}
}
