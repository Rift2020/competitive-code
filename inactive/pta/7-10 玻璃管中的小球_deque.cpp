#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
int k=1;
int q;
int u,v;
int main(){
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d",&u);
        if(u==3){
            k=-k;
        }
        if(u==1)
            scanf("%d",&v);
        if(k==1){
            if(u==1)
                dq.push_back(v);
            else if(u==2&&!dq.empty())
                dq.pop_front();
        }
        else if(k==-1){
            if(u==1)
                dq.push_front(v);
            else if(u==2&&!dq.empty())
                dq.pop_back();
        }
        if(dq.empty())
            printf("-1\n");
        else
            printf("%d\n",int(dq.front()^dq.back()));
    }
    
    
    return 0;
}