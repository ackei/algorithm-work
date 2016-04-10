#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

    unsigned long numUglies = 0;
    unsigned long candidate = 1;
    unsigned long factors[3] = {2, 3, 5};
    unsigned long last;
    unsigned long test;
    vector<unsigned long> uglies;
    uglies.push_back(1);

    while(numUglies < 1500){

        last = uglies[uglies.size() - 1];
        candidate = last * 5;

        for(unsigned long i = 0; i < uglies.size(); ++i){

            for(unsigned long k = 0; k < 3; ++k){
                test = uglies[i] * factors[k];
                if(test > last && candidate > test){
                    candidate = test;
                }

            }

        }
        uglies.push_back(candidate);
        ++numUglies;
    }


/*
    for(unsigned long i = 0; i < uglies.size(); ++i){
        cout << uglies[i] << ", ";
    }
    cout << endl;
    */
    cout << uglies[1499] << endl;
    return 0;

}
