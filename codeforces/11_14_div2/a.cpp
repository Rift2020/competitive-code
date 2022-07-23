#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
ll t,a,b,x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b;
        x=-a*a;
        y=b*b;
        cout<<x<<" "<<y<<endl;
    }
    
    
    
    return 0;
}