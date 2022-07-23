#include<bits/stdc++.h>
#define maxn 10005
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
int n,m,b,ban;
typedef pair<int,int> edge,pr,nod;//v,w;dis,v;mon,i
int dis[maxn];
priority_queue<pr,vector<pr>,greater<pr> > pq,cl;
bool dijkstr(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    pq=cl;
    
}
vector<nod> city;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>b;
    rep(i,1,n){
        int f;
        cin>>f;
        city.push_back(nod{f,i});
    }
    sort(city.begin(),city.end());
    int le,ri;
    rep(i,0,n-1){
        if(city[i].second==1){
            le=i+1;
            break;
        }
    }
    ri=n+1;
    ban=ri;
    if(dijkstr()==false){
        cout<<"AFK"<<endl;
    }
    else{

    }
    
    
    return 0;
}