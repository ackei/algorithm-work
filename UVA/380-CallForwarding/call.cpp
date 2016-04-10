#include<cstdio>
#include<vector>
using namespace std;

struct Forward{
    int start;
    int duration;
    int forward;
    Forward(int s, int d, int f) : start(s), duration(d), forward(f) {}
};

struct Call{
    int time;
    int extension;
    Call(int t, int e) : time(t), extension(e){}
};

void route(Call call, vector<vector<Forward> >& forwards, bool first);

int origExt;

int main(){

    int N, count = 1;
    int ext, start, dur, fwd;
    scanf("%d", &N);
    printf("CALL FORWARDING OUTPUT\n");
    while(N--){
        printf("SYSTEM %d\n", count++);
        vector<vector<Forward> > forwards(10000);
        while(scanf("%d", &ext) && ext){
            scanf("%d %d %d", &start, &dur, &fwd);
            forwards[ext].push_back(Forward(start, dur, fwd));
        }
        vector<Call> calls;
        while(scanf("%d", &start) && start != 9000){
            scanf("%d", &ext);
            calls.push_back(Call(start, ext));
        }
        for(int i = 0; i < calls.size(); ++i){
            origExt = calls[i].extension;
            route(calls[i], forwards, true);
        }
    }

    printf("END OF OUTPUT\n");

}

void route(Call call, vector<vector<Forward> >& forwards, bool first){
    if(!first && call.extension == origExt){
        printf("AT %04d CALL TO %04d RINGS 9999\n", call.time, origExt);
        return;
    }
    for(int i = 0; i < forwards[call.extension].size(); ++i){
        if(forwards[call.extension][i].start <= call.time &&
           call.time <= forwards[call.extension][i].start + forwards[call.extension][i].duration){
                call.extension = forwards[call.extension][i].forward;
                route(call, forwards, false);
                return;
           }
    }
    printf("AT %04d CALL TO %04d RINGS %04d\n", call.time, origExt, call.extension);
}
