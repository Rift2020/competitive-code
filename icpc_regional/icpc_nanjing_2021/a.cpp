#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n,a,b,x,y;
vector<char> ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    int l,u,q;
    if(b<=n/2)l=1;
    else l=0;
    if(a<=n/2)u=1;
    else u=0;
    if(l==1){
        rep(i,1,n-1)ans.push_back('L');
        y=1;
    }
    else{
        rep(i,1,n-1)ans.push_back('R');
        y=n;
    }
    if(u==1){
        rep(i,1,n-1)ans.push_back('U');
        x=1;
    }
    else{
        rep(i,1,n-1)ans.push_back('D');
        x=n;
    }   
    if(a>=x){
        rep(i,1,a-x)ans.push_back('D');
    }
    else{
        rep(i,1,x-a)ans.push_back('U');
    }
    if(b>=y){
        rep(i,1,b-y)ans.push_back('R');
    }
    else{
        rep(i,1,y-b)ans.push_back('L');
    }
    for(char i:ans)cout<<i;
    cout<<endl;
    return 0;
}