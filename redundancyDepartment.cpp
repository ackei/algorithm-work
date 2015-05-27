#include<vector>
#include<string>
#include <iostream>
#include<set>
using namespace std;

int main() {

    int num;

    while (cin >> num &&  num != 0)
    {
        vector<string> FDs;
        bool isRedundant[num];
        vector<vector<string> > redundancies(num);

        for (int i = 0; i < num; i++)
        {
            isRedundant[i] = false;
            string fd;
            cin >> fd;
            FDs.push_back(fd)
        }

        for(int i = 0; i < FDs.size(); ++i){

            vector<string> rules(FDs);
            rules.erase(rules.begin() + i)
            set<char> closure;
            for(int j = 0; j < i; ++j){
            }
        }

    }
}
