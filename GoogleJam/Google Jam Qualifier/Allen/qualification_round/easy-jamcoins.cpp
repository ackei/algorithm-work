#include <cstdio>
#include <cstring>

void print_result(int* A, int size){
	for (int i = 0; i < size; i++){
			printf("%d",A[i]);
	}
	printf(" %d %d %d %d %d %d %d %d %d\n",3,4,5,6,7,8,9,10,11);
}

int main(){
	const int N = 16;
	const int J = 50;
	
	int nums[N];
	int count = 0;
	printf("Case #1:\n");
	for (int i = 1; i < (1 << 7); i++){
		memset(nums,0,sizeof nums);
		nums[0] = nums[N-1] = 1;
		for (int j = 0; j < 7; j++){
			int num_at_index_j = (i & (1 << j));
			nums[2*j+1] = nums[2*j+2] = num_at_index_j ? 0 : 1;
		}
		print_result(nums,N);
			if (++count >= 50)
				break;
	}
	return 0;
}