#include<bits/stdc++.h>
string in;
int ans;
map<char,int> mp={{'H',1},{'O',16},{'C',12}};
	while(t--){
		cin>>in;
		ans=0;
		for(char c:in)ans+=mp[c];
		cout<<ans<<endl;
	}