#include<bits/stdc++.h>
		#define int long long
int x,y,g;
int ans;
typedef pair<int,int> pr;
map<pr,bool> mp;
int gcd(int a,int b){
	if(a<0||b<0)return -1;
	return b==0?a:gcd(b,a%b);
}
void dfs(int x,int y){
	if(mp.find({x,y})!=mp.end())return ;
	mp[{x,y}]=true;
	++ans;
	if(x>y)swap(x,y);
	//cout<<x<<" "<<y<<endl;
	int g=gcd(x,y);
	int _y=g*y/(x+g);
	if((g*y)%(x+g)==0&&g==gcd(x,_y))
		dfs(x,_y);
}
	rep(c,1,t){
		cin>>x>>y;
		ans=0;
		mp.clear();
		dfs(x,y);
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}