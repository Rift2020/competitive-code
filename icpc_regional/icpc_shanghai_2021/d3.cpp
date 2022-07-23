#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int a,b,p,q,t;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>p>>q;
        if(p>=q*2&&fabs((int)sqrt(p*p-4*q*q)-sqrt(p*p-4*q*q))<=1e-6){
            cout<<(p-(int)(sqrt(p*p-4*q*q+1)))<<" "<<2*q<<endl;
        }
        else{
            cout<<0<<" "<<0<<endl;
        }
    }
    
    
    
    return 0;
}