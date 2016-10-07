#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	int prevDist, dist, numLeaks, leakStart;
	string event;
	float gasLost, maxGasUsed, prevUsage, usage;
	usage = prevUsage = prevDist = dist = gasLost = maxGasUsed = numLeaks = leakStart = 0;
	while (cin >> dist >> event){
		if (event == "Goal"){
			gasLost += usage * (dist-prevDist) / 100;
			gasLost += (dist - leakStart) * numLeaks;
			maxGasUsed = ((gasLost > maxGasUsed) ? gasLost : maxGasUsed);
			printf("%.3f\n",maxGasUsed);
			prevDist = dist = gasLost = maxGasUsed = numLeaks = leakStart = 0;
		}
		else if (event == "Leak"){
			if (!numLeaks){
				leakStart = dist;
				numLeaks++;
			}
			else{
				gasLost += (dist - leakStart) * numLeaks++;
				leakStart = dist;
			}
		}
		else if (event == "Gas"){
			cin >> event;
			gasLost += usage * (dist-prevDist) / 100;
			gasLost += (dist - leakStart) * numLeaks;
			maxGasUsed = ((gasLost > maxGasUsed) ? gasLost : maxGasUsed);
			leakStart = dist;
			gasLost = 0;
			prevDist = dist;
		}
		else if (event == "Mechanic"){
			gasLost += (dist - leakStart) * numLeaks;
			numLeaks = 0;
		}
		else if (event == "Fuel"){
			prevUsage = usage;
			cin >> event >> usage;
			if (!usage) 
				break;
			else if (usage != prevUsage){
				gasLost += prevUsage * (dist-prevDist) / 100;
				prevDist = dist; 
				prevUsage = usage;
			}
		}
	}

	return 0;
}
