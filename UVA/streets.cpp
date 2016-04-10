#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool isSquare(unsigned long num);

int main()
{
	const int N = 10;
	const int WIDTH = 10;
	pair<unsigned long,unsigned long> streets[N];
	int count = 0;
	unsigned long testNum = 2;
	unsigned long sum = 1;
	for (int i = 0; i < N; ++i)
	{
		while (true){
			sum += testNum++;
			if (isSquare(sum)){
				streets[i] = make_pair(sqrt(sum),testNum-1);
				break;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << setw(WIDTH) << streets[i].first << setw(WIDTH) << streets[i].second  << endl;
	}
	return 0;
}

bool isSquare(unsigned long num){
	if (sqrt(num) == (int)sqrt(num))
		return true;
	return false;
}