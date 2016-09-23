#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

#define INIT 0
#define UP 1
#define DOWN 2

int main(){
    int N, v, pv, cnt, state, res, nup, ndwn, upruns, dwnruns;
    double upav, dwnav;
    string line;
    while(getline(cin, line)){
        state = INIT;
        N = cnt = 1;
        upruns = dwnruns = nup = ndwn = res = 0;
        sscanf(strtok((char*)line.c_str(), " "), "%d", &v);
        if(v == 0) return 0;
        pv = v;
        while(sscanf(strtok(NULL, " "), "%d", &v) && v != 0){
            ++N;
            switch(state){
                case INIT:
                    if(v > pv){ state = UP; ++upruns; nup = res + 1; }
                    else if(v < pv){ state = DOWN; ++dwnruns; ndwn = res + 1; }
                    else { ++res; }
                    break;
                case UP:
                    if(v >= pv) ++nup;
                    else{ state = DOWN; ++dwnruns; ++ndwn; }
                    break;
                case DOWN:
                    if(v <= pv) ++ndwn;
                    else{ state = UP; ++upruns; ++nup; }
                    break;
            }
            pv = v;
        }
        upav = upruns > 0 ? (double) nup / upruns : 0.0;
        dwnav = dwnruns > 0 ? (double) ndwn / dwnruns : 0.0;
        printf("Nr values = %d:  %6f %6f\n", N, upav, dwnav);
    }
}
