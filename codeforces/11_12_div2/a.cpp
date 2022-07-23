#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
int a,b,c;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if((a+c-2*b)%3==0)
            cout<<0<<endl;
        else{
            cout<<1<<endl;
        }
    }
    
    
    
    return 0;
}