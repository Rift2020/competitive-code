#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10
using namespace std;
using ll = long long;
int m,n;
int a[maxn][maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    m%=n;
    m=n-m;
    rep(i,0,n-1){
        rep(j,0,n-1)cin>>a[i][j];
    }
    rep(i,0,n-1){
        rep(j,m,n+m-1){
            cout<<a[i][j%n]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}