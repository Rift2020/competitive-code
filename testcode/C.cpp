#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
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
    return (m+x%m)%m;//这一步是为了使不确定符号的x变为正数，为什么是这样我还不明白
}
int fact(int x){
    int re=1;
    for(int i=1;i<=x;++i){
        re*=i;
        re%=mod;
    }
    return re;
}
int inline fpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re=(x*re)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return re;
}
int C(int m,int n){
    int fm=fact(m)*fact(n-m);
    fm%=mod;
    fm=fpow(fm,mod-2);
    int fz=fact(n);
    return (fz*fm)%mod;
}
signed main(){
    int n=1,m=3;
    cout<<C(2,5);
    
    
    return 0;
}