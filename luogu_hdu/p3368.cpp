#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
int n,m;
ll c[maxn];int inn[maxn];
int inline lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i))c[i]+=k;
}
ll query(int x){
    ll ans=0;
    for(int i=x;i>=1;i-=lowbit(i))ans+=c[i];
    return ans;
}
int main(){
    cin>>n>>m;
    memset(c,0,sizeof(c));
    int e,x,y,k;
    for(int i=1;i<=n;++i){
        scanf("%d",&inn[i]);
    }
    //for(int i=1;i<=n;++i)cout<<c[i]<<" ";
    //for(int i=1;i<=n;++i)cout<<query(i)<<" ";
    for(int i=0;i<m;++i){
        scanf("%d%d",&e,&x);
        if(e==2)cout<<query(x)+inn[x]<<endl;
        else{
            scanf("%d%d",&y,&k);
            add(x,k);
            add(y+1,-k);
        }
    }   
    
    
    return 0;
}