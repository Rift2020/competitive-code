#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
//#define local
#ifdef local
#define cout cout<<"output:"
#endif
#define maxn 200005
using namespace std;
using ll = long long int;
vector<int> v[maxn],g[maxn];
int rd[maxn];
bool vis[maxn];
int ans,t,n;
bool hl=false;
void dfs2(int x,int d){
    ans=max(ans,d);
    for(int i:v[x]){
        if(i>x)
            dfs2(i,d);
        else
            dfs2(i,d+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        rep(i,1,n){
            v[i].clear();
            g[i].clear();
        }
        cin>>n;
        hl=false;
        ans=1;
        rep(i,1,n){
            int k;
            cin>>k;
            rd[i]=k;
            rep(j,1,k){
                int in;
                cin>>in;
                v[in].push_back(i);
                g[in].push_back(i);
            }
        }
        
        queue<int> q;
        rep(i,1,n)if(rd[i]==0)q.push(i);
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            for(int i:g[tp]){
                rd[i]--;
                if(rd[i]==0)q.push(i);
            }
            g[tp].clear();
        }
        rep(i,1,n){
            if(!g[i].empty())hl=true;
        }
        if(hl){
            cout<<-1<<endl;
            continue;
        }
        rep(i,1,n){
            dfs2(i,1);
        }
        cout<<ans<<endl;   
    }
    
    
    
    return 0;
}