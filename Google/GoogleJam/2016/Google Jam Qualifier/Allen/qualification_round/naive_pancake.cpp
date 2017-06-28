#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <queue>
#include <map>

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

bool happy(string stack){
	int length = stack.length();
	for (int i = 0; i < length; i++){
		if (stack[i] == '-')
			return false;
	}
	return true;
}

int main(){
	int TC, c = 1;
	cin >> TC;
	while (TC--){
		map<string,int> min_flip_map;
		string stack;
		cin >> stack;
		queue<pair<string,int> > stacks_to_check;
		stacks_to_check.push(make_pair(stack,0));
		while (!stacks_to_check.empty()){
			pair<string,int> stack_pair = stacks_to_check.front();
			stacks_to_check.pop();
			string stack_to_check = truncate(stack_pair.first);
			int current_num_flip = stack_pair.second;
			if (happy(stack_to_check)){
				printf("Case #%d: %d\n",c++,current_num_flip);
				break;
			}
			int length = stack_to_check.length();
			for (int i = 0; i < length; i++){
				pair<string,int> pair_to_push(flip(stack_to_check,i),current_num_flip+1);
				stacks_to_check.push(pair_to_push);
			}
		}
	}
}