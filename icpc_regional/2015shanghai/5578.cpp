#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
string in;int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}