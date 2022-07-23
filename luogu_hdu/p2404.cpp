#include<bits/stdc++.h>
#define maxn 15
using namespace std;
int ans[maxn],n;
void pr(int p){
    if(p==0)return;
    cout<<ans[0];
    for(int i=1;i<=p;++i)
        cout<<'+'<<ans[i];
    cout<<endl;
}
void dfs(int x,int p){
    if(x==0)pr(p);
    ++p;
    for(int i=1;i<=x;++i){
        if(p==0||i>=ans[p-1]){
            ans[p]=i;
            dfs(x-i,p);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    dfs(n,-1);
    
    return 0;
}