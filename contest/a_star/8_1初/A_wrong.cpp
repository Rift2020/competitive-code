#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
ll t,a,b,k;
ll inline fp(ll a,ll n){
    ll base=a;
    ll res=1;
    while(n){
        if(n&1)
            res=(base*res)%mod;
        base=(base*base)%mod;
        n>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        bool fl=false;
        if(k%2==1){
            fl=true;
            k=k-1;
        }
        a=((a%mod)*(fp(2,k/2)))%mod;
        b=((b%mod)*(fp(2,k/2)))%mod;
        if(fl){
            ll t=a-b;
            a=a+b;
            b=t;
        }
        cout<<a%mod<<" "<<b%mod<<endl;
    }
    
    return 0;
}