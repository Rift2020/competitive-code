#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
#define maxn 5005
#define mod 80112002
#define ll long long
using namespace std;
int n,m;
vector<int> v[maxn];
int rd[maxn];
ll mem[maxn];
ll dfs(int x){
    if(mem[x])return mem[x];
    if(v[x].size()==0)return mem[x]=1;
    for(int i:v[x]){
        mem[x]+=dfs(i);
        mem[x]%=mod;
    }
    return mem[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    repeat(i,m){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        rd[b]++;
    }
    for(int i=1;i<=n;++i)dfs(i);
    ll ans=0;
    for(int i=1;i<=n;++i){
        if(rd[i]==0)
            ans+=mem[i];
            ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}