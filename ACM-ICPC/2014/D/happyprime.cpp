#include <cstdio>
#include <iostream>
#include <bitset>
#include <set>

using namespace std;

long long sieveSize;
bitset<10010> bs;
set<int> checkSet;
set<int> notHappy;

void sieve(long long upperbound) {
	sieveSize = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= sieveSize; i++){
		if (bs[i]){
			for (long long j = i*i; j <= sieveSize; j+=i)
				bs[j] = 0;
		}
	}
}

int sumDigitSquared(int n){
	int sum = 0;
	int current = n;
	while (current >= 10){
		int last = current % 10;
		sum += (last * last);
		current /= 10;
	}
	return sum + (current * current);
}

bool isHappy(int n){
	if (n == 1){
		checkSet.clear();
		return true;
	}
	if (notHappy.count(n)){
		return false;
	}
	if (checkSet.count(n)){
		for (set<int>::iterator it = checkSet.begin(); it != checkSet.end(); ++it)
			notHappy.insert(*it);
		checkSet.clear();
		return false;
	}
	checkSet.insert(n);
	return isHappy(sumDigitSquared(n));
}

int main(){
	sieve(10000);
	int TC, n, c = 1;
	scanf("%d", &TC);
	while (TC--){
		if (c > 1) printf("\n");
		scanf("%d %d",&c,&n);
		if (bs[n] && isHappy(n))
			printf("%d %d %s",c,n,"YES");
		else{
			printf("%d %d %s",c,n,"NO");
		}
		c++;
	}

	return 0;
}
