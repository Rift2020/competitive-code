#include<bits/stdc++.h>
string in;
	rep(c,1,t){
		cin>>in;
		int ans=1e9;
		for(int i=0;i<in.size();++i){
			for(int j=i+1;j<in.size();++j){
				if(in[i]==in[j])ans=min(ans,j-i);
			}
		}
		if(ans==1e9)ans=-1;
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}