#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

bool minEval();
bool maxEval();

int board[5][5];

void printBoard(){

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;;

}


bool maxEval(){

    bool noMoves = true;
    for(int i = 4; 0 <=  i; --i){
        for(int j = 4; 0 <= j; --j){
            if(board[i][j]){
                noMoves = false;
                board[i][j] = 0;

                cout << "max: " << endl;
                printBoard();

                if(minEval()){
                    cout << "max return true" << endl;
                    board[i][j] = 1;
                    return true;
                }
            } else {
                continue;
            }
            int b = i - 1;
            while(0 <= b && board[b][j]){
                board[b][j] = 0;

                cout << "max: " << endl;
                printBoard();

                if(minEval()){
                    for(int k = b; k <= i; ++k){
                        board[k][j] = 1;
                    }
                    //cout << "max return true" << endl;
                    return true;
                }

                --b;
            }
            for(int k = b + 1; k < i; ++k){
                board[k][j] = 1;
            }
            b = j - 1;
            while(0 <= b && board[i][b]){
                board[i][b] = 0;

                cout << "max: " << endl;
                printBoard();

                if(minEval()){
                    for(int k = b; k <= j; ++k){
                        board[i][k] = 1;
                    }
                    //cout << "max return true" << endl;
                    return true;
                }

                --b;
            }
            for(int k = b + 1; k < j; ++k){
                board[i][k] = 1;
            }
            board[i][j] = 1;
        }
    }

    if(noMoves){
        //cout << "max return true" << endl;
    } else {
        //cout << "max return false" << endl;
    }
    return noMoves ? true : false;

}

bool minEval(){

    bool noMoves = true;
    for(int i = 4; 0 <= i; --i){
        for(int j = 4; 0 <= j; --j){
            if(board[i][j]){
                noMoves = false;
                board[i][j] = 0;

                //cout << "min: " << endl;
                //printBoard();

                if(!maxEval()){
                    board[i][j] = 1;
                    //cout << "min return false" << endl;
                    return false;
                }
            } else {
                continue;
            }
            int b = i - 1;
            while(0 <= b && board[b][j]){
                board[b][j] = 0;

                //cout << "min: " << endl;
                //printBoard();

                if(!maxEval()){
                    for(int k = b; k <= i; ++k){
                        board[k][j] = 1;
                    }
                    //cout << "min return false" << endl;
                    return false;
                }

                --b;
            }
            for(int k = b + 1; k < i; ++k){
                board[k][j] = 1;
            }
            b = j - 1;
            while(b >= 0 && board[i][b]){
                board[i][b] = 0;

                //cout << "min: " << endl;
                //printBoard();

                if(!maxEval()){
                    for(int k = b; k <= j; ++k){
                        board[i][k] = 1;
                    }
                    //cout << "min return false" << endl;
                    return false;
                }

                --b;
            }
            for(int k = b + 1; k < j; ++k){
                board[i][k] = 1;
            }
            board[i][j] = 1;
        }
    }

    return noMoves ? false : true;

}

int main(){

    int c;
    scanf("%d", &c);
    while(c--){

        memset((void*)board, 0, 25*sizeof(int));
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                scanf("%d", &board[i][j]);
            }
        }

        printf((maxEval() ? "winning\n" : "losing\n"));

    }

}
