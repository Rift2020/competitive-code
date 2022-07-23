#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],w[30],mem[30][30005];
int dfs(int x,int mon){
    int s=0;
    if(mem[x][mon]!=-1)return mem[x][mon];
    if(x>=m)return 0;
    if(mon<v[x])
        s=dfs(x+1,mon);
    else
        s=max(w[x]+dfs(x+1,mon-v[x]),dfs(x+1,mon));
    return mem[x][mon]=s;
}
int main(){
    cin>>n>>m;
    memset(mem,-1,sizeof(mem));
    for(int i=0;i<m;++i){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    cout<<dfs(0,n);
    return 0;
}