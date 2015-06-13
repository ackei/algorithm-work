#include<iostream>

using namespace std;

int leastPower(int num);

int main(){
  int count;
  cin >> count;
  for (int i = 0; i < count; i++){
    int answer = 0;
    int num;
    cin >> num;
    int power = leastPower(num);
    int powerFive = 1;
    for (int j = 1; j <= power; j++){
      powerFive *= 5;
      answer += (num/powerFive);
    }
    cout << answer << endl;
  }
  return 0;
}

int leastPower(int num){
  if (num < 5)
    return 0;
  else
    return leastPower(num/5) + 1;
}

