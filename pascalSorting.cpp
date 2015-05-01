#include <iostream>
#include <string>

using namespace std;

void printCases(string knownOrdering, int maxDepth);
string makeArguments(string knownOrdering, char var, int comparison);
string makeOrdering(string knownOrdering, char var, int rightIndex);
char depthToVar(int currentDepth);

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
  printCases("a", 1, n);
  cout << "end." << endl;

  return 0;

}

void printCases(string knownOrdering, int maxDepth){

    int currentDepth = knownOrdering.length() + 1;
    char var = depthToVar(currentDepth);
    string indent = string(currentDepth, "  ");

    // Check for base case.
    if(currentDepth == maxDepth){


        // Print the first if statements. //
        cout << indent << "if " << knownOrdering.at(maxDepth - 2)
             << " < " << var << " then\n";
        cout << indent << "  " << "writeln("
             << makeArguments(knownOrdering, var, 0) << ")\n";

        // Print the else if statements. //
        for(int i = 2; i < maxDepth; ++i){

            cout << indent << "else if "
                 << knownOrdering.at(maxDepth - i)
                 << " < " << var << " then\n";
            cout << indent << "  " << "writeln("
                 << makeArguments(knownOrdering, var, i - 1) << ")\n";

        }

        // Print the else statement. //
        cout << indent << "else\n";
        cout << indent << "  " << << "writeln("
             << makeArguments(knownOrdering, var, maxDepth - 1) << ")\n";

        return;

    }

    // Print the first comparison case.
    cout << indent << "if " << knownOrdering.at(currentDepth - 2)
         << " < " << var << " then\n";
    printCases(knownOrdering + var, maxDepth);

    // Print the else if comparison cases.
    for(int i = 1; i < currentDepth - 2; ++i){

        cout << indent << "else if " << knownOrdering.at(currentDepth - (i + 1))
             << " < " << var << "then\n";
        printCases(makeOrdering(knownOrdering, var, i), maxDepth);

    }

    // Print the else case.
    cout << indent << "else\n"
    printCases(var + knownOrdering, maxDepth);

    return;

}

/*
 * knownOrdering is the currently knownOrdering. Var is the current variable
 * is being placed and varRightIndex is the position of var indexed from the
 * right.
 */
string makeArguments(string knownOrdering, char var, int varRightIndex){

    int varLeftIndex = 

}

char depthToVar(int currentDepth){

}

string makeOrdering(string knownOrdering, char var, int rightIndex){

}
