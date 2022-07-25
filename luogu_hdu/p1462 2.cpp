#include<bits/stdc++.h>
#define maxn 10005
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
int n,m,b,c1;
typedef pair<int,int> edge,pr,nod;//w,v;dis,v;mon,i
int dis[maxn];
bool vis[maxn];
vector<edge> g[maxn];
unordered_map<int,int> um;
priority_queue<pr,vector<pr>,greater<pr> > pq,cl;
bool dijkstr(int ban){
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    pq=cl;
    pq.push(pr{0,1});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto i:g[u]){
            int v=i.second,w=i.first,b=um[v];
            if(b>ban)continue;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push(pr{dis[v],v});
            }
        }
    }
    if(dis[n]<b)return true;
    return false;
}
vector<nod> city;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>b;
    rep(i,1,n){
        int f;
        cin>>f;
        city.push_back(nod{f,i});
        um[i]=f;
    }
    rep(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(edge{c,b});
        g[b].push_back(edge{c,a});
    }
    sort(city.begin(),city.end());
    int le,ri;
    rep(i,0,n-1){
        if(city[i].second==1||city[i].second==n){
            if(city[i].second==1)c1=city[i].first;
            le=i;
        }
    }
    ri=n;
    if(dijkstr(1e9)==false){
        cout<<"AFK"<<endl;
    }
    else{
        while (le<ri) {
            int mi=(le+ri)/2;
            int ban=city[mi].first;
            //cout<<le<<" "<<ri<<endl;
            if(dijkstr(ban)==true&&dijkstr(ban-1)==false){
                cout<<city[mi].first<<endl;
                return 0;
            }
            else if(dijkstr(ban)==true)ri=mi;
            else le=mi;
        }
    }
    
    
    return 0;
}
