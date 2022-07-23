#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 65
#define int long long
using namespace std;
int t,n;
int a[maxn];
int n0,n1;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        n0=0;
        n1=0;
        cin>>n;
        rep(i,1,n)cin>>a[i];
        rep(i,1,n){
            if(a[i]==0)++n0;
            else if(a[i]==1)++n1;
        }
        cout<<n1*((int)(1)<<n0)<<endl;
    }

    
    
    return 0;
}