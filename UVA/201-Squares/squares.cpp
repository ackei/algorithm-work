#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3


using namespace std;

vector<vector<vector<bool> > > graph;

bool existsSqaure(int size, int i, int j);

int main(){

    int n, m;
    char direction;
    int x, y, countOfSize;
    int problem = 1;

    while(cin >> n >> m){

        cout << endl;
        cout << "Problem #" << problem++ << endl << endl;

        bool anySquares = false;

        for(int i = 0; i < n; ++i){
            vector<vector<bool> > newRow;
            for(int j = 0; j < n; ++j){
                vector<bool> vertex;
                for(int k = 0; k < 4; ++k){
                    vertex.push_back(false);
                }
                newRow.push_back(vertex);
            }
            graph.push_back(newRow);
        }

        for(int i = 0; i < m; ++i){
            cin >> direction >> x >> y;
            switch(direction){
                case 'H':
                    graph[x-1][y-1][EAST] = true;
                    graph[x-1][y][WEST] = true;
                    break;
                case 'V':
                    graph[y-1][x-1][SOUTH] = true;
                    graph[y][x-1][NORTH] = true;
                    break;
            }

        }

        for(int size = 1; size < n; ++size){
            countOfSize = 0;
            for(int i = 0; i < n - size; ++i){
                for(int j = 0; j < n - size; ++j){
                    if(existsSqaure(size, i, j)){
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

        cout << endl;
        cout << "****************************************" << endl;

        graph.clear();

    }

    return 0;
}

bool existsSqaure(int size, int i, int j){

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
