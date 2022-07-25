#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
	#define int long long
	using namespace std;int t,k,x;
unordered_map<int,char> um;
string convert(int x,int n){
	string re(n,um[0]);
	for(int i=0;x;++i){
		re[i]=um[x%k];
		x/=k;
	}
	reverse(re.begin(),re.end());
	return re;
}signed main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>k>>x;
		x--;
		um.clear();
		for(int i=10-k,j=0;i<=9;++i,++j)um[j]='0'+i;
		for(int i=k,j=1;;i*=k,++j){
			if(x<=i){
				cout<<convert(x,j)<<endl;
				break;
			}
			x-=i;
		}
		
	}				return 0;}