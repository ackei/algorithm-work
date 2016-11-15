#include<cstdio>
using namespace std;

int main(){
	int P, K, oct_int, dec_int, hex_int;
	char num_str[8];
	scanf("%d", &P);
	while(P--){
		scanf("%d %s", &K, num_str);
		sscanf(num_str, "%o", &oct_int);
		for(char *p = num_str; *p != '\0'; ++p)
			if(*p == '9' || *p == '8') oct_int = 0;
		sscanf(num_str, "%x", &hex_int);
		sscanf(num_str, "%d", &dec_int);
		printf("%d %d %d %d\n", K, oct_int, dec_int, hex_int);
	}
}
