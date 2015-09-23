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
        //cout << "Printing route: " << i << endl;
        for(int j = 0; j < routes[i].size(); ++j){
            //cout << routes[i][j] << ' ';
        }
        //cout << endl;
    }

    for(int i = 0; i < routes.size(); ++i){

        stops = maxSubarray(routes[i]);
        //cout << "stops: " << stops.first << ' ' << stops.second << endl;
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

    //cout << "Exiting read readRoutes()!" << endl;

}

pair<int, int> maxSubarray(vector<int> array){

    //cout << "array.size(): " << array.size() << endl;
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
    ////cout << "Made it past computing the new arrays." << endl;

    pair<int, int> leftSolution = maxSubarray(left),
                   rightSolution = maxSubarray(right);

    //cout << "Back from recursion!" << endl;

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

    //cout << "Made it past computing their nicenesses!" << endl;

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

    //cout << "Made it past computing max across array!" << endl;

    pair<int, int> acrossSolution = make_pair(leftBound, rightBound + leftSize);
    nicenessAcross = rightMax + leftMax;

    if(better(nicenessLeft, leftSolution, nicenessRight, rightSolution) == -1){
        //cout << "left is better than right" << endl;
        if(better(nicenessLeft, leftSolution, nicenessAcross, acrossSolution) == -1){
            //cout << "left is better than across" << endl;
            return leftSolution;
        } else {
            //cout << "across is better than left" << endl;
            return acrossSolution;
        }
    } else {
        //cout << "right is better than left" << endl;
        if(better(nicenessAcross, acrossSolution, nicenessRight, rightSolution) == -1){
            //cout << "across is better than right" << endl;
            return acrossSolution;
        } else {
            //cout << "right is better than across" << endl;
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
