#include<bits/stdc++.h>
#define maxp 65//最多只有'z'-'A'个
using namespace std;
int mp[maxp][maxp];//存图 大小是条数
int d[maxp];//每个点的度数
int n,s,n1;//s是出发点，n1是度数为1的点的数量
bool fl=true;//能否构成欧拉路
char ans[maxp*maxp];
map<int,bool> vis;
void cdfs(int x){//dfs检验是否连通
    if(vis[x])return;
    vis[x]=true;
    for(int i=0;i<65;++i){
        if(mp[x][i]>0){
            cdfs(i);
        }
    }
}
void solve(int x){
    //仍然是dfs
    //cout<<(char)(x+'A');
    for(int i=0;i<65;++i){
        if(mp[x][i]){
            mp[x][i]--;
            mp[i][x]--;
            solve(i);
        }
    }
    ans[n--]=(char)(x+'A');//倒序添加
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        string in;
        cin>>in;
        int a=in[0]-'A',b=in[1]-'A';
        mp[a][b]++;
        mp[b][a]++;
        vis[a]=false;
        vis[b]=false;
        d[a]++;
        d[b]++;
    }
    s=vis.begin()->first;//初始化第一个点
    for(int i=0;i<maxp;++i){
        if(d[i]%2==1){
            ++n1;
            if(n1==1)s=i;//如果有入度为1的点，设置成第一个
        }
    }
    if(n1>2)fl=false;
    cdfs(s);
    for(auto i:vis){
        if(i.second==false)fl=false;
    }
    if(fl==false){
        cout<<"No Solution"<<endl;
        return 0;
    }
    solve(s);
    cout<<ans;
    return 0;
}