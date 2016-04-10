#include <iostream>
#include <string>

using namespace std;

bool isYounger(int* input, int* young, int size);
bool isOlder(int* input, int* old, int size);

int main(){
  int numPeople;
  cin >> numPeople;
  string youngest, oldest, input;
  int yBDay[3], oBDay[3], iBDay[3];
  cin >> input;
  youngest = oldest = input;
  for (int i = 0; i < 3; i++){
    cin >> iBDay[i];
    yBDay[i] = oBDay[i] = iBDay[i];
  }
  for (int i = 1; i < numPeople; i++){
    cin >> input;
    for (int j = 0; j < 3; j++){
      cin >> iBDay[j];
    }
    if (isYounger(iBDay, yBDay,3)){
      youngest = input;
      for (int j = 0; j < 3; j++){ yBDay[j] = iBDay[j];}
    }
    if (isOlder(iBDay, oBDay,3)){
      oldest = input;
      for (int j = 0; j < 3; j++){ oBDay[j] = iBDay[j];}
    }
  }
  cout << youngest << endl << oldest << endl;

  return 0;
}

bool isYounger(int* input, int* young, int size){
  if (input[size-1] < young[size-1])
    return false;
  if (input[size-1] > young[size-1])
    return true;
  return isYounger(input,young,size-1);
}
bool isOlder(int* input, int* old, int size){
  if (input[size-1] > old[size-1])
    return false;
  if (input[size-1] < old[size-1])
    return true;
  return isOlder(input,old,size-1);

}

