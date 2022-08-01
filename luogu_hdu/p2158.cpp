/**
 *    author:  Rift
 *    created: 2022.07.30  17:47
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
using namespace std;
using pr = pair<int,int>;
using ll = long long;
int Euler(int x){
	int ans=x;
	int sqrtx=sqrt(x+0.5);
	for(int i=2;i<=sqrtx;++i){
		if(x%i==0)
			ans=ans/i*(i-1);
		while(x%i==0)x/=i;
	}
	if(x!=1)ans=ans/x*(x-1);
	return ans;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	ll ans=0;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	rep(i,1,n-1){
		//cout<<Euler(i)<<endl;
		ans+=Euler(i);
	}
	cout<<ans*2+1<<endl;
	
	return 0;
}
