#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t;
string in;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>in;
		int ind=-1;
		for(int i=in.size()-2;i>=0;--i){
			if(in[i]-'0'+in[i+1]-'0'>=10){
				ind=i;
				break;
			}
		}
		
		if(ind!=-1){
			int num=in[ind]-'0'+in[ind+1]-'0';
			in[ind]=to_string(num)[0];
			in[ind+1]=to_string(num)[1];
		}
		else{
			int num=in[0]+in[1]-'0'-'0';
			in=in.substr(1);
			in[0]=num+'0';
		}
		cout<<in<<endl;
	}				return 0;}