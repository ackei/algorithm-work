#include<cstdio>
#include<map>
using namespace std;

char codes[64] = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

int P, N; long double D;
char bits[18];
char opcode[6];
char addr[12];

void readBitsNegative(long double D){
    bits[0] = '1';
    int i = 1;
    long double m = -1.0, delta = 0.5;
    while(i < 17){
        if(m + delta <= D){
            m += delta;
            bits[i] = '1';
        } else {
            bits[i] = '0';
        }
        ++i;
        delta /= 2.0;
    }
    if(m != D){
        while(bits[--i] == '1') bits[i] = '0';
        bits[i] = '1';
    }
}

void readBitsPositive(long double D){
    bits[0] = '0';
    int i = 1;
    long double delta = 0.5;
    while(i < 16){
        if(delta <= D){
            D -= delta;
            bits[i] = '1';
        } else {
            bits[i] = '0';
        }
        ++i;
        delta /= 2.0;
    }
    bits[i] = (D >= delta) ? '1' : '0';
}

void readBitsN1(){
    bits[0] = '1';
    for(int i = 1; i < 17; ++i) bits[i] = '0';
}

void readBits(long double D){
    if(D == -1.0) readBitsN1();
    else if(D < 0.0) readBitsNegative(D);
    else readBitsPositive(D);
}


int main(){

    scanf("%d", &P);
    opcode[5] = '\0';
    addr[11] = '\0';
    while(P--){
        scanf("%d %Lf", &N, &D);
        if(D < -1.0 || 1.0 <= D){
            printf("%d INVALID VALUE\n", N);
            continue;
        }
        readBits(D);
        for(int i = 0; i < 5; ++i) opcode[i] = bits[i];
        for(int i = 5; i < 16; ++i) addr[i-5] = bits[i];
        int c = (opcode[0] == '1') ? 1 : 0;
        for(int i = 1; i < 5; ++i) c = 2*c + ((opcode[i] == '1') ? 1 : 0);
        int a = (addr[0] == '1') ? 1 : 0;
        for(int i = 1; i < 11; ++i) a = a*2 + ((addr[i] == '1') ? 1 : 0);
        printf("%d %c %d %c\n", N, codes[c], a, (bits[16] == '1') ? 'D' : 'F');
    }
}
