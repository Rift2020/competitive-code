#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int a[maxn];
int t,n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,0,n-1)cin>>a[i];
        sort(a,a+n);
        cout<<a[n-2]+a[n-1]<<endl;
    }
    
    
    
    return 0;
}