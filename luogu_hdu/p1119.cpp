#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,m,q;
int mp[maxn][maxn],tim[maxn];
void inline update(int x){
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(mp[i][j]>mp[i][x]+mp[x][j])
                mp[i][j]=mp[j][i]=mp[i][x]+mp[x][j];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>tim[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            mp[i][j]=1e9;
    for(int i=0;i<n;++i)mp[i][i]=0;
    for(int i=0;i<m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        mp[x][y]=mp[y][x]=z;
    }
    cin>>q;
    int now=0;
    for(int i=0;i<q;++i){
        int x,y,z;
        cin>>x>>y>>z;
        while(tim[now]<=z&&now<n){
            update(now);
            ++now;
        }
        if(x>=now||y>=now||mp[x][y]==1e9)cout<<-1<<endl;
        else cout<<mp[x][y]<<endl;
    }
    
    return 0;
}