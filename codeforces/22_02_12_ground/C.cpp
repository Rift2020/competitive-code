#include<bits/stdc++.h>
		#define maxn 100005
int a[maxn];
	cin.tie(nullptr);
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		bool fl=false,notone=false;
		ll ans=0;
		rep(i,2,n-1){
			if(a[i]>1)notone=true;
			if(a[i]%2==0){
				fl=true;
				ans+=a[i]/2;
			}
			else{
				ans+=a[i]/2+1;
			}
		}
		if(fl||(notone&&n>3))cout<<ans<<endl;
		else cout<<-1<<endl;
	}