#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long long
#define maxn 100005
#define mod 998244353
using namespace std;
using ll = long long;
int n,nn;
vector<int> um[maxn];
int d[maxn];
int cu[maxn][3];
bool vis[maxn];
queue<int> q;
ll ans=1;
ll fact[maxn];
ll inline fpow(ll x,ll n){
    ll re=1;
    while(n){
        if(n&1)
            re=x*re%mod;
        x=x*x%mod;
        n>>=1;
    }
    return re;
}
ll C(ll m,ll n){
    ll fm=fact[m]*fact[n-m];
    fm%=mod;
    fm=fpow(fm,mod-2);
    ll fz=fact[n];
    return (fz*fm)%mod;
}
ll f(ll k)
{
    ll re=1;
    for(ll i=k;i>=2;i-=2){
        re=(re*C(2,i))%mod;
    }
    ll fm=fact[k/2];
    fm%=mod;
    fm=fpow(fm,mod-2);
    return (re*fm)%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    nn=n-1;
    fact[0]=1;
    rep(i,1,n)fact[i]=fact[i-1]*i%mod;
    rep(i,1,n-1){
        int u,v;
        cin>>u>>v;
        d[u]++;
        d[v]++;
        um[u].push_back(v);
        um[v].push_back(u);
    }
    rep(i,1,n){
        if(d[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        if(vis[tp])continue;
        vis[tp]=true;
        int adj=um[tp][0];
        um[tp].erase(um[tp].begin());
        d[tp]--;
        if(d[adj]>2){
            cu[adj][1]++;
        }
        else if(d[adj]==2){
            int adj2=um[adj][0];
            int i=0;
            if(adj2==tp){
                adj2=um[adj2][1];
                i=1;
            }
            if(adj2>2){
                cu[adj2][2]++;
            }
            else if(adj2==2){
                um[adj2].erase(um[adj2].begin()+i);
                d[adj2]--;
                nn-=3;
                q.push(adj2);
            }
        }

    }
    rep(i,1,n){
        int a1=cu[i][1],a2=cu[i][2];
        nn-=a1+2*a2;
        if(a1%2==1)++a1;
        ans=ans*max(1LL,f(a1)+a2)%mod;
    }
    if(nn>0)ans+=nn/2;
    cout<<ans<<endl;
    return 0;
}