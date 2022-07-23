#include<bits/stdc++.h>
#define ll long long
#define p 19260817
using namespace std;
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(m<0){
        cout<<pow(n,m)<<endl;
        return 0;
    }
    if(m==0){
        cout<<"1\n";
        return 0;
    }
    ll s=1;
    for(int i=1;i<=m;++i){
        s=(s*(n%p))%p;
    }
    cout<<s<<endl;
    return 0;
}