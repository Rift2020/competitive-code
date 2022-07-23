#include<bits/stdc++.h>
#define maxn 30
using namespace std;
unordered_map<int,int> mp[maxn];
int n,k;
void add_edge(int u,int v){
    mp[u][v]=1;
}
int root;
int dfn[maxn];
void dfs(int x,int n){
    dfn[x]=max(dfn[x],n);
    for(auto i:mp[x]){
        int v=i.first;
        dfs(v,n+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    string now,la="";
    for(int i=0;i<k;++i){
        cin>>now;
        if(la!=""){
            for(int i=0;i<now.size()&&i<la.size();++i){
                if(la[i]!=now[i]){
                    add_edge(la[i]-'a',now[i]-'a');
                    break;
                }
            }
        }
        la=now;
    }
    bool fl=false;
    for(int i=0;i<n;++i){
        memset(dfn,0,sizeof(dfn));
        dfs(i,1);
        int ma=0;
        for(int i=0;i<n;++i){
            ma=max(ma,dfn[i]);
        }
        if(ma==n){
            fl=true;
            break;
        }
    }
    string ans;
    cin>>ans;
    if(fl){
        for(char &i:ans){
            i=dfn[i-'a']-1+'a';
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
    
    return 0;
}