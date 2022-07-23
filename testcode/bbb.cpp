#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int n,c;
int a[maxn];
int ss[maxn];
int ss2[maxn];
bool qlm[maxn];
void dfs(int x,int s){
    if(x==n+1){
        if(s==c){
            rep(i,1,n)
                if(qlm[i])
                    cout<<a[i]<<" ";
            exit(0);
        }
        return;
    }
    if(ss[n]-ss[x-1]+s<c)return;
    if(ss2[n]-ss2[x-1]+s>c)return;
    qlm[x]=true;
    dfs(x+1,s+a[x]);
    qlm[x]=false;
    dfs(x+1,s);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    rep(i,1,n){
        cin>>a[i];
        if(a[i]>0){
            ss[i]=ss[i-1]+a[i];
            ss2[i]=ss2[i-1];
        }
        else{
            ss2[i]=ss2[i-1]+a[i];
            ss[i]=ss[i-1];
        }
            
    }
    dfs(1,0);
    cout<<"No Solution!"<<endl;
    
    
    return 0;
}