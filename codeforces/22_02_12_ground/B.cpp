#include<bits/stdc++.h>
		using namespace std;
int a[maxn];
	cin.tie(nullptr);
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			if(a[i]==0)a[i]=2;
			else a[i]=1;
		}
		ll ans=0;
		rep(i,1,n){
			ll l=i,r=n-i+1;
			ans+=l*r*a[i];
		}
		cout<<ans<<endl;
	}