#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)using namespace std;using ll = long long int;int t,n,m;
int _u,_d,_l,_r,u,d,l,r;
string s;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>s;
		u=0,d=0,l=0,r=0;
		int x=0,y=0;
		bool fl=true;
		for(char c:s){
			_u=u,_d=d,_l=l,_r=r;
			if(c=='L')x--;
			else if(c=='U')y++;
			else if(c=='R')x++;
			else if(c=='D')y--;
			r=max(r,x),l=min(l,x),u=max(u,y),d=min(d,y);
			if(r-l+1>m||u-d+1>n){
				fl=false;
				break;
			}
		}
		if(fl)_u=u,_d=d,_l=l,_r=r;
		cout<<1+_u<<" "<<1-_l<<endl;
	}				return 0;}