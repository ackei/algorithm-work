#include<iostream>
#include<vector>

using namespace std;

int main(){
  int numGames;
  cin >> numGames;
  for (int i = 0; i < numGames; ++i){
    int numPin;
    int numColor;
    int numGuess;
    cin >> numPin;
    cin >> numColor;
    cin >> numGuess;
    vector<int*> guesses;
    vector<int*> guesses2;
    for (int k = 0; k < numGuess; ++k){
      int guess[numPin];
      int guess2[numColor];
      for (int j = 0; j < numColor; guess[j++] = 0);//Initialize guess2
      for (int j = 0; j < numPin; ++j){
        int value;
        cin >> value;
        guess[j] = value;
        guess2[value]++;
      }
      guesses.push_back(guess);
      guesses2.push_back(guess2);
    }
    int currentGuess[numPin];
  }
  return 0;
}
