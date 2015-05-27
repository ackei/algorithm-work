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
            isRedundant[i] = true;
            string fd;
            cin >> fd;
            FDs.push_back(fd);
        }

        for(int i = 0; i < FDs.size(); ++i){

            vector<string> rules(FDs);
            set<char> closure;
	    string output;
	    // Parse left hand side of rules[i]
	    int k = 0;
	    while (rules[i][k] != '-')
	    {
		closure.insert(rules[i][k++]);
	    } 
	    k += 2;
	    output = rules[i].substr(k, rules[i].length() - k);
            rules.erase(rules.begin() + i);
            for(int j = 0; j < rules.size(); ++j){
		
		k = 0; 
		bool allowed = true;
	    	while (rules[j][k] != '-')
	    	{

		     if (closure.find(rules[j][k]) == closure.end()) 
		     {
				allowed = false;
				break;
		     }

		     //closure.insert(rules[j][k++]);
	    	} 
	    	k += 2;
	    	string heyman = rules[j].substr(k, rules[j].length() - k);
            	if (allowed)
		{
		 for (int count = 0; count < heyman.length(); count++)
		 {
			closure.insert(heyman[count]);
		 }
			rules.erase(rules.begin() + j);
		}

            }
		
	    for (int whatuppp = 0; whatuppp < output.length(); whatuppp++)
	    {
		if (closure.find(output[whatuppp]) == closure.end())
		{
			isRedundant[i] = false;
			cout << "I am L and I am not redundant" << endl;
			break;
		}
	    }
		
        }

    }
}
