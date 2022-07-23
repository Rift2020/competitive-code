#include<bits/stdc++.h>
#define maxn 1000005
#define mod 100003
#define ll long long
using namespace std;
typedef pair<int,int> nod;//len,num
vector<int> st[maxn];
int n,m;
int dist[maxn],num[maxn];
bool vis[maxn];
void relax(int s){
    priority_queue<nod,vector<nod>,greater<nod> > pq;
    pq.push(nod(0,s));
    //int p=0;
    num[s]=1;
    while(!pq.empty()){
        //cout<<++p<<endl;
        int k=pq.top().second;
        pq.pop();
        for(auto i:st[k]){
            if(dist[i]>dist[k]+1){
                dist[i]=dist[k]+1;
                num[i]=num[k];
                pq.push(nod{dist[i],i});
            }else if(dist[i]==dist[k]+1){
                num[i]+=num[k];
                num[i]%=mod;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)dist[i]=INT_MAX;
    memset(vis,0,sizeof(0));
    dist[1]=0;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        if(x==y)continue;
        st[x].push_back(y);
        st[y].push_back(x);
    }
    relax(1);
    for(int i=1;i<=n;++i){
        cout<<num[i]<<endl;
    }
    
    return 0;
}