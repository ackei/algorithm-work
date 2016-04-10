#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define VCRUISE 400; //knots
#define AOPT 30; //in thousands of feet
#define GPHOPT 2000; //gallons per hour
#define GPHEXTRA 10; //gallons per hour for each 1000 feet
#define CLIMBCOST 50; //gallons per 1000 feet of climb
#define INFINITY 1000000000;

double expTailWind(int height, int low, int high){
	return (low + ((height-20)*(high - low)/20.0));
}


int main(){
	int N,c=1;
	scanf("%d",&N);
	while (N--){
		int numLegs;
		scanf("%d",&numLegs);
		vector<vector<int> > legInfo;
		vector<int> leg(3);
		for (int i = 0; i < numLegs; ++i){
			scanf("%d %d %d",&leg[0],&leg[1],&leg[2]);
			legInfo.push_back(leg);
			leg.clear();
		}
		vector<vector<int> > fuelRequired;
		
		vector<int> altOfLegs(numLegs);
		for (int testLeg = 0; testLeg < numLegs; testLeg++){
			vector<int> currentLeg;
			for (int testHeight = 20; testHeight <= 40; testHeight++){
				double tail = expTailWind(testHeight, legInfo[testLeg][1], legInfo[testLeg][2]);
				double speed = VCRUISE + tail;
				double time = legInfo[testLeg][0]/speed;
				double fuel = (GPHOPT + GPHEXTRA * abs(testHeight - AOPT)) * time;
				currentLeg.push_back(round(fuel));
			}
			fuelRequired.push_back(currentLeg);
		}
	}
}
