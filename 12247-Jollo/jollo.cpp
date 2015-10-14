#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){

    int she[3], he[2],
        her_ptr,
        his_losses;
    //bool dealt[53];
    while(scanf("%d %d %d %d %d", she, she + 1,she + 2, he, he + 1)
            && she[0]){

        bool dealt[53] = {false};
        dealt[she[0]] = true;
        dealt[she[1]] = true;
        dealt[she[2]] = true;
        dealt[he[0]] = true;
        dealt[he[1]] = true;

        sort(she, she+3);
        sort(he, he+2);
        her_ptr = 0;
        his_losses = 0;

        while(her_ptr < 3 && she[her_ptr] < he[0]){
            ++her_ptr;
        }

        // He has to win two rounds with these two cards.
        // Give him the minimum possible card.
        if(her_ptr == 3){
            int i = 1;
            while(dealt[i]){
                ++i;
            }
            printf("%d\n", i);
        }
        // The worst he can do is lose at most once with these cards.
        // Give him the min card greater than she[1]
        else if(her_ptr == 2){
            int i = she[1];
            while(dealt[i] && i < 53){
                ++i;
            }
            if(i == 53){
                printf("-1\n");
            } else {
                printf("%d\n", i);
            }
        } else if(her_ptr <= 1){
            ++her_ptr;
            while(her_ptr < 3 && she[her_ptr] < he[1]){
                ++her_ptr;
            }
            if(her_ptr < 3){
                printf("-1\n");
            } else {
                int i = she[2];
                while(dealt[i] && i < 53){
                    ++i;
                }
                if(i == 53){
                    printf("-1\n");
                } else {
                    printf("%d\n", i);
                }
            }
        }

    }

}
