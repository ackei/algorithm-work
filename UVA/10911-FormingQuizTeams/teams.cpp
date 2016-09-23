#include<cstring>
#include<cstdio>
#include<cmath>
#include<limits>
using namespace std;

bool assigned[16] = {0};
double distances[16][16];
int N;
double homes[16][2];

double pair(int s){
    /* Base case, the last student necessarily has a partner. */
    if(s == 2*N - 1) return 0.0;
    /* Check if this student already has a partner. */
    if(assigned[s]) return pair(s + 1);
    /* Otherwise, let's find this dude's partner. */
    double best = numeric_limits<double>::max(), current;
    for(int i = s + 1; i < 2*N; ++i){
        /* If this guy already has a partner, move on. */
        if(assigned[i]) continue;
        /* Otherwise, examine the possibilities for this guy. */
        assigned[i] = true;
        current = pair(s + 1) + distances[s][i];
        if(current < best) best = current;
        assigned[i] = false;
    }
    return best;
}

int main(){

    int C = 1;

    while(scanf("%d", &N) && N){
        //memset((void*)assigned, 0, sizeof(bool)*2*N);
        for(int i = 0; i < 2*N; ++i){
            scanf("%*s %lf %lf", &homes[i][0], &homes[i][1]);
            assigned[i] = false;
        }
        for(int i = 0; i < 2*N; ++i)
            for(int j = i + 1; j < 2*N; ++j)
                distances[i][j] = sqrt(pow(homes[i][0] - homes[j][0], 2.0) + pow(homes[i][1] - homes[j][1], 2.0));
        printf("Case %d: %.2lf\n", C++, pair(0));
    }

}
