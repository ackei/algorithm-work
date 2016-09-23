#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

    int numUglies = 0;
    int testing = 1;
    int candidate = 1;
    vector<int> uglies;

    while(numUglies < 1500){
        while(candidate % 5 == 0){
            candidate /= 5;
        }
        while(candidate % 3 == 0){
            candidate /= 3;
        }
        while(candidate % 2 == 0){
            candidate /= 2;
        }
        if(candidate == 1){
            ++numUglies;
            uglies.push_back(testing);
        }
        ++testing;
        candidate = testing;
    }

    cout << uglies[1499] << endl;

    return 0;

}
