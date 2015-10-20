#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    int dur, nrec, curmth, mthchg, prevchg;
    float val, dwnpay, lnamt, dppctg, pct[101];
    string format = "%d month%c";
    const char* fmt = format.c_str();
    char answer[11];
    vector<string> answers;
    while(scanf("%d %f %f %d", &dur, &dwnpay, &lnamt, &nrec) && dur >= 0){

        val = dwnpay + lnamt;
        dwnpay = lnamt / dur;
        prevchg = 0;
        curmth = 0;
        while(nrec--){
            scanf("%d %f", &mthchg, &dppctg);
            pct[mthchg] = dppctg;
            while(curmth < mthchg){
                pct[curmth] = pct[prevchg];
                ++curmth;
            }
            prevchg = mthchg;
        }
        for(; curmth < 101; ++curmth){
            pct[curmth] = dppctg;
        }
        curmth = 0;
        val = val - val*pct[curmth++];
        lnamt -= dwnpay;
        while(val <= lnamt){
            lnamt -= dwnpay;
            val = val - val*pct[curmth++];
        }
        sprintf(answer, fmt, curmth, curmth == 1 ? ' ' : 's');
        answers.push_back(string(answer));
    }

    for(int i = 0; i < answers.size(); ++i){
        cout << answers[i] << '\n';
    }

}
