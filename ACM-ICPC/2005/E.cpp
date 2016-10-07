#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

void parse(unsigned char* mem, size_t& pointer, string& line, int& sqbrck, string& output) {

	

}



int main() {

	// Program Number
	int C = 1,N;
	cin >> N;

	string line;

	// Flush
	getline(cin, line);

	while (N--) {
		unsigned char mem[1 << 14];
		memset((void *)mem, 0, 1 << 14);
		size_t pointer = 0;
		int sqbrck = 0;
		string output;
		
		line = "";
	
		while (getline(cin, line), line != "end") {
			
			string ans = "COMPILE ERROR";
			cout << line << endl;
			
			parse(mem, pointer, line, sqbrck, output);
			
		}
				

	//	cout << "PROGRAM #" << C << ":" << endl;
		cout << line << endl;
		C++;
	}
	
	return 0;
}
