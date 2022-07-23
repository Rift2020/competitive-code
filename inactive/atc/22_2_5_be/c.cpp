#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long long
#define mod 998244353
using namespace std;
using ll = long long;
string in;
int n;
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=x*(a/b);
}
int mod_inverse(int a,int m){
    int x,y;
    exgcd(a,m,x,y);
    return (m+x%m)%m;//这一步是为了使不确定符号的x变为正数
}
int sum0(int r){
   int m=(__int128)(1+r)%mod*r%mod*(ll)499122177%mod;
   return m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>in;
    n=atoll(in.c_str());
    int ans=0;
    for(int i=1,k=9;i<in.size();++i){
        ans+=sum0(k);
        ans%=mod;
        k*=10;
    }
    string sub(in.size()-1,'0');
    sub='1'+sub;
    ans+=sum0(1+n-atoll(sub.c_str()));
    ans%=mod;
    cout<<ans<<endl;
    
    return 0;
}