#include<bits/stdc++.h>
#define maxv 505
using namespace std;
int v,e,k,n,ys[maxv];
vector<int> vc[maxv];
queue<int> q;
bool vis[maxv];
void query(){
    memset(vis,false,sizeof(vis));
    q.push(1);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        vis[now]=true;
        for(auto i:vc[now]){
            if(vis[i])continue;
            if(ys[i]==ys[now]){
                cout<<"No"<<endl;
                return;
            }
            q.push(i);
        }
    }
    cout<<"Yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>v>>e>>k;
    for(int i=0;i<e;++i){
        int x,y;
        cin>>x>>y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    cin>>n;
    for(int i=0;i<n;++i){
        set<int> st;
        for(int j=1;j<=v;++j){
            cin>>ys[j];
            st.insert(ys[j]);
        }
        if(st.size()>k)cout<<"No"<<endl;
        else query();
    }
    
    return 0;
}