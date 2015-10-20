#include<cstdio>
#include<iostream>
using namespace std;

int main(){

    int TC, Y, c = 1, ptr, skip;
    char cards[52][3];
    scanf("%d", &TC);
    while(TC--){
        //cout << "Entering while loop." << endl;
        for(int i = 0; i < 52; ++i){
            scanf("%s", cards[i]);
            //cout << "cards[" << i << "]: " << cards[i] << " ";
        }
        //cout << endl << "Out of while loop." << endl;
        Y = 0;
        ptr = 26;
        skip = 0;
        for(int i = 0; i < 3; ++i){
            //cout << "cards[ptr]: " << cards[ptr] << endl;
            //cout << "Y: " << Y << " ptr: " << ptr << " skip: " << skip << endl;
            switch(cards[ptr][0]){
                case 'A':
                case 'K':
                case 'Q':
                case 'J':
                case 'T':
                    Y += 10;
                    ++skip;
                    --ptr;
                    break;
                default:
                    ////cout << "cards[ptr][0]: " << cards[ptr][0] << endl;
                    //cout << "cards[ptr][0] - '0': " << cards[ptr][0] - '0' << endl;
                    Y += cards[ptr][0] - '0';
                    skip += (11 - (cards[ptr][0] - '0'));
                    ptr -= (11 - (cards[ptr][0] - '0'));
                    break;
            }
        }
        --Y;
        if(Y <= ptr){
            printf("Case %d: %s\n", c++, cards[Y]);
        } else {
            ptr = skip + Y;
            printf("Case %d: %s\n", c++, cards[ptr]);
        }
    }

}
