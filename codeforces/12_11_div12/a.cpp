#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,2,n+1){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}