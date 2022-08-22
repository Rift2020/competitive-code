/**
 *    author:  Rift
 *    created: 2022.08.13  20:20
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 2000005
#define int ll
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int fact[maxn],mod;
void init_fact(int n){
    fact[0]=1;
    for(int i=1;i<=n;++i)
        fact[i]=(fact[i-1]*i)%mod;
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return g;
}
int C(int n,int m){
    if(m>n)return 0;
    int fz=fact[n];
    int fm=(ll)fact[m]*fact[n-m]%mod;
    int fm_inv,y;
    exgcd(fm,mod,fm_inv,y);
    fm_inv=(fm_inv+mod)%mod;
    return (int)((ll)fz*fm_inv%mod);
}
int tp,n,m;
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m;
    mod=1e9+7;
    init_fact(n);
    cout<<C(n,m)<<endl;


    return 0;
}
