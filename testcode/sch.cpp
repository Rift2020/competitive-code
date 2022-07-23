#include<iostream>
#include<algorithm>
#include <queue>
#define uint unsigned int
using namespace std;
const int n=5;
typedef struct{
    string name;
    uint arrive_time;
    uint start_time;
    uint need_time;
    uint end_time;
    string state;//waiting,running,finished
    uint priority;
}proc;
typedef pair<uint,uint> pr;//index,needtime
bool cmp_arrivetime(proc a,proc b){
    if(a.arrive_time<b.arrive_time)return true;
    return false;
}

proc p[n]={{"A",0,0,4,0,"waiting"},{"B",1,0,3,0,"waiting"},{"C",2,0,5,0,"waiting"},{"D",3,0,2,0,"waiting"},{"E",4,0,4,0,"waiting"}};

int time;
void run_proc(int i){
    if(p[i].state=="finished")
        return;
    p[i].start_time=time;
    int end_time=time+p[i].need_time;
    p[i].state="running";
    for(;time<end_time;time++)
        ;
    p[i].state="finished";
    p[i].end_time=time;
}
void FCFS(){
    for(int i=0;i<n;++i){
        for(;time<p[i].arrive_time;++time)
            ;
        run_proc(i);
    }
}
void SPF(){
    priority_queue<pr,vector<pr>,greater<pr> > pq;
    int i=0;

        while(i<n&&(pq.empty()||p[i].arrive_time>=time)){
            if(p[i].arrive_time>=time){
                pq.push({p[i].need_time,i});
                ++i;
            }
            else{
                ++time;
            }
            run_proc(pq.top().second);
            pq.pop();
        }


}
void simulate(void f()){
    for(int i=0;i<n;++i){
        p[i].state="waiting";
    }
    sort(p,p+n,cmp_arrivetime);
    time=0;
    f();
}
void print(){
    printf("procName arrive_time serve_time start_time end_time turnover_time weighted_turnover_time\n");
    for(int i=0;i<n;++i){
        printf("\t%s\t\t%d\t\t\%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n",p[i].name.c_str(),p[i].arrive_time,p[i].need_time,p[i].start_time,p[i].end_time,p[i].end_time-p[i].arrive_time,(float)(p[i].end_time-p[i].arrive_time)/p[i].need_time);
    }
}
int main(){
    simulate(FCFS);
    print();
    simulate(SPF);
    print();

    return 0;
}