#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string flip(string current_stack, int index){
	string new_stack(current_stack);
	for (int i = 0; i <= index; i++){
		char sign = '-';
		if (current_stack[index-i] == '-')
			sign = '+';
		new_stack[i] = sign;
	}
	return new_stack;
}

string truncate(string stack){
	int length = stack.length();
	int last_min_pos = -1;
	for (int i = 0; i < length; i++){
		if (stack[i] == '-')
			last_min_pos = i;
	}
	if (last_min_pos < 0)
		return "";
	return stack.substr(0,last_min_pos+1);
}

int main(){
	int TC, c = 1;
	cin >> TC;
	while (TC--){
		string stack;
		cin >> stack;
		int num_flips = 0;
		while (true){
			stack = truncate(stack);
			if (stack == ""){
				printf("Case #%d: %d\n",c++,num_flips);
				break;
			}
			int length = stack.length();
			int plus_length = 0;
			for (int i = 0; i < length; i++){
				if (stack[i] == '+')
					plus_length++;
				else
					break;
			}
			if (plus_length > 0){
				stack = flip(stack,plus_length-1);
				num_flips++;
			}
			stack = flip(stack,length-1);
			num_flips++;
		}
	}
}