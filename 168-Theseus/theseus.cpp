#include<map>
#include<cstdio>
#include<vector>
using namespace std;

const int NODE = 0, COL = 1, ADJ_NODE = 2;

map<char, vector<char> > adj;
map<char, bool> blocked;

int k;
char mp, tp, pp;

int main(){

    int state, ctr; char nc, cn; bool trapped;
    while(true){
        state = NODE; adj.clear(); blocked.clear();
        while(true){
            scanf("%c", &nc);
            if(nc == '#') return 0;
            switch(state){
                case NODE:{
                    cn = nc;
                    vector<char> vec;
                    adj[cn] = vec;
                    blocked[cn] = false;
                    state = COL;
                    break;
                }
                case COL:
                    if(nc == '.'){
                        scanf(" %c %c %d ", &mp, &tp, &k);
                        goto proccase;
                    }
                    if(nc == ';') state = NODE;
                    else state = ADJ_NODE;
                    break;
                case ADJ_NODE:
                    if(nc == ';') state = NODE;
                    else if(nc == '.'){
                        scanf(" %c %c %d ", &mp, &tp, &k);
                        goto proccase;
                    }
                    else adj[cn].push_back(nc);
                    break;
            }
        }
        proccase:;
        trapped = false; ctr = 0;
        while(!trapped){
            pp = tp;
            tp = mp; // Move Theseus
            ++ctr; // increment counter
            // Move Minotaur
            trapped = true;
            for(int i = 0; i < adj[mp].size(); ++i){
                if(!blocked[adj[mp][i]] && pp != adj[mp][i]){
                    trapped = false;
                    mp = adj[mp][i];
                    break;
                }
            }
            if(trapped) printf("/%c\n", mp);
            if(!trapped && ctr == k){
                ctr = 0;
                blocked[tp] = true;
                printf("%c ", tp);
            }
        }
    }

}
