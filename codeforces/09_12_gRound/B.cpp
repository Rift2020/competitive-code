#include<bits/stdc++.h>
string s;
	while(t--){
		cin>>s;
		int ans=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0'&&(i==0||s[i-1]!='0')){
				++ans;
			}
		}
		cout<<min(ans,2)<<endl;
	}