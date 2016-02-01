#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

float records[1000];

int main(){
	int numStudents;
	while (scanf("%d", &numStudents) && numStudents){
		memset(records,0,sizeof records);
		float avg = 0;
		for (int i = 0; i < numStudents; i++){
			scanf("%f",&records[i]);
			avg = avg * ((float)i / (i + 1)) + (records[i] / (i+1));
		}
		float avg1 = floor(avg * 100 + 0.5)/100;
		float avg2 = ceil(avg * 100 + 0.5)/100;
		float given1 = 0, given2 = 0, received1 = 0, received2 = 0;
		for (int i = 0; i < numStudents; i++){
			float diff1 = records[i] - avg1;
			if (diff1 > 0)
				received1 += diff1;
			else if (diff1 < 0)
				given1 -= diff1;
			float diff2 = records[i] - avg2;
			if (diff2 > 0)
				received2 += diff2;
			else if (diff2 < 0)
				given2 -= diff2;
		}
		printf("$%.2f\n",max((given1 < received1) ? given1 : received1, (given2 < received2) ? given2 : received2));
	}
}
