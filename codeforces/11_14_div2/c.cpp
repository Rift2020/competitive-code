#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int t;
int n;
int a[maxn];
int b[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,n-1)cin>>b[i];
        sort(a,a+n,greater<int>());
        sort(b,b+n,greater<int>());
        bool fl=true;
        for(int i=0;i<n;++i){
            if(a[i]==b[i]||a[i]==b[i]-1)continue;
            fl=false;
            break;
        }
        if(fl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}