#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

#define ACE 0
#define KING 1
#define QUEEN 2
#define JACK 3

int main(){

    while(true){

    int valCount[4] = {0, 0, 0, 0},
        suitCount[4] = {0, 0, 0, 0},
        points = 0;
    bool suitRoyalty[4][4],
         suitStopped[4] = {false, false, false, false},
         allStopped = true;
    char card[3];
    char val,
         suit;

    memset((void*) suitRoyalty, 0, 16);

    for(int i = 0; i < 13; ++i){
        if(scanf("%s", card) == EOF){
            return 0;
        };
        val = card[0];
        suit = card[1];
        //cout << "val: " << val << " suit: " << suit << endl;
        switch(suit){
            case 'S':
                suit = 0;
                break;
            case 'H':
                suit = 1;
                break;
            case 'D':
                suit = 2;
                break;
            case 'C':
                suit = 3;
                break;
        }
        ++suitCount[suit];
        switch(val){
            case 'A':
                ++valCount[ACE];
                suitRoyalty[suit][ACE] = true;
                break;
            case 'J':
                ++valCount[JACK];
                suitRoyalty[suit][JACK] = true;
                break;
            case 'Q':
                ++valCount[QUEEN];
                suitRoyalty[suit][QUEEN] = true;
                break;
            case 'K':
                ++valCount[KING];
                suitRoyalty[suit][KING] = true;
                break;
        }
    }

    for(int i = 0; i < 4; ++i){
        if(suitRoyalty[i][ACE]){
            suitStopped[i] = true;
        } else if(suitRoyalty[i][KING] && suitCount[i] > 1){
            suitStopped[i] = true;
        } else if(suitRoyalty[i][QUEEN] && suitCount[i] > 2){
            suitStopped[i] = true;
        }

        if(suitRoyalty[i][KING] && suitCount[i] == 1){
            points -= 1;
        }

        if(suitRoyalty[i][QUEEN] && suitCount[i] <= 2){
            points -= 1;
        }

        if(suitRoyalty[i][JACK] && suitCount[i] <= 3){
            points -= 1;
        }

        if(!suitStopped[i]){
            allStopped = false;
        }

    }

    points += 4*valCount[ACE] + 3*valCount[KING] + 2*valCount[QUEEN] + valCount[JACK];

    if(points >= 16 && allStopped){
        printf("BID NO-TRUMP\n");
    } else {
        int maxSuit = 0;
        for(int i = 0; i < 4; ++i){

            if(suitCount[i] == 2){
                points += 1;
            }

            if(suitCount[i] < 2){
                points += 2;
            }

            if(0 < i){
                if(suitCount[i] > suitCount[maxSuit]){
                    maxSuit = i;
                }
            }

        }
        if(points < 14){
            printf("PASS\n");
        } else {
            switch(maxSuit){
                case 0:
                    suit = 'S';
                    break;
                case 1:
                    suit = 'H';
                    break;
                case 2:
                    suit = 'D';
                    break;
                case 3:
                    suit = 'C';
                    break;
            }
            printf("BID %c\n", suit);
        }
    }

    }


}
