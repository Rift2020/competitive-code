/**
 *    author:  Rift
 *    created: 2022.08.09  22:30
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
using namespace std;
using pr = pair<int,int>;
using ll = long long;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return g;
}
int t,a,b,c;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		bool fl=false;
		if(a<b){
			swap(a,b);
			fl=true;
		}
		if(c%__gcd(a,b)!=0){
			cout<<-1<<endl;
			continue;
		}
		int x,y,g;
		g=exgcd(a,b,x,y);
		//cout<<g<<endl;
		//x*=c/__gcd(a,b);
		//y*=c/__gcd(a,b);
		int a2=a/g,b2=b/g;
		int l=(-x-1)/b2+1;
		int r=y/a2;
		if(l>r){
			cout<<x+b2*l<<" "<<y-a2*r<<endl;
		}
		else{
			cout<<r-l+1<<" "<<x+b2*l<<" "<<y-a2*r<<" "<<x+b2*r<<" "<<y-a2*l<<endl;
		}
	}
	
	
	return 0;
}
