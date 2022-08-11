/**
 *    author:  Rift
 *    created: 2022.08.10  20:11
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
#define endl '\n'
using namespace std;
using ll = long long;
int x,mod;
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
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>x>>mod;
	for(int i=1;i<=x;++i)
		cout<<fpow(i,mod-2)<<endl;
	
	
	return 0;
}
