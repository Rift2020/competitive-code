#include<bits/stdc++.h>
		#define maxn 10005
		using ll = long long;
int a[maxn];
int b[maxn];
int st[maxn];
	cin.tie(nullptr);
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			st[i]=a[i];
		}
		sort(st+1,st+n+1);
		bool fl=false;
		rep(i,1,n){
			if(a[i]!=st[i]){
				fl=true;
				break;
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}