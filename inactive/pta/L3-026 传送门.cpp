#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
//typedef pair<int,int> pr;//y,xto
unordered_map<int,int> mp[maxn];
int n,q,x1,x2,y;
char op;
int where(int x,int y){
    if(y==0&&mp[x].empty())return x;
    if(y==0)return where(mp[x].begin()->second,mp[x].begin()->first);
    auto it=mp[x].find(y);
    if(it==mp[x].end())return x;
    ++it;
    if(it==mp[x].end())return x;
    return where(it->second,it->first);
}
void xfx(){
    ll ans=0;
    for(int i=1;i<=n;++i){
        ans+=i*where(i,0);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=0;i<q;++i){
        cin>>op>>x1>>x2>>y;
        if(op=='+'){
            mp[x1][y]=x2;
            mp[x2][y]=x1;
        }
        else if(op=='-'){
            mp[x1].erase(y);
            mp[x2].erase(y);
        }
        xfx();
    }    
    
    
    return 0;
}