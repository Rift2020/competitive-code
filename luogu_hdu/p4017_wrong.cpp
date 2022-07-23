#include<bits/stdc++.h>
#define mod 80112002
#define maxn 5005
#define ll long long
using namespace std;
int n,m;ll mem[maxn],mx;
vector<int> v[maxn];
ll dfs(int x){
    if(mem[x]!=-1)return mem[x];
    mem[x]=1;
    for(auto i:v[x]){
        mem[x]=max(mem[x],dfs(i)+1);
    }
    if(mem[x]>mx)mx=mem[x];
    return mem[x];
}
int main(){
    cin>>n>>m;
    int a,b;
    memset(mem,-1,sizeof(mem));
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i)dfs(i);   
    cout<<mx%80112002<<endl;
    return 0;
}