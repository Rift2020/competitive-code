#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
#define x first
#define y second
using namespace std;
using ll = long long;
int a[maxn][maxn];
int n,s;
typedef pair<int,int> pr;
pr search(int u,int d,int l,int r){
    int x=(u+d)/2,y=(l+r)/2;
    if(a[x][y]==s)return {x,y};
    if(a[u][l]==s)return {u,l};
    if(a[u][r]==s)return {u,r};
    if(a[d][l]==s)return {d,l};
    if(a[d][r]==s)return {d,r};
    if(a[x][y]>s&&(x!=d||y!=r))return search(u,x,l,y);
    else if(a[x][y]<s&&(x!=u||y!=l)) return search(x,d,y,r);
    return {-1,-1};
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        rep(j,1,n)cin>>a[i][j];
    }

    cin>>s;
    pr ans=search(1,n,1,n);
    cout<<ans.x<<" "<<ans.y<<endl;
    
    return 0;
}