#include<bits/stdc++.h>
#define maxn 200005
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
ll n,m,ans;
int fa[maxn];
struct st{
    int u,v,k;
};
bool operator<(const st &a,const st &b){
    return a.k<b.k;
}
int f(int x){
    if(fa[x]==x)return x;
    return fa[x]=f(fa[x]);
}
void mg(int x,int y){
    int fx=f(x);
    int fy=f(y);
    fa[fx]=fy;
}
st ar[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=0;i<m;++i){
        int u,v,k;
        cin>>u>>v>>k;
        ar[i]=st{u,v,k};
    }
    sort(ar,ar+m);
    for(int i=0;i<m;++i){
        int u=ar[i].u,v=ar[i].v,k=ar[i].k;
        if(f(u)!=f(v))mg(u,v);
        else{
            ans+=max(0,k);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}