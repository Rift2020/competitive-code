#include<bits/stdc++.h>
int a[5];
string out[5]={"Typically Otaku","Eye-opener","Young Traveller","Excellent Traveller","Contemporary Xu Xiake"};

	while(t--){
		rep(i,1,4)
			cin>>a[i];
		int s=0;
		rep(i,1,4){
			if(a[i]>=1)++s;
		}
		cout<<out[s]<<endl;
		
	}