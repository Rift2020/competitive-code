#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 370
#define maxm 5005
using namespace std;
using ll = long long;
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m,k;
vector<int> v[maxn];
vector<int> u;
int dp[maxm];
int ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    rep(i,1,n){
        int a,b,c;
        cin>>a>>b>>c;
        v[mon[a-1]+b].push_back(c);
    }
    rep(i,1,n){
        if(v[i].empty())continue;
        rep(j,1,k){

        }
    }
    
    return 0;
}