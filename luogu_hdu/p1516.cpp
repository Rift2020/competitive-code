/**
 *    author:  Rift
 *    created: 2022.08.11  14:12
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
int x,y,m,n,l;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>x>>y>>m>>n>>l;
	int a=m-n,b=l,c=y-x;
	if(c%(__gcd(a,b))!=0){
		cout<<"Impossible"<<endl;
	}
	else{
		int x,y;
		if(a<0){
			a=-a;
			c=-c;
		}
		int g=exgcd(a,b,x,y);
		x=x*c/g;
		b=b/g;
		//cout<<x<<" "<<b<<endl;
		cout<<(x%b+b)%b<<endl;
	}
	
	
	return 0;
}
