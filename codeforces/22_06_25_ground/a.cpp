#include<bits/stdc++.h>
		#define int ll
int ans;
	cin.tie(nullptr);
	cin>>t;
		cin>>n>>z;
		ans=0;
		while(n--){
			int in;
			cin>>in;
			ans=max(ans,in|z);
		}
		cout<<ans<<endl;
	}