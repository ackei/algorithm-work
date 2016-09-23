#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll answers[300][300];

ll UPD(int num);
ll UPD_helper(int n, int k){
	if (n < 1){
		return 0;
	}
	else if (answers[n][k] >= 0){
		return answers[n][k];
	}
	else if (n == k){
		return 1;
	}
	else if (n % 2 == 0 && k == n/2)
		return 1;
	else{
		ll sum = 0;
		for (int i = k; i <= n; i++){
			sum += UPD_helper(n-k*2,i);
		}
		return answers[n][k] = sum;
	}
}

ll UPD(int num){
	ll answer = 0;
	for (int i = 1; i <= num; i++){
		answer += UPD_helper(num,i);
	}
	return answer;
}



int main(){
	memset(answers,-1,sizeof answers);
	ll input;
	while (cin >> input && input){
		cout << input << " " << UPD(input) << endl;
	}
	return 0;
}
