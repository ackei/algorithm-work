#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<cctype>
using namespace std;

struct lazy_def{
    int type; // 0 if zip, 1 otherwise.
    string id;
    // Attributes for zip type definitions.
    string evenDef;
    string oddDef;
    // Attributes for literal type defintions.
    vector<int> literals;
    string restDef;
};

map<string, lazy_def> lazy_defs;
vector<vector<int> > tests;

bool isNumber(string s);
int eval(string def_id, int index);
void readDef();
void doTest();

int main(){

    int numDefs,
        numTests;

    cin >> numDefs >> numTests;

    for(int i = 0; i < numDefs; ++i){
        readDef();
    }
    for(int i = 0; i < numTests; ++i){
        doTest();
    }

    for(int i = 0; i < tests.size(); ++i){
        for(int j = 0; j < tests[i].size(); ++j){
            cout << tests[i][j];
            if(j < tests[i].size() - 1){
                cout << ' ';
            }
        }
        cout << endl;
    }

}

int eval(string def_id, int index){

    lazy_def def = lazy_defs[def_id];

    while(true){

        if(def.type == 0){ // It is a zip.

            if(index % 2 == 0){
                def = lazy_defs[def.evenDef];
            } else {
                def = lazy_defs[def.oddDef];
            }
            index /= 2;

        } else { // It is a bunch of literals followed by a def

            if(index < def.literals.size()){
                return def.literals[index];
            } else {
                if(def.restDef == def.id){
                    return def.literals[index % def.literals.size()];
                } else {
                    index -= def.literals.size();
                    def = lazy_defs[def.restDef];
                }
            }
        }
    }

}

void readDef(){

    string defLine;
    lazy_def newDef;
    string name;
    string peek;
    cin >> name;
    cin >> peek; // Get the = sign.
    cin >> peek;

    newDef.id = name;

    if(peek == "zip"){
        newDef.type = 0;
        string evenDef,
               oddDef;
        cin >> evenDef;
        cin >> oddDef;
        newDef.evenDef = evenDef;
        newDef.oddDef = oddDef;
    } else {
        newDef.type = 1;
        vector<int> literals;
        literals.push_back(atoi(peek.c_str()));
        do{
            cin >> peek;
            if(isNumber(peek)){
                literals.push_back(atoi(peek.c_str()));
            } else {
                newDef.literals = literals;
                newDef.restDef = peek;
                break;
            }
        } while(true);
    }

    lazy_defs.insert(pair<string, lazy_def>(name, newDef));

}

bool isNumber(string s){

    for(int i = 0; i < s.length(); ++i){
        if(!isdigit(s[i])){
            return false;
        }
    }

    return true;

}

void doTest(){

    string def_id;
    vector<int> elements;
    int start,
        end;

    cin >> def_id >> start >> end;
    for(int i = start; i <= end; ++i){
        elements.push_back(eval(def_id, i));
    }

    tests.push_back(elements);

}
