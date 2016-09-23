#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

vector<int> ns;
vector<vector<string> > texts;
int curr_prob = 0;
int curr_n;
int memo[2500][2500];
int cuts[2500][2500];
int i_printStack[2500];
int j_printStack[2500];

int format(int start, int end);
int scoreLine(int i, int j);
void printLine(int i, int j);
void print(int i, int j);

int main(){

    int n;
    string line;
    string nextWord;

    while(true){

        getline(cin, line);
        stringstream iss1(line);
        iss1 >> n;
        if(n == 0){
            break;
        }
        cout << "n: " << n << endl;
        ns.push_back(n);
        vector<string> nextText;
        while(true){
            getline(cin, line);
            if(line.size() == 0){
                break;
            }
            stringstream iss(line);
            while(iss >> nextWord){
                nextText.push_back(nextWord);
            }
        }

        texts.push_back(nextText);

    }

    for(int i = 0; i < texts.size(); ++i){

        curr_prob = i;
        curr_n = ns[curr_prob];
        memset(memo, -1, sizeof(int)*2500*2500);
        memset(cuts, -1, sizeof(int)*2500*2500);
        memset(i_printStack, -1, sizeof(int)*2500);
        memset(j_printStack, -1, sizeof(int)*2500);

        format(0, texts[i].size() - 1);
        //cout << "finished format!" << endl;
        print(0, texts[i].size() - 1);
        cout << endl;

    }

    return 0;

}

void print(int i, int j){

    //cout << "entering print! i: " << i << " j: " << j  << endl;
    if(cuts[i][j] == i || cuts[i][j] == -1){
        printLine(i, j);
    } else {
        print(i, cuts[i][j] - 1);
        print(cuts[i][j], j);
    }

}

int format(int start, int end){

    if(start == end){
        return 500;
    }
    if(memo[start][end] > 0){
        return memo[start][end];
    }

    int best_i = start,
        bestScore = scoreLine(start, end);

    for(int i = start + 1; i <= end; ++i){
        if(format(start, i - 1) + format(i, end) < bestScore){
            best_i = i;
            bestScore = format(start, i - 1) + format(i, end);
        }
    }
    //cout << "format(" << start << ", " << end << "): " << bestScore  << endl;
    //cout << "best cut: " << best_i << endl;

    memo[start][end] = bestScore;
    cuts[start][end] = best_i;

}

int scoreLine(int i, int j){

    if(i == j){
        return 500;
    }

    int cumLength = 0;
    for(int k = i; k <= j; ++k){
        cumLength += texts[curr_prob][k].size();
    }

    if(cumLength > curr_n - (j - i)){
        return 1 << 30;
    } else {
        int deficit = curr_n - (j - i) - cumLength,
            remainder = deficit % (j - i),
            quotient = deficit / (j - i);
        return remainder * (quotient + 1) * (quotient + 1)
                    + (j - i - remainder) * quotient * quotient;
    }

}

void printLine(int i, int j){

    //cout << "made it to printLine!" << endl;
    //cout << "i: " << i << " j: " << j << endl;
    int cumLength = 0;
    for(int k = i; k <= j; ++k){
        cumLength += texts[curr_prob][k].size();
    }
    //cout << "cumLength: " << cumLength << endl;

    int deficit = curr_n - (j - i) - cumLength,
        remainder,
        quotient,
        xtraStart;

    if(i == j){
        cout << texts[curr_prob][i] << endl;
        return;
    } else {
        remainder = deficit % (j - i);
        quotient = deficit / (j - i);
        xtraStart = j - i - remainder;
    }

    for(int k = i; k <= j; ++k){
        cout << texts[curr_prob][k]
             << string(quotient + 1, ' ');
        if(xtraStart > 0){
            --xtraStart;
        } else {
            cout << ' ';
        }
    }

    cout << endl;

}
