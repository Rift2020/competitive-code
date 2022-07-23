#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 205
using namespace std;
using ll = long long;
int n;
int a[maxn][maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        rep(j,i+1,n){
            cin>>a[i][j];
        }
    }
    rep(d,2,n-1){
        rep(l,1,n-d){
            int r=l+d;
            rep(i,l+1,r-1){
                a[l][r]=min(a[l][r],a[l][i]+a[i][r]);
            }
        }
    }
    cout<<a[1][n]<<endl;
    
    return 0;
}