#include<iostream>
#include<cstdlib>

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

bool*** graph;

using namespace std;

bool existsSqaure(int size, int i, int j, bool*** graph, int n);

int main(){

    int n, m;
    char direction;
    int x, y, countOfSize;
    bool anySquares = false;

    cin >> n;
    cin >> m;

    bool graph[n][n][4];

    graph = new bool***[n];

    for(int i = 0; i < n; ++i){
        graph[i] = new bool**[n];
        for(int j = 0; j < n; ++j){
            graph[i][j] = new bool[4];
            for(int k = 0; k < 4; ++k){
                graph[i][j][k] = false;
            }
        }
    }

    for(int i = 0; i < m; ++i){

        cin >> direction >> x >> y;
        switch(direction){
            case 'H':
                graph[x][y][EAST] = true;
                graph[x][y+1][WEST] = true;
                break;
            case 'V':
                graph[y][x][SOUTH] = true;
                graph[y][x+1][NORTH] = true;
                break;
        }

    }

    for(int size = 1; size < n; ++size){
        countOfSize = 0;
        for(int i = 0; i < n - size; ++i){
            for(int j = 0; j < n - size; ++j){
                if(existsSqaure(size, i, j, graph, n)){
                    ++countOfSize;
                }
            }
        }
        if(countOfSize){
            anySquares = true;
            cout << countOfSize << " square (s) of size " << size << endl;
        }
    }

    if(!anySquares){
        cout << "No completed squares can be found." << endl;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            delete graph[i][j];
        }
        delete graph[i];
    }


    return 0;
}

bool existsSqaure(int size, int i, int j, bool*** graph, int n){

    for(int step = 0; step < size; ++step){
        if(!(graph[i][j + step][EAST] && graph[i + size][j + step][EAST])){
            return false;
        }
        if(!(graph[i + step][j][SOUTH] && graph[i + step][j + size][SOUTH])){
            return false;
        }
    }

    return true;

}
