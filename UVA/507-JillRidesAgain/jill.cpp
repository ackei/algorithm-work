#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void readRoutes();
pair<int, int> maxSubarray(vector<int> array);
int niceness(pair<int, int> stops, vector<int> array);
int better(int niceLeft, pair<int, int> leftSolution,
           int niceRight, pair<int, int> rightSolution);

vector<vector<int> > routes;

int main(){

    int totalNice;
    pair<int, int> stops;
    readRoutes();

    for(int i = 0; i < routes.size(); ++i){

        stops = maxSubarray(routes[i]);
        totalNice = niceness(stops, routes[i]);
        if(totalNice < 0){
            cout << "Route " << i + 1 << " has no nice parts" << endl;
        } else {
            cout << "The nicest part of route "
                 << i + 1
                 << " is between stops "
                 << stops.first + 1
                 << " and "
                 << stops.second + 2
                 << endl;
        }

    }

    return 0;

}

void readRoutes(){

    int numRoutes,
        routeLength,
        niceness;

    cin >> numRoutes;
    routes.resize(numRoutes);
    for(int i = 0; i < numRoutes; ++i){
        cin >> routeLength;
        for(int j = 0; j < routeLength - 1; ++j){
            cin >> niceness;
            routes[i].push_back(niceness);
        }
    }

}

pair<int, int> maxSubarray(vector<int> array){

    // Base case.
    if(array.size() == 1){
        return make_pair(0, 0);
    }

    int leftSize = array.size() / 2,
        rightSize = array.size() - leftSize;
    vector<int> left(leftSize),
                right(rightSize);

    for(int i = 0; i < left.size(); ++i){
        left[i] = array[i];
    }
    for(int i = 0; i < rightSize; ++i){
        right[i] = array[i + leftSize];
    }

    pair<int, int> leftSolution = maxSubarray(left),
                   rightSolution = maxSubarray(right);

    int nicenessLeft = niceness(leftSolution, left),
        nicenessRight = niceness(rightSolution, right),
        leftBound = leftSize - 1,
        leftSum = left[leftSize - 1],
        leftMax = left[leftSize - 1],
        rightBound = 0,
        rightSum = right[0],
        rightMax = right[0],
        nicenessAcross = 0;

    rightSolution.first += left.size();
    rightSolution.second += left.size();

    for(int i = left.size() - 2; i >= 0; --i){
        leftSum += left[i];
        if(leftSum >= leftMax){
            leftMax = leftSum;
            leftBound = i;
        }
    }

    for(int i = 1; i < right.size(); ++i){
        rightSum += right[i];
        if(rightSum >= rightMax){
            rightMax = rightSum;
            rightBound = i;
        }
    }

    pair<int, int> acrossSolution = make_pair(leftBound, rightBound + leftSize);
    nicenessAcross = rightMax + leftMax;

    if(better(nicenessLeft, leftSolution, nicenessRight, rightSolution) == -1){
        if(better(nicenessLeft, leftSolution, nicenessAcross, acrossSolution) == -1){
            return leftSolution;
        } else {
            return acrossSolution;
        }
    } else {
        if(better(nicenessAcross, acrossSolution, nicenessRight, rightSolution) == -1){
            return acrossSolution;
        } else {
            return rightSolution;
        }
    }

}

int niceness(pair<int, int> stops, vector<int> array){

    int niceness = 0;
    for(int i = stops.first; i <= stops.second; ++i){
        niceness += array[i];
    }

    return niceness;

}

int better(int niceLeft, pair<int, int> leftSolution,
           int niceRight, pair<int, int> rightSolution){

    if(niceLeft > niceRight){
        return -1;
    } else if (niceLeft < niceRight){
        return 1;
    } else {

        int leftWidth = leftSolution.second - leftSolution.first + 1,
            rightWidth = rightSolution.second - rightSolution.first + 1;

        if(leftWidth > rightWidth){
            return -1;
        } else if(leftWidth < rightWidth){
            return 1;
        } else {
            if(leftSolution.first < rightSolution.first){
                return -1;
            } else {
                return 1;
            }
        }
    }

}
