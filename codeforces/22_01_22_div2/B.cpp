#include<bits/stdc++.h>
	cin.tie(nullptr);
	while(t--){
		cin>>l>>r>>k;
		int n=r-l+1;
		if(n==1){
			if(l!=1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
		if(n%2==1&&l%2==1)n+=2;
		n/=2;
		if(n<=k)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}