#include <iostream>
#include <string>
#include <vector>

using namespace std;

void changeNeighbors(int** a, int x, int y, bool increment);

int main(){
  vector<vector<int> > solutions;
  int counts[8][8];
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      counts[i][j] = 0;
    }
  }
  
  return 0;
}

void changeNeighbors(int** a, int x, int y, bool increment){
  for (int i = 0; i < 8; i++){
    increment? a[x][i]++ : a[x][i]--;
    increment? a[i][y]++ : a[i][y]--;
  }
  int xMark1 = x, yMark1 = y, xMark2 = x, yMark2 = y;
  if (x < y){
    yMark1 = y-x;
    xMark1 = 0;
  }
  else{
    yMark1 = 0;
    xMark1 = x-y;
  }
  if (x+y < 8){
    xMark2 = 0;
    yMark2 = x+y;
  }
  else{
    xMark2 = x+y-7;
    yMark2 = 7;
  }
  while (xMark1 < 8 && yMark1 < 8){
    increment? a[xMark1++][yMark1++]++ : a[xMark1++][yMark1++]--;
  }
  while (xMark2 < 8 && yMark2 >= 0){
    increment? a[xMark2++][yMark2--]++ : a[xMark2++][yMark2--]--;
  }
}
