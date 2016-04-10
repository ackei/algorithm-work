#include<cstdio>
#include<map>
using namespace std;

int N, M;
bool scents[1 << 6][1 << 6] = {false};
map<char, char> left = {{'N', 'W'}, {'W', 'S'}, {'S', 'E'}, {'E', 'N'}};
map<char, char> right = {{'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'}};
map<char, int> dy = {{'N', 1}, {'S', -1}, {'E', 0}, {'W', 0}};
map<char, int> dx = {{'N', 0}, {'S', 0}, {'E', 1}, {'W', -1}};

int main(){

    int x, y, px, py, nx, ny; char dir, ins; bool lost = false;
    scanf("%d %d", &N, &M);

    while(scanf("%d %d %c ", &x, &y, &dir) != EOF){
        lost = false;
        while(scanf("%c", &ins), ins != '\n'){
            if(lost) continue;
            switch(ins){
                case 'L':
                    dir = left[dir];
                    break;
                case 'R':
                    dir = right[dir];
                    break;
                case 'F':
                    px = x; py = y;
                    nx = x + dx[dir]; ny = y + dy[dir];
                    if(scents[x][y])
                        if(nx < 0 || N < nx || ny < 0 || M < ny)
                            break;
                    x = nx; y = ny;
                    break;
            }
            if(x < 0 || N < x || y < 0 || M < y){
                lost = true;
                scents[px][py] = true;
            }
        }

        if(!lost) printf("%d %d %c\n", x, y, dir);
        else printf("%d %d %c LOST\n", px, py, dir);

    }
}
