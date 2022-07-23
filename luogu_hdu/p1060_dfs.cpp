#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],w[30];
int dfs(int x,int mon){
    int s=0;
    if(x>=m)return 0;
    if(mon<v[x])
        s+=dfs(x+1,mon);
    else
        s+=max(w[x]+dfs(x+1,mon-v[x]),dfs(x+1,mon));
    return s;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    cout<<dfs(0,n);
    return 0;
}