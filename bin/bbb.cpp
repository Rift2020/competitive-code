#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1030
#define x first
#define y second
using namespace std;
using ll = long long;
typedef pair<int,int> pr;
int n,a[maxn][maxn],cnt;
bool isin(pr lu,pr rd,pr ban){
    if(ban.x>=lu.x&&ban.x<=rd.x&&ban.y>=lu.y&&ban.y<=rd.y)return true;
    return false;
}
void solve(pr lu,pr rd,pr ban){
    if(lu==rd)return;
    pr cen={(lu.x+rd.x)/2,(lu.y+rd.y)/2};
    pr l[]={{0,0},lu,{lu.x,cen.y+1},{cen.x+1,lu.y},{cen.x+1,cen.y+1}};
    pr r[]={{0,0},cen,{cen.x,rd.y},{rd.x,cen.y},rd};
    pr ba[]={{0,0},r[1],{r[1].x,r[1].y+1},{r[1].x+1,r[1].y},l[4]};
    int wh;
    for(int i=1;i<=4;++i){
        if(isin(l[i],r[i],ban))wh=i;
    }
    int ct=++cnt;
    for(int i:{1,2,4,3}){
        if(wh==i){
            solve(l[i],r[i],ban);
        }
        else{
            a[ba[i].x][ba[i].y]=ct;
            solve(l[i],r[i],ba[i]);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pr ban;
    cin>>ban.x>>ban.y>>n;
    solve({1,1},{n,n},ban);
    rep(i,1,n){
        rep(j,1,n){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}