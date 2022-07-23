#include<bits/stdc++.h>
using namespace std;
int a[25],t,l,r;
void dfs(int k,int x){
    if(k==x){
        if(max(l,r)<t)t=max(l,r);
        return;
    }
    l+=a[x];
    dfs(k,x+1);
    l-=a[x];
    r+=a[x];
    dfs(k,x+1);
    r-=a[x];
}
int main(){
    int s[4],k,ans=0;
    for(int &i:s)cin>>i;
    for(int &i:s){
        k=i;
        for(int j=0;j<k;++j)cin>>a[j];
        t=INT_MAX;l=0;r=0;
        dfs(k,0);
        ans+=t;
    }
    cout<<ans<<endl;
    return 0;
}