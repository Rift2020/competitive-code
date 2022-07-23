//only pass 30%
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modn(ll x,ll n){
    if(x==1)return 1;
    if(n==1)return x;
    if(n%2==0)
        return (modn(x,n/2)*modn(x,n/2))%7;
    else
        return (modn(x,n/2)*((modn(x,n/2)*x)%7))%7;
}
bool isHappy(ll n){
    ll s=0;
    for(int i=1;i<=6;++i){
        s+=modn(i,n);
    }
    return s%7==0;
}
int main(){
    ll l,r,ans=0;
    cin>>l>>r;
    for(ll i=l;i<=r;++i){
        ans+=isHappy(i);
    }
    cout<<ans<<endl;
    
    return 0;
}