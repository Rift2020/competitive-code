/**
 *    author:  Rift
 *    created: 2022.08.10  14:46
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define mod 19260817
#define int ll
using namespace std;
using ll = long long;
int inline read(){
    int s=0,f=1;
    char c=getchar();
    while(!(c<='9'&&c>='0')){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        s=(s<<1)+(s<<3);
        s+=c-'0';
		s%=mod;
        c=getchar();
    }
    return f*s;
}
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
int a,b,c;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	c=read(),a=read();
	b=19260817;
	int x,y;
	int g=exgcd(a,b,x,y);
	int x1=c*x/g;
	cout<<(x1%b+b)%b<<endl;
	
	
	return 0;
}
