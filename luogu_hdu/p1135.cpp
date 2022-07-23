#include<bits/stdc++.h>
using namespace std;
int l[205],lp[205],n,a,b,now,sp=0,nn;
queue<int> q;
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i){
        cin>>l[i];
    }
    memset(lp,-1,sizeof(lp));
    lp[a]=0;
    q.push(a);
    while(!q.empty()&&lp[b]==-1){
        now=q.front();
        q.pop();
        nn=now-l[now];
        if(nn>=1&&nn<=n&&lp[nn]==-1){
            lp[nn]=lp[now]+1;
            q.push(nn);
        }
        nn=now+l[now];
        if(nn>=1&&nn<=n&&lp[nn]==-1){
            lp[nn]=lp[now]+1;
            q.push(nn);
        }
    }
    cout<<lp[b]<<endl;
    return 0;
}