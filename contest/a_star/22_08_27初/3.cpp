/**
 *    author:  Rift
 *    created: 2022.08.27  14:39
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
#define maxl 30
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int logn[maxn];
int f[maxn][maxl];
int a[maxn];
bool d[maxn];
int n;
void init(){
    logn[1]=0;
    rep(i,2,n)
        logn[i]=logn[i/2]+1;
    for(int j=1;j<=logn[n]+1;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r){
    int s=logn[r-l+1];
    return max(f[l][s],f[r-(1<<s)+1][s]);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	rep(i,1,n){
		cin>>f[i][0];
		a[i]=f[i][0];
	}    
	init();
	for(int i=1;i<=n;++i){
		if(a[i]==query(i,n)){
			d[i]=true;
		}
	}
	bool fl=true;
	int la=-1;
	for(int i=1;i<=n;++i){
		if(d[i]==false){
			if(a[i]<la){
				fl=false;
				break;
			}
			la=a[i];
		}
	}
	if(fl)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
