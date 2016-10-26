#include <iostream>
#include <string>

using namespace std;

void post(string pre, string in){
	if (pre.length() == 0)
		return;
	char root = pre[0];
	int root_idx = in.find(root);
	post(pre.substr(1,root_idx), in.substr(0,root_idx));
	post(pre.substr(root_idx + 1, pre.length()-root_idx), in.substr(root_idx+1,in.length()-root_idx));
	cout << root;
}

int main(){
	string pre;
	string in;
	while (cin >> pre >> in){
		post(pre,in);
		cout << endl;
	}
	return 0;
}
