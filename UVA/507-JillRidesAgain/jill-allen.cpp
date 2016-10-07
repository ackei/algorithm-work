#include <cstdio>

// return max value
int max_subarray(int* niceness,int len,int& start,int& end){
	int max_nice, current_nice, max_length, current_length, current_start, current_end;
	max_nice = current_nice = max_length = current_length = current_start = 0;
	current_end = 1;
	for (int i = 0; i < len; i++){
		current_nice += niceness[i];
		current_length++;
		current_end = i+1;
		if (current_nice > max_nice || (current_nice == max_nice && current_length > max_length)){
			max_nice = current_nice;
			max_length = current_length;
			start = current_start;
			end = current_end;
		}
		if (current_nice < 0){
			current_start = i+1;
			current_nice = 0;
			current_length = 0;
		}
	}

	return max_nice;
}

int main(){
	int TC, c = 1, S, start, end;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d",&S);
		int niceness[20000];
		for (int i = 0; i < S-1; i++)
			scanf("%d",&niceness[i]);
		if (max_subarray(niceness,S-1,start,end))
			printf("The nicest part of route %d is between stops %d and %d\n",c++,start+1,end+1);
		else
			printf("Route %d has no nice parts\n",c++);
	}
}
