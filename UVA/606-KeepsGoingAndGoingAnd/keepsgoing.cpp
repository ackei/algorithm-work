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
vector<int> evalRange(string def_id, int start, int end);
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

vector<int> evalRange(string def_id, int start, int end){

    lazy_def def = lazy_defs[def_id];

    if(def.type == 0){

        vector<int> evens = evalRange(def.evenDef, start / 2, end / 2);
        vector<int> odds = evalRange(def.oddDef, start / 2, end / 2);
        vector<int> merge;

        int i;
        for(i = 0; i < evens.size(); ++i){
            merge.push_back(evens[i]);
            if(i < odds.size()){
                merge.push_back(odds[i]);
            }
        }

        if(i < odds.size()){
            merge.push_back(odds[i]);
        }

        return merge;

    } else {

        if(start < def.literals.size() && end < def.literals.size()){
            vector<int> seq(def.literals.begin() + start, def.literals.begin() + end);
            return seq;
        } else if (start < def.literals.size()){
            cout << "start < def.literals.size()" << endl;
            vector<int> head(def.literals.begin() + start, def.literals.end());
            vector<int> tail = evalRange(def.restDef, 0, end - start - 1);
            head.insert(head.end(), tail.begin(), tail.end());
            return head;
        } else {
            if(def_id == def.restDef){
                int offset = start % def.literals.size();
                cout << "offset: " << offset << endl;
                return evalRange(def_id, offset, offset + (end - start));
            } else {
                return evalRange(def.restDef, start - def.literals.size(), end - def.literals.size());
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
    tests.push_back(evalRange(def_id, start, end));

}
