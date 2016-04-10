#include<cstdio>
#include<cmath>
using namespace std;

int p, q, r, s, t, u;
double EPS = 1e-9;

double f(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2.0) + u;
}

int sign(double x){
    return x < 0 ? -1 : 1;
}

int main(){
    double low, high;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
        if((f(0.0) < 0.0 && f(1.0) < 0.0) || (f(0.0) > 0.0 && f(1.0) > 0.0)){
            printf("No solution\n");
            continue;
        }
        low = 0.0;
        high = 1.0;
        while(abs(f((low + high) / 2.0)) > EPS){
            if(sign(f((low+high) / 2.0)) == sign(f(low))){
                low = (low + high) / 2.0;
            } else {
                high = (low + high) / 2.0;
            }
        }
        printf("%.4lf\n", (low + high) / 2.0);
    }
}
