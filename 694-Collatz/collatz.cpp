#include <cstdio>
#include <climits>

int numTerms(int A, int L);

int main(){
	int A,L, c = 1;
	while (scanf("%d %d",&A,&L),A >= 0 && L >= 0){
		if (c > 1) printf("\n");
		printf("Case %d: A = %d, limit = %d, number of terms = %d", c++, A, L, numTerms(A,L));
	}
	return 0;
}

int numTerms(int A, int L){
	int count = 1;
	int current = A;
	while (current != 1){
		if (current % 2){
			if (current >= INT_MAX/3)
				break;	
			current = 3*current + 1;
		}
		else
			current /= 2;
		if (current <= L)
			count++;
		else
			break;
	}
	return count;
}
