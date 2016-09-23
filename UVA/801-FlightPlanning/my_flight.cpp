#include<cstdio>
#include<algorithm>
#include<cmath>
#include<limits>
using namespace std;

#define VCRUISE 400
#define AOPT 30
#define GPHOPT 2000
#define GPHEXTRA 10
#define CLIMBCOST 50

double maxDouble = numeric_limits<double>::max();
double memo[11][41][41];
double legInfo[11][3];
int K;
double cost_memo[11][41][41];
// legInfo[K][0] == tailwind at 20000
// legInfo[K][1] == tailwind at 40000
// legInfo[K][2] == length of leg

double cost(int leg, int prev_a, int cur_a){
    //printf("Entering cost(leg: %d prev_a: %d cur_a: %d)\n", leg, prev_a, cur_a);
    if(cost_memo[leg][prev_a][cur_a] != -1.0)
        return cost_memo[leg][prev_a][cur_a];
    double tailwind = (cur_a - 20.0) * ((legInfo[leg][1] - legInfo[leg][0]) / 20.0) + legInfo[leg][0];
    //double tailwind = ((cur_a - 20.0) / 20.0) * legInfo[leg][1] +
    //                  ((1.0 - (cur_a - 20.0)) / 20) * legInfo[leg][0];
    double speed = VCRUISE + tailwind;
    double distance = legInfo[leg][2],
           gph = GPHOPT + GPHEXTRA*abs(cur_a - AOPT),
           cost_to_climb = cur_a > prev_a ? (cur_a - prev_a) * CLIMBCOST : 0.0;
    double g_consumed = (distance / speed) * gph + cost_to_climb;
    //printf("g_consumed: %lf leg: %d prev_a: %d cur_a: %d tailwind: %lf speed: %lf distance: %lf gph: %lf cost_to_climb: %lf\n", g_consumed, leg, prev_a, cur_a, tailwind, speed, distance, gph, cost_to_climb);
    cost_memo[leg][prev_a][cur_a] = g_consumed;
    //printf("Exiting cost(leg: %d prev_a: %d cur_a: %d)\n", leg, prev_a, cur_a);
    return g_consumed;
}

double fly(int leg, int prev_a, int cur_a){
    //printf("Entering fly(leg: %d prev_a: %d cur_a: %d)\n", leg, prev_a, cur_a);
    if(leg == K) return cost(leg, prev_a, cur_a);
    //printf("Past the check of K: %d\n", K);
    if(memo[leg][prev_a][cur_a] != -1.0) return memo[leg][prev_a][cur_a];
    //printf("Past the memo check\n");
    double &ans = memo[leg][prev_a][cur_a] = maxDouble,
        g_consumed = cost(leg, prev_a, cur_a);
    for(int next_a = 20; next_a <= 40; ++next_a)
        ans = min(ans, g_consumed + fly(leg + 1, cur_a, next_a));
    //printf("Exiting fly(leg: %d prev_a: %d cur_a: %d)\n", leg, prev_a, cur_a);
    return ans;
}

void print_fly(int leg, int prev_a, int cur_a){
    if(leg == K) return;
    double &ans = memo[leg][prev_a][cur_a],
        g_consumed = cost(leg, prev_a, cur_a);
    for(int next_a = 20; next_a <= 40; ++next_a){
        if(g_consumed + fly(leg + 1, cur_a, next_a) == ans){
            printf(" %d", next_a);
            print_fly(leg + 1, cur_a, next_a);
            break;
        }
    }
}

int main(){

    int N;
    scanf("%d", &N);
    for(int flight = 1; flight <= N; ++flight){
        scanf("%d", &K);
        fill(&memo[0][0][0], &memo[0][0][0] + 11*41*41, -1.0);
        fill(&cost_memo[0][0][0], &cost_memo[0][0][0] + 11*41*41, -1.0);
        for(int k = 1; k <= K; ++k)
            scanf("%lf %lf %lf", &legInfo[k][2], &legInfo[k][0], &legInfo[k][1]);
        double totalCost = maxDouble;
        for(int next_a = 20; next_a <= 40; ++next_a)
            totalCost = min(totalCost, fly(1, 0, next_a));
        printf("Flight %d:", flight);
        for(int next_a = 20; next_a <= 40; ++next_a)
            if(totalCost == fly(1, 0, next_a)){
                printf(" %d", next_a);
                print_fly(1, 0, next_a);
                break;
            }
        printf(" %d\n", (int)ceil(totalCost));
    }

    return 0;

}
