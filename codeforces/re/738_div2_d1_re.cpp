#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct uv{
    int u,v;
};
vector<uv> ans;
int n,m1,m2;
int fa[maxn],fa2[maxn];
int f(int x){
    if(fa[x]==x)return x;
    return fa[x]=f(fa[x]);
}
int f2(int x){
    if(fa2[x]==x)return x;
    return fa2[x]=f2(fa2[x]);
}
void mg(int x,int y){
    int fx=f(x);
    int fy=f(y);
    fa[fx]=fy;
}
void mg2(int x,int y){
    int fx=f2(x);
    int fy=f2(y);
    fa2[fx]=fy;
}


int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;++i)fa[i]=fa2[i]=i;
    for(int i=0;i<m1;++i){
        int u,v;
        cin>>u>>v;
        mg(u,v);
    }
    for(int i=0;i<m2;++i){
        int u,v;
        cin>>u>>v;
        mg2(u,v);
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(f(i)!=f(j)&&f2(i)!=f2(j)){
                ans.push_back(uv{i,j});
                mg(i,j);
                mg2(i,j);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.u<<" "<<i.v<<endl;
    }
    return 0;
}