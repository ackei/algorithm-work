#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool backtrack(int partial_sum, int target, vector<int>& choices);
vector<int> getFactors(int sum);
bool readCuts(vector<int>& cuts);

int main(){

    vector<int> cuts;
    vector<int> factors;
    int sum,
        max,
        i;

    while(readCuts(cuts)){

        sum = 0;
        for(i = 0; i < cuts.size(); ++i){
            sum += cuts[i];
        }

        factors = getFactors(sum);
        max = *max_element(cuts.begin(), cuts.end());
        i = 0;

        while(max > factors[i]){
            ++i;
        }

        // cout << "max: " << max << " sum: " << sum << " i: " << i << endl;
        while(!backtrack(0, factors[i], cuts)){
            ++i;
        }

        cout << factors[i] << endl;

    }

}

bool readCuts(vector<int>& cuts){

    cuts.clear();
    int size,
        nextCut;
    cin >> size;

    if(!size){
        return false;
    }

    for(int i = 0; i < size; ++i){
        cin >> nextCut;
        cuts.push_back(nextCut);
    }

    sort(cuts.begin(), cuts.end());

    return true;

}

vector<int> getFactors(int sum){

    vector<int> smallFactors;
    vector<int> largeFactors;

    for(int i = 1; i * i < sum; ++i){

        if(sum % i == 0){
            smallFactors.push_back(i);
            largeFactors.push_back(sum / i);
        }

    }

    vector<int> result(smallFactors.size() + largeFactors.size());
    reverse(largeFactors.begin(), largeFactors.end());
    merge(
        smallFactors.begin(),
        smallFactors.end(),
        largeFactors.begin(),
        largeFactors.end(),
        result.begin()
    );

    return result;

}

bool backtrack(int partial_sum, int target,  vector<int>& choices){

    vector<int> newChoices(choices);
    int choice;
    bool isKosher;

    for(int i = 0; i < choices.size(); ++i){

        choice = choices[i];
        newChoices.erase(newChoices.begin() + i);

        if(partial_sum + choice < target){

            isKosher = backtrack(partial_sum + choice, target, newChoices);

            if(isKosher){

                return true;

            } else {

                while(i + 1 < choices.size() && choices[i + 1] == choice){
                    ++i;
                }

            }

        } else if(partial_sum + choice == target && newChoices.size() == 0){

            return true;

        } else if(partial_sum + choice == target){

            return backtrack(0, target, newChoices);

        }

        newChoices.insert(newChoices.begin() + i, choice);

    }

    return false;

}
