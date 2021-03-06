#include<iostream>
#include<string>
#include<iomanip>
#include<utility>
#include<vector>

using namespace std;

bool readInput();
void printInput(int setNo);
void findSolutions();
void printSolution();

int board [7][8];
bool boardAssigned [7][8];
vector<pair<int, int>> bones;

int main(){

    int setNo = 1;
    // Init bones.
    for(int i = 0; i < 7; ++i){
        for(int j = i; j < 7; ++j){
            bones.push_back(pair<int, int>(i, j));
        }
    }

    while(readInput()){

        printInput(setNo);
        findSolutions();
        ++setNo;

    }


    return 0;

}

bool readInput(){

    string line;

    for(int i = 0; i < 7; ++i){

        if(getline(cin, line)){

            for(int j = 0; j < 8; ++j){

                board[i][j] = line[2 * j] - '0';

            }

        }
        else{

            return false;

        }

    }

    return true;

}

void printInput(int setNo){


    cout << "Layout #" << setNo << ":\n\n";
    for(int i = 0; i < 7; ++i){

        for(int j = 0; j < 8; ++j){

            cout << setw(4) << board[i][j];

        }

        cout << '\n';

    }

    cout << '\n';
    cout << "Maps resulting from layout #" << setNo << "are:\n\n";

}

void findSolutions(){

}


void printSolution();
