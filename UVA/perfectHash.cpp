#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int wordsToNumbers(int* a, string s);

int main(){
  int a[13];
  string s;
  while (getline(cin,s)){
    cout << s << endl;
    int n = wordsToNumbers(a,s);
    int answer = a[0];
    bool cont = true;
    while (cont){
      cont = false;
      for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
          if (answer/a[j] % n == answer/a[i] % n){
            cont = true;
            if ((answer/a[j] + 1) * a[j] < (answer/a[i] + 1) * a[i])
              answer = (answer/a[j] + 1) * a[j];
           else
             answer = (answer/a[i] + 1) * a[i];
          }
        }
      }
    }
    cout << answer << endl;
    cout << endl;
  }
  return 0;
}

int wordsToNumbers(int* a, string s){
  int aIndex = 0;
  int j = 0;
  for (int i = 0; i < s.length(); i=j){
    for (j = i; isspace(s[j]); j++);
    int num = 0;
    for (;!(isspace(s[j])) && j < s.length();j++){
      int temp = (int)(s[j]) - (int)('a') + 1;
      num = (num << 5) + temp;
    }
    a[aIndex++] = num;
  }
  return aIndex;
}
