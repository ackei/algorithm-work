#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct Transaction{
    char date[9];
    int checkNo;
    char amt[10];
    Transaction(char* dt, int cno, char* am) : checkNo(cno) {
        int i = 0;
        while(dt[i] != '\0'){
            date[i] = dt[i];
            ++i;
        }
        date[i] = '\0';
        i = 0;
        while(am[i] != '\0'){
            amt[i] = am[i];
            ++i;
        }
        amt[i] = '\0';
    }
    Transaction(){}
};

vector<Transaction> transactions;

bool comp(Transaction t1, Transaction t2){
    return t1.checkNo < t2.checkNo;
}

int main(){
    char date[9], amt[20], temp[10];
    int checkNo, TC, cnt, sc;
    string line;
    scanf("%d ", &TC);
    while(TC--){
        transactions.clear();
        while(getline(cin, line) && (sc = sscanf(line.c_str(), "%s %d %s", date, &checkNo, amt)) != EOF){
            if(sc == 2){
                amt[0] = '0'; amt[1] = '.'; amt[2] = '0'; amt[3] = '0'; amt[4] = '\0';
            }
            cnt = 0;
            for(int i = 0; amt[i] != '\0'; ++i){
                if(amt[i] == '.'){
                    if(i == 0){
                        int j;
                        for(j = 0; amt[j] != '\0'; ++j){
                            temp[j+1] = amt[j];
                        }
                        temp[j+1] = '\0';
                        temp[0] = '0';
                        for(int k = 0; k <= j+1; ++k){
                            amt[k] = temp[k];
                        }
                        //printf("\namt: %s\n", amt);
                    }
                    else{
                        amt[i-1] = '0';
                    }
                    break;
                }
                if(amt[i] != '0') break;
            }
            for(int i = 0; amt[i] != '.' && amt[i] != '\0'; ++i){
                if(amt[i] != '0' || cnt) ++cnt;
            }
            if(cnt < 7) transactions.push_back(Transaction(date, checkNo, amt));
        }
        sort(transactions.begin(), transactions.end(), comp);
        int nchecks = transactions.size(),
            nrows = nchecks / 3 + (nchecks % 3 == 0 ? 0 : 1), i;
        Transaction ct, pt;
        //printf("nchecks: %d nrows: %d\n", nchecks, nrows);
        for(i = 0; i + 2*nrows < nchecks; ++i){
            ct = transactions[i];
            if(i > 0) pt = transactions[i-1];
            printf("%4d%c %9s %s", ct.checkNo, (i > 0 && ct.checkNo - pt.checkNo > 1) ? '*' : ' ', ct.amt, ct.date);
            ct = transactions[i + nrows];
            pt = transactions[i + nrows - 1];
            //printf("\nct.checkNo: %d pt.checkNo: %d\n", ct.checkNo, pt.checkNo);
            printf("   %4d%c %9s %s", ct.checkNo, (ct.checkNo - pt.checkNo > 1) ? '*' : ' ', ct.amt, ct.date);
            ct = transactions[i + 2*nrows];
            pt = transactions[i + 2*nrows - 1];
            printf("   %4d%c %9s %s\n", ct.checkNo, (ct.checkNo - pt.checkNo > 1) ? '*' : ' ', ct.amt, ct.date);
        }
        for(; i < nrows; ++i){
            ct = transactions[i];
            if(i > 0) pt = transactions[i-1];
            printf("%4d%c %9s %s", ct.checkNo, (i > 0 && ct.checkNo - pt.checkNo > 1) ? '*' : ' ', ct.amt, ct.date);
            ct = transactions[i + nrows];
            pt = transactions[i + nrows - 1];
            printf("   %4d%c %9s %s\n", ct.checkNo, (ct.checkNo - pt.checkNo > 1) ? '*' : ' ', ct.amt, ct.date);
        }
        if(TC) printf("\n");
    }
}
