/**
 *    author:  Rift
 *    created: 2022.08.09  22:30
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
#define divCeil(a,b) ((a<0||a%b==0)?a/b:a/b+1)
#define divFloor(a,b) ((a>0||a%b==0)?a/b:a/b-1)

using namespace std;
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
		x*=c/__gcd(a,b);
		y*=c/__gcd(a,b);
		//cout<<"x,y "<<x<<" "<<y<<endl;
		a=a/g,b=b/g;
		int l=divCeil(-x,b);
		if(-x%b==0)++l;
		int r=divFloor(y,a);
		if(y%a==0)--r;
		/*
		int l=-x/b;
		if((-x<0&&-x%b==0)||-x>=0)l++;
		int r=y/a;
		if(y<0||y%a==0)r--;
		*/
		//cout<<"a,b "<<a<<" "<<b<<endl;
		//cout<<"l,r "<<l<<" "<<r<<endl;
		//cout<<"g:"<<c/g<<endl;
		if(fl){
			swap(x,y);
			swap(a,b);
			swap(l,r);
			a=-a;
			b=-b;
		}
		if(l>r&&fl==false||l<r&&fl==true){
			cout<<x+b*l<<" "<<y-a*r<<endl;
		}
		else{
			cout<<max(l,r)-min(l,r)+1<<" "<<x+b*l<<" "<<y-a*r<<" "<<x+b*r<<" "<<y-a*l<<endl;
		}
	}
	
	
	return 0;
}
