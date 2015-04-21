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

void printCases(string knownOrdering, int maxDepth){

    int currentDepth = knownOrdering.length();
    char var = depthToVar(currentDepth);

    // Check for base case.
    if(currentDepth == maxDepth){
        string indent = string(maxDepth, "  ");
        // Print the first if statements.
        cout << indent << "if " << knownOrdering.at(maxDepth - 1)
             << " < " << var << " then\n";
        cout << indent << "  " << "writeln("
             << makeArguments(knownOrdering, var, i) << ")\n";
        // Print the else if statements.

        // Print the else statement.
    }

}
