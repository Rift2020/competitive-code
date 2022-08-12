/**
 *    author:  Rift
 *    created: 2022.08.12  14:59
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
#define ll __int128
using namespace std;
//using ll = long long;
using pr = pair<int,int>;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll g=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return g;
}
ll exCRT(long long a[],long long m[],int k){
    ll anow=a[1],mnow=m[1];
    for(int i=2;i<=k;++i){
        ll x,y,g;
        g=exgcd(mnow,-m[i],x,y);
        //if((a[i]-anow)%g!=0)return -1;//无解情形
        x=x*((a[i]-anow)/g);
        anow=x*mnow+anow;
        mnow=lcm(mnow,(ll)m[i]);
        anow=(anow%mnow+mnow)%mnow;
    }
    return (anow%mnow+mnow)%mnow;
}
long long a[maxn],m[maxn],k;
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>k;
    rep(i,1,k){
        cin>>m[i]>>a[i];
    }
    cout<<(long long)(exCRT(a,m,k))<<endl;


    return 0;
}
