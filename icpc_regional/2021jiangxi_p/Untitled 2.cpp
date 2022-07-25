#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,x,y;
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
}int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}