#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
#define x first
#define y second
using namespace std;
using ll = long long;
int n;
typedef pair<int,int> pr;
map<pr,pr> ans;
set<pr> st;
queue<pr> q;
pr a[maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        cin>>a[i].x>>a[i].y;
        st.insert(a[i]);
    }
    rep(i,1,n){
        pr now=a[i];
        for(int i=0;i<4;++i){
            pr near={now.x+dx[i],now.y+dy[i]};
            if(st.find(near)==st.end()){
                ans[now]=near;
                q.push(now);
            }
        }
    }
    while(!q.empty()){
        pr now=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            pr near={now.x+dx[i],now.y+dy[i]};
            if(st.find(near)!=st.end()&&ans.find(near)==ans.end()){
                ans[near]=ans[now];
                q.push(near);
            }
        }
    }
    rep(i,1,n){
        cout<<ans[a[i]].x<<" "<<ans[a[i]].y<<endl;
    }
    return 0;
}