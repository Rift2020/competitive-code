#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
    #define per(i, a, b) for (int i = (a); i >= (b); --i)
        #define maxn 30005
        using namespace std;
using ll = long long;
int t,n,m;
vector<int> g[maxn];
int rd[maxn];
priority_queue<int,vector<int>,greater<int> > pq,cl;
vector<int> ans;
signed main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        rep(i,1,n){
            rd[i]=0;
            g[i].clear();
        }
        ans.clear();
        pq=cl;
        rep(i,1,m){
            int u,v;
            cin>>u>>v;
            rd[v]++;
            g[u].push_back(v);
        }
        //topsort
        rep(i,1,n){
            if(rd[i]==0)pq.push(i);
        }
        while(!pq.empty()){
            int u=pq.top();
            ans.push_back(u);
            pq.pop();
            for(int v:g[u]){
                rd[v]--;
                if(rd[v]==0){
                    pq.push(v);
                }
            }
        }
        //_
        bool fl=true;
        for(int i:ans){
            if(fl){
                fl=false;
                cout<<i;
            }
            else
                cout<<" "<<i;
        }
        cout<<endl;
    }

    return 0;
}