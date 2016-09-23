#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > generateSequences(int maxValue, int maxLength);

vector<vector<int> > helperGenerator(vector<vector<int> > result, int maxValue, int maxLength, int currentLength);

int main(){
	int numDatasets;
	cin >> numDatasets;
	for (int count = 0; count < numDatasets; ++count){
		int m,n;
		cin >> m;
		cin >> n;
		vector<vector<int> > list;
		list = generateSequences(m,n);

		int size = list.size();

		string binary;

		cin >> binary;

		int min = 1;
		int max = size;

		for (int i = 2; min != max; ++i){
			if (binary[i] == '0'){
				max = (min+max)/2;
			}
			else
				min = (min+max)/2 + 1;
		}

		vector<int> answer = list[min-1];

		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << " ";
		}
		cout << "\n\n";
	}


	return 0;
}

vector<vector<int> > generateSequences(int maxValue, int maxLength){
	vector<vector<int> > list;
	vector<int> tuple;
	for (int i = 1; i <= maxValue; i++){
		tuple.clear();
		tuple.push_back(i);
		list.push_back(tuple);
	}
	return helperGenerator(list,maxValue,maxLength,1);
}

vector<vector<int> > helperGenerator(vector<vector<int> > result, int maxValue, int maxLength, int currentLength){
	if (currentLength == maxLength)
		return result;
	else{
		vector<vector<int >> newResult;
		for (int i = 0; i < result.size(); i++){
			vector<int>* currentTuple = &result[i];
			for (int j = currentTuple->back(); j <= maxValue; ++j){
				vector<int> temp(result[i]);
				if (j > temp.size()){
					temp.push_back(j);
					newResult.push_back(temp);
				}
			}
		}
		return helperGenerator(newResult, maxValue, maxLength, ++currentLength);
	}
}