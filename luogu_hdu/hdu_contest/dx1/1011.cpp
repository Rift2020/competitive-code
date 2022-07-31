#include<bits/stdc++.h>
#define p 1000000007
#define int long long
using namespace std;
int inline qpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re=(x*re)%p;
        x=(x*x)%p;
        n>>=1;
    }
    return re;
}
signed main(){
    ios::sync_with_stdio(false);
    int n,m,t;
    cin>>t;
    //cout<<qpow(2,p-2)<<endl;
    while(t--){
        cin>>n>>m;
        if((n-m)%2==1)
            cout<<((n-m)*qpow(2,p-2))%p<<endl;
        else
            cout<<(n-m)/2%p<<endl;
    }


    return 0;
}
