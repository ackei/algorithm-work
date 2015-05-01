#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void printCases(string knownOrdering, int maxDepth);
string makeArguments(string knownOrdering, char var, int comparison);
string makeOrdering(string knownOrdering, char var, int rightIndex);
char depthToVar(int currentDepth);

int main(){

  int n;
  string s = "a,b,c,d,e,f";

  cin >> n;
  if(n == 1){

    cerr << "Valid values of n are: 2 <= n <= 6\n";
    exit(1);

  }

  s = s.substr(0,2*n-1);

  cout << "program sort(input,output);" << endl;
  cout << "var" << endl;
  cout << s << " : integer;" << endl;
  cout << "begin" << endl;
  cout << "  readln(" << s << ");" << endl;

  printCases("a", n);

  cout << "end." << endl;

  return 0;

}

void printCases(string knownOrdering, int maxDepth){

    int currentDepth = knownOrdering.length() + 1;
    char var = depthToVar(currentDepth);
    string indent = string(2 * currentDepth, ' ');

    // Check for base case.
    if(currentDepth == maxDepth){


        // Print the first if statements. //
        cout << indent << "if " << knownOrdering.at(maxDepth - 2)
             << " < " << var << " then\n";
        cout << indent << "  " << "writeln("
             << makeArguments(knownOrdering, var, 0) << ")\n";

        // Print the else if statements. //
        for(int i = 3; i < maxDepth + 1; ++i){

            cout << indent << "else if "
                 << knownOrdering.at(maxDepth - i)
                 << " < " << var << " then\n";
            cout << indent << "  " << "writeln("
                 << makeArguments(knownOrdering, var, i - 2) << ")\n";

        }

        // Print the else statement. //
        cout << indent << "else\n";
        cout << indent << "  " << "writeln("
             << makeArguments(knownOrdering, var, maxDepth - 1) << ")\n";

        return;

    }

    // Print the first comparison case.
    cout << indent << "if " << knownOrdering.at(currentDepth - 2)
         << " < " << var << " then\n";
    printCases(knownOrdering + var, maxDepth);

    // Print the else if comparison cases.
    for(int i = 1; i <= currentDepth - 2; ++i){

        cout << indent << "else if " << knownOrdering.at(currentDepth - (i + 2))
             << " < " << var << " then\n";
        printCases(makeOrdering(knownOrdering, var, i), maxDepth);

    }

    // Print the else case.
    cout << indent << "else\n";
    printCases(var + knownOrdering, maxDepth);

    return;

}

/*
 * knownOrdering is the currently knownOrdering. Var is the current variable
 * is being placed and varRightIndex is the position of var indexed from the
 * right.
 */
string makeArguments(string knownOrdering, char var, int varRightIndex){

    int varLeftIndex = knownOrdering.length() - varRightIndex,
        i;
    string result = "";

    for(i = 0; i < varLeftIndex; ++i){
        result = result + knownOrdering[i] + ",";
    }

    result = result + var;

    for(; i < knownOrdering.length(); ++i){
        result = result + "," + knownOrdering[i];
    }

    return result;

}

char depthToVar(int currentDepth){

    char vars[6] = {'x', 'b', 'c', 'd', 'e', 'f'};

    return vars[currentDepth - 1];

}

string makeOrdering(string knownOrdering, char var, int rightIndex){

    int leftIndex = knownOrdering.length() - rightIndex;

    string result = knownOrdering.substr(0, leftIndex) +
                    var +
                    knownOrdering.substr(leftIndex);

    return result;

}
