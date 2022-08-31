#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 15
using namespace std;
using ll = long long int;
unordered_map<string,int> us;
int m;
vector<int> g[maxn];
int a[maxn];
int ans=1e9;
void dfs(int x,int n){
    if(n>25)return;
    //cout<<'a';
    string s;
    bool fl=true;
    rep(i,1,8){
        if(a[i]!=i)fl=false;
    }
    if(fl){
        ans=min(ans,n);
        return;
    }
    rep(i,1,9){
        s+=a[i]+'0';
    }
    if(us.find(s)!=us.end()&&us[s]<=n){
        return;
    }
    us[s]=n;
    for(int v:g[x]){
        swap(a[x],a[v]);
        dfs(v,n+1);
        swap(a[x],a[v]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>m;
    rep(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,1,8){
        int in;
        cin>>in;
        a[in]=i;
    }
    rep(i,1,9){
        if(a[i]==0){
            dfs(i,0);
            break;
        }
    }
    if(ans==1e9)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}