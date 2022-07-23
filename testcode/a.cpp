#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
#define x first
#define y second
using namespace std;
using ll = long long;
int n,c;
int mem[maxn][maxn];//使用第[i,n]种物品，占用j空间下，能赚到的最大钱
int w[maxn];//weight
int v[maxn];//value
bool qlm[maxn][maxn];//取了嘛？mem[i][j]赚的钱中，第i个物品取了还是没取
typedef pair<int,int> pr;
pr nex[maxn][maxn];//mem[i][j]赚的钱中，下一个决策是哪(类链表)
int memdfs(int x,int y){
    //求使用第[x,n]种物品，占用y空间下，能赚到的最大钱
    if(mem[x][y]!=-1)return mem[x][y];//记忆化
    if(x==n){//已经到了最后一个物品(边界)
        if(w[x]<=y)
            mem[x][y]=v[x],qlm[x][y]=true;
        else
            mem[x][y]=0,qlm[x][y]=false;
        return mem[x][y];
        //nex默认就是{0,0}，所以不用给nex赋值
    }
    if(y==0)return mem[x][y]=0;//(边界)没米了
    if(w[x]<=y&&memdfs(x+1,y-w[x])+v[x]>=memdfs(x+1,y)){
        //米够买第x个物品，而且买第x物品比不买更划算
        mem[x][y]=memdfs(x+1,y-w[x])+v[x];
        qlm[x][y]=true;//第x物品取了
        nex[x][y]={x+1,y-w[x]};//下一个决策
    }
    else{
        mem[x][y]=memdfs(x+1,y);//买不了或者不买更好
        qlm[x][y]=false;//没取
        nex[x][y]={x+1,y};//下一个决策
    }
        
    return mem[x][y];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mem,-1,sizeof(mem));
    cin>>n>>c;
    rep(i,1,n)cin>>w[i]>>v[i];
    cout<<memdfs(1,c)<<endl;
    bool fl=false;//至少买了一个东西，则为true
    for(pr now={1,c};now!=(pr){0,0};now=nex[now.x][now.y]){
        if(qlm[now.x][now.y]){
            fl=true;
            cout<<now.x<<" ";
        }
    }
    if(!fl){
        cout<<"nothing";
    }
    cout<<endl;
    return 0;
}