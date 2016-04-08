#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

vector<int> answer;
int ansMaltNum;

vector< vector<pair<int,int> > > preferences;

void search(vector<int> maltedSet, int numMalt, int custNum, int totalCust) {
	if (custNum == totalCust){
		if (numMalt < ansMaltNum){
			answer = maltedSet;
			ansMaltNum = numMalt;
			return;
		}
	}
	int numPairs = preferences[custNum].size();
	for (int i = 0; i < numPairs; i++){
		int flavor = preferences[custNum][i].first;
		int malted = preferences[custNum][i].second;
		if (maltedSet[flavor] == -1){
			maltedSet[flavor] = malted;
			if (malted){
				search(maltedSet,numMalt+1,custNum+1,totalCust);
			}
			else{
				search(maltedSet,numMalt,custNum+1,totalCust);
			}
		}
		else if (maltedSet[flavor] != malted){
			continue;
		}
		else{
			search(maltedSet,numMalt,custNum+1,totalCust);
		}
	}
}

int main(){
	int TC, numFlavors, numCustomers, c = 1;
	scanf("%d",&TC);
	while (TC--){
		answer.clear();
		preferences.clear();
		ansMaltNum = 5000;
		scanf("%d\n",&numFlavors);
		scanf("%d\n",&numCustomers);
		int numPairs, flavor, malted;
		for (int custNum = 0; custNum < numCustomers; custNum++){
			scanf("%d ",&numPairs);
			vector<pair<int,int> > pairs;
			while(numPairs--){
				scanf("%d ",&flavor);
				scanf("%d ",&malted);
				pair<int,int> flavPair(flavor-1,malted);
				pairs.push_back(flavPair);
			}
			preferences.push_back(pairs);
		}
		vector<int> maltedSet;
		for (int i = 0; i < numFlavors; i++)
			maltedSet.push_back(-1);
		search(maltedSet,0,0,numCustomers);
		printf("Case #%d: ", c++);
		for (int i = 0; i < numFlavors; i++){
			if (ansMaltNum == 5000)
				printf("IMPOSSIBLE");
			else
				printf("%d ",answer[i] == -1 ? 0 : answer[i]);
		}
		printf("\n");
	}
}
