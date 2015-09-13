#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool increment(int* A, int numPin, int numColor);

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
    vector<vector<int> > guesses;
    vector<vector<int> > guesses2;
    vector<int> blackColors;
    vector<int> totalColors;
    for (int k = 0; k < numGuess; ++k){
      vector<int> guess(numPin);
      vector<int> guess2(numColor);
      for (int j = 0; j < numColor; guess2[j++] = 0);//Initialize guess2
      for (int j = 0; j < numPin; ++j){
        int value;
        cin >> value;
        guess[j] = value-1;
        guess2[value-1]++;
      }
      guesses.push_back(guess);
      guesses2.push_back(guess2);
      int color1, color2;
      cin >> color1;
      blackColors.push_back(color1);
      cin >> color2;
      totalColors.push_back(color1 + color2);
    }
    int guessToCheck[numPin];
    for (int j = 0; j < numPin; guessToCheck[j++] = 0);
    bool cheating = true;
    do{
      int histogram[numColor];
      for (int j = 0; j < numColor; histogram[j++] = 0);
      for (int j = 0; j < numPin; ++j){ histogram[guessToCheck[j]]++; }
      bool goodGuess = true;
      for (int j = 0; j < numGuess; ++j){
        int sumBW = 0;
        for (int k = 0; k < numColor; k++){
          if (histogram[k] < guesses2[j][k])
            sumBW += histogram[k];
          else
            sumBW += guesses2[j][k];
        }
        if (sumBW != totalColors[j]){
          goodGuess = false;
          break;
        }
        int blackCount = 0;
        for (int k = 0; k < numPin; ++k){
          if (guessToCheck[k] == guesses[j][k])
            blackCount++;
        }
        if (blackCount != blackColors[j]){
          goodGuess = false;
          break;
        }
      }
      if (goodGuess){
        for (int j = 0; j < numPin; ++j)
          cout << guessToCheck[j]+1 << " ";
        cout << endl;
        cheating = false;
        break;
      }
    }while (increment(guessToCheck, numPin, numColor));
    if (cheating)
      cout << "You are cheating!" << endl;
  }
  return 0;
}

bool increment(int* A, int numPin, int numColor){
  if (numPin <= 0)
    return false;
  if (A[numPin-1] < numColor-1){
    A[numPin-1]++;
    return true;
  }
  else if (A[numPin-1] == numColor-1){
    A[numPin-1] = 0;
    return increment(A, numPin-1, numColor);
  }
}
