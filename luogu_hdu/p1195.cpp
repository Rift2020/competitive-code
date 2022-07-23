#include<bits/stdc++.h>
#define maxn 1005
#define maxm 100005
using namespace std;
struct st{
    int x,y,l;
}s[maxm];
bool operator<(struct st x,struct st y){
    return x.l<y.l;
}
int n,m,k;
int fa[maxn];
int sf(int x){
    if(x==fa[x])return x;
    return fa[x]=sf(fa[x]);
}
void mf(int x,int y){
    int fx=sf(x);
    int fy=sf(y);
    fa[fx]=fy;
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<=n;++i)fa[i]=i;
    for(int i=0;i<m;++i){
        cin>>s[i].x>>s[i].y>>s[i].l;
    }
    sort(s,s+m);
    int need=n-k;
    int now=0;
    int ans=0;
    for(int i=0;i<m;++i){
        if(sf(s[i].x)!=sf(s[i].y)){
            now++;
            ans+=s[i].l;
            mf(s[i].x,s[i].y);
        }
        if(now==need)break;
    }
    if(now==need)cout<<ans<<endl;
    else cout<<"No Answer"<<endl;
    return 0;
}