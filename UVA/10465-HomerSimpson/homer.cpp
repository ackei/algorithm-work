#include<cstdio>
#include<limits>
#include<algorithm>
using namespace std;

struct Ate{
    short num,
          tr,
          tu;
    bool set;
    Ate(){num = -1; tr = numeric_limits<short>::max(); set = false; tu = 0;}
    Ate(short nm, short r, short u):num(nm), tr(r), tu(u), set(true){}
};

Ate ateMin(Ate ate1, Ate ate2){
    if(ate1.tr < ate2.tr){
        return ate1;
    } else if(ate1.tr == ate2.tr){
        return ate1.num < ate2.num ? ate2 : ate1;
    } else {
        return ate2;
    }
}

Ate memo[10001];
short m, n, t;

Ate eat(short r){
    if(r < m && r < n) return Ate(0, r > 0 ? r : 0, 0);
    if(memo[r].set) return memo[r];
    Ate m_ate, n_ate;
    if(m <= r){m_ate = eat(r-m); ++m_ate.num;}
    if(n <= r){n_ate = eat(r-n); ++n_ate.num;}
    Ate ans = ateMin(m_ate, n_ate);
    ans.set = true;
    memo[r] = ans;
    return ans;
}

int main(){

    while(scanf("%hd %hd %hd", &m, &n, &t) != EOF){
        for(int i = 1; i <= t; ++i) memo[i].set = false;
        Ate ans = eat(t);
        if(ans.tr){
            printf("%hd %hd\n", ans.num, ans.tr);
        } else {
            printf("%hd\n", ans.num);
        }
    }

}
