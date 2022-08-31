/**
 *    author:  Rift
 *    created: 2022.07.08  22:40
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
using namespace std;
using ll = long long;
int t;
int n;
int a[maxn];
int used[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<2<<endl;
		int i,j;
		rep(i,1,n){
			used[i]=false;
		}
		a[1]=1;
		used[1]=true;
		for(i=2,j=1;i<=n;++i){
			if(a[i-1]*2<=n&&used[a[i-1]*2]==false){
				a[i]=a[i-1]*2;
				used[a[i]]=true;
			}
			else{
				for(;j<=n;++j){
					if(used[j]==false){
						a[i]=j;
						used[a[i]]=true;
						break;
					}
				}
			}
		}
		rep(i,1,n)cout<<a[i]<<" ";
		cout<<endl;
	}


}
