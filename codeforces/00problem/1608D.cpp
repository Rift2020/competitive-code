/**
 *    author:  Rift
 *    created: 2021.12.14  15:28
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define mod 998244353
#define maxn 100005
#define int long long
using namespace std;
using ll = long long;
int n,ans,diff;
string a[maxn];
int qt,qqt,wt,bt,w_t,b_t;
int fact[maxn*3];
bool fl,flwb,flbw;
int inline fpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re=(x*re)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return re;
}
int C(int n,int m){
	if(m==0)return 1;
	if(m>n)return 0;
	int fm=fact[m]*fact[n-m];
	fm%=mod;
	fm=fpow(fm,mod-2);
	int fz=fact[n];
	return (fz*fm)%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fact[0]=1;
	rep(i,1,maxn*3-1)fact[i]=fact[i-1]*i%mod;
	cin>>n;
	rep(i,1,n)cin>>a[i];
	fl=false,flwb=true,flbw=true;
	rep(i,1,n){
		for(char c:a[i]){
			if(c=='?')qt++;
			if(c=='W')wt++;
			if(c=='B')bt++;
		}
		if(a[i]=="??")qqt++;
		else if(a[i]=="WB"||a[i]=="W?"||a[i]=="?B")w_t++;
		else b_t++;
		if(a[i]=="WW"||a[i]=="BB")fl=true;
		if(a[i][0]=='W'||a[i][1]=='B')flbw=false;
		else if(a[i][0]=='B'||a[i][1]=='W')flwb=false;
	}
	if(wt>n||bt>n){
		ans=0;
	}
	else{
		diff=abs(wt-bt);
		ans=C(qt,(qt-diff)/2);
		if(fl==false){	
			ans=(ans-fpow(2,qqt))%mod;
			if(flwb)++ans;
			if(flbw)++ans;
		}
	}
	cout<<ans%mod<<endl;//

return 0;
}


