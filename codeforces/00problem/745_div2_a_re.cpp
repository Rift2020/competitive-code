#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define mod 1000000007
#define maxn 200005
using namespace std;
using ll = long long int;
ll fact[maxn];
int t;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    fact[0]=1;
    for(int i=1;i<maxn;++i){
        if(i==2)fact[2]=1;
        else fact[i]=fact[i-1]*i%mod;
    }
    while(t--){
        cin>>n;
        n*=2;
        cout<<fact[n]<<endl;
    }

    
    
    
    return 0;
}