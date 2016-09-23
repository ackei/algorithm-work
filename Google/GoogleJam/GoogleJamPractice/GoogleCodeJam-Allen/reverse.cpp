#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int TC, count = 1;
	scanf("%d\n",&TC);
	string input;
	while (TC--){
		getline(cin,input);
		char* cstr = new char[input.length()+1];
		strcpy(cstr,input.c_str());
		
		vector<char*> words;
		char* p = strtok(cstr," ");
		while (p!=0){
			words.push_back(p);
			p = strtok(NULL," ");
		}
		printf("Case #%d: ", count++);
		for (int i = words.size()-1; i >= 0; i--){
			cout << words[i] << " ";
		}

		delete[] cstr;
		cout << endl;
	}
}
