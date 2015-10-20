#include<cstdio>
#include<algorithm>
using namespace std;

int main(){

    int H, U, D, F, d;
    double h, u, f;
    while(scanf("%d %d %d %d", &H, &U, &D, &F) && H){
        d = 1;
        h = 0.0;
        f = U * (F / 100.0);
        do{

            h += max(0.0, (U - ((d - 1)*f)));
            if(H < h){
                break;
            }
            h -= D;
            if(h < 0.0){
                break;
            }
            ++d;

        } while(0.0 <= h && h <= H);

        printf((h <= 0.0 ? "failure on day %d\n" : "success on day %d\n"), d);

    }

}
