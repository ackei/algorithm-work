#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  string s = "a,b,c,d,e,f";
  cin >> n;
  s = s.substr(0,2*n-1);
  cout << "program sort(input,output);" << endl;
  cout << "var" << endl;
  cout << s << " : integer;" << endl;
  cout << "begin" << endl;
  cout << "  readln(" << s << ");" << endl;
  cout << "end." << endl;
  return 0;
}
