#include<bits/stdc++.h>
#define maxn 500505
#define ll long long
using namespace std;
int r,n,a[maxn];ll mem[maxn],ans=0;
ll dfs(int x){
    //cout<<x<<endl;
    if(mem[x]!=-1)return mem[x];
    mem[x]=a[x];
    int nxf=0,fr=0;
    for(int i=0;i<=1000;++i){
        if((1+i)*i/2>=x){
            fr=(i-1)*i/2+1;
            nxf=(1+i)*i/2+1;
            break;
        }
    }
    
    int site=x-fr+1;
    int l=nxf+site-1;
    int r=l+1;
    if(l<=n){
        mem[x]+=max(dfs(l),dfs(r));
    }
    if(mem[x]>ans)ans=mem[x];
    return mem[x];
}
int main(){
    memset(mem,-1,sizeof(mem));
    cin>>r;
    n=(1+r)*r/2;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}