#include<bits/stdc++.h>
#define maxn 35
#define ll long long
using namespace std;
int a[maxn],n;
ll mem[maxn][maxn][maxn],root,tree[maxn][2];
ll dfs(int s,int t,int r){
    if(mem[s][t][r])return mem[s][t][r];
    if(s==t)return mem[s][t][r]=a[r];
    //if(s==t-1)return mem[s][t][r]=a[s]+a[t];
    ll le=1,ri=1;
    for(int nr=s;nr<r;++nr){
        if(le<dfs(s,r-1,nr)){
            le=dfs(s,r-1,nr);
            tree[r][0]=nr;
        }
        //le=max(le,dfs(s,r-1,nr));
    }
    for(int nr=r+1;nr<=t;++nr){
        if(ri<dfs(r+1,t,nr)){
            ri=dfs(r+1,t,nr);
            tree[r][1]=nr;
        }
        //ri=max(ri,dfs(r+1,t,nr));
    }
    /*
    if(s==t-1){
        cout<<':'<<a[s]<<" "<<a[t]<<endl;
        cout<<':'<<le<<" "<<ri<<" "<<a[r]<<endl;
    }
    */
    return mem[s][t][r]=le*ri+a[r];
}
void dfs2(int x){
    cout<<x<<" ";
    if(tree[x][0]!=0)dfs2(tree[x][0]);
    if(tree[x][1]!=0)dfs2(tree[x][1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll ma=0;
    for(int i=1;i<=n;++i){
        if(ma<dfs(1,n,i)){
            ma=dfs(1,n,i);
            root=i;
        }
        //ma=max(ma,dfs(1,n,i));
    }
    cout<<ma<<endl;
    dfs2(root);
    return 0;
}