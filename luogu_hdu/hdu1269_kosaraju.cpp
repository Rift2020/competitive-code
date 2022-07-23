#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,m;
vector<int> g[maxn],rg[maxn];//g是图，rg是反图
bool vis[maxn];
vector<int> seq;//第一次dfs的标号，可以用vector来替代，显然后push的就是序号更大的意思
bool scc[maxn];//是否是别的连通分量
//注意，如果你需要知道哪些点属于哪个连通分量，可以改成int数组，然后标记的时候用一个全局的cnt给它标
void dfs(int x){
    if(vis[x])return;
    vis[x]=true;
    for(int i:g[x])dfs(i);
    seq.push_back(x);//后序
}
void dfs2(int x){
    if(scc[x])return;
    scc[x]=true;//在这里标记
    for(int i:rg[x])dfs2(i);
}
int inline sccAmo(){//返回的是连通分量的数量
    int re=0;
    for(int i=1;i<=n;++i)dfs(i);
    for(int i=seq.size()-1;i>=0;--i){
        if(scc[seq[i]]==false){
            //如果需要，在这里让cnt增加
            re++;
            dfs2(seq[i]);
        }
    }
    return re;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
    	if(n==0)break;
        //以下5行都是初始化
    	for(auto &i:g)i.clear();
    	for(auto &i:rg)i.clear();
    	seq.clear();
    	memset(vis,0,sizeof(vis));
    	memset(scc,0,sizeof(scc));
        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
      	if(sccAmo()<=1){
      		cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
    }
    
    return 0;
}