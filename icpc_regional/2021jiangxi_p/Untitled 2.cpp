#include<bits/stdc++.h>
vector<int> ans;
void frac(int x,int y){
	//if(y==0)return;
	int a=x/y;
	int b=x%y;
	ans.push_back(a);
	if(b!=1){
		frac(y,b);
	}
	else{
		ans.push_back(y);
	}
}
	while(t--){
		cin>>x>>y;
		ans.clear();
		frac(x,y);
		if(ans.size()==1){
			ans.insert(ans.begin(),0);
		}
		cout<<ans.size()-1<<" ";
		for(int i:ans)
			cout<<i<<" ";
		cout<<endl;
	}