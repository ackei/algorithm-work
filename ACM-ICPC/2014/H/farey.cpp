#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b){
	return a * (b / gcd(a,b));
}

bool relPrime(int x, int y){
	return (gcd(x,y) == 1);
}

struct rational { 
	int num, den; 
	rational() : num(0), den(1) {}
	rational(int n, int d) : num(n), den(d) {}
	bool operator < (rational other) const {
		return ((num*other.den) < (other.num * den));
	}
	rational operator + (rational other) const{
		int sum_num = (num * other.den + den * other.num);
		int sum_den = (den * other.den);
		int sum_gcd = gcd(sum_num,sum_den);
		return rational(sum_num/sum_gcd,sum_den/sum_gcd);	
	}
};

vector<rational> fareyList;
vector<rational> fareySumList;
int fareySumValues[10010];

void genFarey(int n){
	fareyList.push_back(rational(0,1));
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (relPrime(i,j))
				fareyList.push_back(rational(j,i));
	fareyList.push_back(rational(1,1));
}

void reduceSum(vector<rational> &ratVec){
	set<int> denoms;
	int size = ratVec.size();
	for (int i = 0; i < size; i++)
		denoms.insert(ratVec[i].den);
	vector<rational> reducedVec;
	for (set<int>::iterator it = denoms.begin(); it != denoms.end(); ++it){
		rational oneSum(0,*it);
		for (int i = 0; i < size; i++){
			if (ratVec[i].den == *it){
				oneSum.num += ratVec[i].num;
			}
		}
		reducedVec.push_back(oneSum + rational(0,1));
	}
	if (size == reducedVec.size())
		return;
	ratVec = reducedVec;
	reduceSum(ratVec);
}

rational sumVector(vector<rational> &ratVec){
	reduceSum(ratVec);
	rational sum(0,1);
	for (int i = 0; i < ratVec.size(); i++){
		sum = sum + ratVec[i];
	}
	return sum;
}



int main(){
	int TC, n, c=1;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %d",&c,&n);
		if (c > 1) printf("\n");
		genFarey(n);
		sort(fareyList.begin(),fareyList.end());
		int size = fareyList.size();
		for (int i = 0; i < size-1; i++)
			fareySumList.push_back(rational(fareyList[i].den,fareyList[i+1].den));
		rational sum = sumVector(fareySumList);	
		if (sum.den == 1)
			printf("%d %d",c,sum.num);
		else
			printf("%d %d/%d",c,sum.num,sum.den);
		fareyList.clear();
		fareySumList.clear();

	}
	return 0;
}
