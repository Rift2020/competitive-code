#include<bits/stdc++.h>
int n;
string s;
	while(t--){
		cin>>n;
		cin>>s;
		int ans=0;
		for(int i=0;i<n;++i){
			//cout<<':'<<s[i]-'0'<<endl;
			if(i!=n-1&&s[i]!='0')
				ans+=s[i]-'0'+1;
			else
				ans+=s[i]-'0';
		}
		cout<<ans<<endl;
	}