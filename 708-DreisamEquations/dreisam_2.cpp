#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;

bool E();
void L();
bool T();
bool Ep();

#define LPAREN 0
#define RPAREN 1
#define NUM 2
#define EOEQ 3
#define EQUAL 4

struct Token{
    int type;
    int val;
} currtoken;

int stack[11], *top = stack, left_side, TC, result;
char equation[81],
     *eq_ptr,
     ops[11],
     *ops_ptr = ops;

void getToken(){

    //cout << "entering getToken()" << endl;
    while(isspace(*eq_ptr)){ ++eq_ptr;}
    if(isdigit(*eq_ptr)){
        currtoken.type = NUM;
        currtoken.val = 0;
        while(isdigit(*eq_ptr)){
            currtoken.val *= 10;
            currtoken.val += *eq_ptr - '0';
            ++eq_ptr;
        }
    } else if (*eq_ptr == '('){
        currtoken.type = LPAREN;
        ++eq_ptr;
    } else if(*eq_ptr == ')'){
        currtoken.type = RPAREN;
        ++eq_ptr;
    } else if(*eq_ptr == '='){
        currtoken.type = EQUAL;
        ++eq_ptr;
    } else if(*eq_ptr == '\0'){
        currtoken.type = EOEQ;
    }
    //cout << "currtoken type: " << currtoken.type << " value: " << currtoken.val << endl;

}

bool match(int TK_TYPE){
    //cout << "Entering match " << TK_TYPE << endl;
    if(currtoken.type == TK_TYPE){
        if(currtoken.type != EOEQ) getToken();
        return true;
    } else {
        printf("Error: Malformed expression\n");
        return false;
    }
}

void S(){
    //cout << "Entering S" << endl;
    getToken();
    L();
    if(E()){
        match(EOEQ);
        // Print the solution here.
        printf("There is a solution!\n");
    } else {
        // Print impossible here.
        printf("Impossible!\n");
    }
}

bool E(){
    //cout << "Entering E" << endl;
    T();
    return Ep();
}

void L(){
    //cout << "Entering L" << endl;
    if(currtoken.type != NUM){
        printf("Error: Malformed expression.\n");
    }
    result = currtoken.val;
    getToken();
    match(EQUAL);
}

bool T(){
    //cout << "Entering T" << endl;
    if(currtoken.type == LPAREN){
        match(LPAREN);
        return E();
        //match(RPAREN);
    } else if(currtoken.type == NUM){
        *top = currtoken.val;
        ++top;
        getToken();
    } else {
        printf("Error: Malformed expression.\n");
    }
    return false;
}

bool Ep(){
    //cout << "Entering Ep" << endl;
    char* eq_memo = eq_ptr;
    int right_op, left_op;
    if(currtoken.type != RPAREN){
        if(T()) return true;
    } else {
        getToken();
    }
    --top;
    right_op = *top;
    --top;
    left_op = *top;
    *top = left_op + right_op;
    ++top;
    *ops_ptr = '+';
    ++ops_ptr;
    //cout << left_op << "+" << right_op << ": " << left_op + right_op << endl;
    if(currtoken.type == EOEQ){
        if(left_op + right_op == result) return true;
    } else {
        if(Ep()) return true;
    }
    --top;
    *top = left_op - right_op;
    ++top;
    --ops_ptr;
    *ops_ptr = '-';
    ++ops_ptr;
    eq_ptr = eq_memo;
    getToken();
    //cout << left_op << "-" << right_op << ": " << left_op - right_op << endl;
    if(currtoken.type == EOEQ){
        if(left_op - right_op == result) return true;
    } else {
        if(Ep()) return true;
    }
    --top;
    *top = left_op * right_op;
    ++top;
    --ops_ptr;
    *ops_ptr = '*';
    ++ops_ptr;
    eq_ptr = eq_memo;
    getToken();
    //cout << left_op << "*" << right_op << ": " << left_op * right_op << endl;
    if(currtoken.type == EOEQ){
        if(left_op * right_op == result) return true;
    } else {
        if(Ep()) return true;
    }
    eq_ptr = eq_memo;
    --ops_ptr;
    --top;
    *top = left_op;
    //cout << "*top: " << *top << endl;
    ++top;
    ++top;
    return false;
}

int main(){

    while(scanf("%[^\n]\n", equation)){
        if(equation[1] == '\0') return 0;
        eq_ptr = equation;
        S();
    }

    return 0;

}
