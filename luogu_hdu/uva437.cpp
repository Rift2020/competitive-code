#include<bits/stdc++.h>
#define maxn 35
using namespace std;
int n,x,y,z,m;
typedef struct{
    int x,y,z;
}st;
bool operator<(st a,st b){
    if((a.x<b.x&&a.y<b.y)||(a.x<b.y&&a.y<b.x))return true;
    else return false;
}
st a[maxn*3];int p=-1;
int mem[maxn*3];
int dfs(int t){
    if(mem[t])return mem[t];
    for(int i=0;i<=p;++i){
        if(a[i]<a[t])mem[t]=max(mem[t],dfs(i)+a[i].z);
    }
    if(mem[t]+a[t].z>m)m=mem[t]+a[t].z;
    return mem[t];
}
int main(){
    int o=0;
    while(1){
        ++o;
        cin>>n;
        p=-1;
        m=0;
        memset(mem,0,sizeof(mem));
        if(n==0)break;
        for(int i=0;i<n;++i){
            cin>>x>>y>>z;
            a[++p]=(st){x,y,z};
            a[++p]=(st){x,z,y};
            a[++p]=(st){y,z,x};
        }
        for(int i=0;i<=p;++i)dfs(i);
        printf("Case %d: maximum height = %d\n",o,m);
    }
    
    
    return 0;
}