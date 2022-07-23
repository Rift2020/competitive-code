#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;

ll c[maxn];
int n,m;
int inline lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    while(x<=n){
        c[x]+=k;
        x+=lowbit(x);
    }
}
ll getsum(int x){
    ll ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
ll q(int l,int r){
    ll ans=0;
    return getsum(r)-getsum(l-1);
}
int main(){
    memset(c,0,sizeof(c));
    int a,b,in;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        add(i,a);
    }
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&in,&a,&b);
        if(in==1)add(a,b);
        else{
            printf("%lld\n",q(a,b));
        }
    }
    
    return 0;
}