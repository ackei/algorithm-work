#include <stdio.h>
#include <stdlib.h>

void initdata(int data[2][15]) {
	int i;
	for (i = 0; i < 15; data[0][i] = 0, data[1][i] = 0, i++); 
}

void convert(char* str, int* arr) {
	int i;
	for (i = 0; i < 15; i++) {
		arr[i] = atoi(&str[i << 1]);
	}	
}

void detect(int* arr, int* indexptr, int* data[2], int* countptr) {
	if (arr[*indexptr] > arr[*indexptr-1]) {
		data[0][(*countptr)++] = arr[*indexptr];
	}
}

void check(int* arr, int* indexptr, int* data[2], int* countptr) {
	int i;
	for (i = 0; i < *countptr; i++) {
		if (data[0][i] != 0 && arr[*indexptr] <= data[0][i]) {
			data[1][i] = 1;
		}
	}
}

int compute(int** data, int* countptr) {
	int i, ans = 0;
	for (i = 0; i < (*countptr); i++) {
		if (data[1][i] == 1) {
			ans++;
		}
	}
	return ans;
}

void numIslands(int* arr, int* data[2], int* ans) {	
	
	int index, count = 0;

	if (arr[0] != 0) {
		data[0][0] = arr[0];
	}

	for (index = 1 ; index < 15; index++) {
		check(arr, &index, data, &count);
		detect(arr, &index, data, &count);		
	}	

	(*ans) = compute(data, &count);
}

int main() {

	char buff = getchar();
	int numcases = atoi(&buff);
	while (numcases--) {
		int ans = 0;
		int arr[15];
		int data[2][15];
		char str[30];
		
		initdata(data);
		
		fgets(str, 30, stdin);
		fputs(str, stdout);
		//convert(str, arr);
		//numIslands(arr, data, &ans);		
			
		//printf("%d %d", numcases, ans);
	}


	return 0;
}
