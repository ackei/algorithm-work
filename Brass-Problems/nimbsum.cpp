#include <iostream>
using namespace std;


void convert(int num, int base, int* arr) {
	int x = num, count = 0;
	while (count < 25) {
		arr[count++] = x % base;
		x = x / base;
	}
}

int convback(int base, int* arr) {
	

}

void Badd(int* arr1, int* arr2, int* ans, int base) {
	
}


int main() {
	
	int numcases;
	cin >> numcases;
	while(numcases--) {
	
		int probnum, base, num1, num2, answer;
		cin >> probnum >> base >> num1 >> num2;
		
		int arr1[25], arr2[25], ans[25];

		convert(num1, base, arr1);
		convert(num2, base, arr2);
		Badd(arr1, arr2, ans, base);
		answer = convback(base, ans);
		
		cout << probnum << " " << answer << endl;
		
	}



	return 0;
}
