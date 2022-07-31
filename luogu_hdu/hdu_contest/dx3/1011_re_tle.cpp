/**
 *    author:  Rift
 *    created: 2022.07.29  10:28
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
#define maxl 21
using namespace std;
using pr = pair<int,int>;
using ll = long long;
typedef struct{
    int x,y,w;
}st;
bool operator<(st a,st b){
    return a.w<b.w;
}
int t,n,q;
st a[maxn];
int xma[maxn][maxl],xmi[maxn][maxl],yma[maxn][maxl],ymi[maxn][maxl];
//i i+2^j-1
int logn[maxn];
inline int read() {  // 快读
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
void init(){
    rep(i,1,n){
        xma[i][0]=xmi[i][0]=a[i].x;
        yma[i][0]=ymi[i][0]=a[i].y;
    }
    for(int j=1;j<=logn[n]+1;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            xma[i][j]=max(xma[i][j-1],xma[i+(1<<(j-1))][j-1]);
            xmi[i][j]=min(xmi[i][j-1],xmi[i+(1<<(j-1))][j-1]);
            yma[i][j]=max(yma[i][j-1],yma[i+(1<<(j-1))][j-1]);
            ymi[i][j]=min(ymi[i][j-1],ymi[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r,int x,int y){
    int s=logn[r-l+1];
    int xmax=max(xma[l][s],xma[r-(1<<s)+1][s]);
    int xmin=min(xmi[l][s],xmi[r-(1<<s)+1][s]);
    int ymax=max(yma[l][s],yma[r-(1<<s)+1][s]);
    int ymin=min(ymi[l][s],ymi[r-(1<<s)+1][s]);
    return max({abs(x-xmax),abs(x-xmin),abs(y-ymin),abs(y-ymax)});
}
int solve(int x,int y){
    int l=1,r=n,m=(l+r)/2;
    int ans=0;
    while(l<=r){
        m=(l+r)/2;
        int q=query(m,r,x,y);
        ans=max(ans,min(q,a[m].w));
        if(q<a[m].w){
            r=m-1;
        }
        else {
            l=m+1;
        }
    }

    return ans;
}
signed main(){
    //ios::sync_with_stdio(false),cin.tie(nullptr);
    t=read();
    logn[1]=0;
    rep(i,2,1e5+5){
        logn[i]=logn[i/2]+1;
    }
    while(t--){
        n=read(),q=read();
        rep(i,1,n){
            int x,y;
            x=read(),y=read(),a[i].w=read();
            a[i].x=x+y;
            a[i].y=x-y;
        }
        sort(a+1,a+n+1);
        init();
        rep(o,1,q){
            int a,b,x,y;
            a=read(),b=read();
            x=a+b,y=a-b;
            printf("%d\n", solve(x,y));
            //cout<<solve(x,y)<<endl;
        }
    }


    return 0;
}
