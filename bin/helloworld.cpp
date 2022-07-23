/**
 *    author:  Rift
 *    created: 2021.12.16  22:04
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
int n;
int a[]={2,3,5,7,11,13,17,19,23,29,31};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i:a){
			int b=n-i-1;
			if(__gcd(i,b)==1){
				cout<<i<<" "<<b<<" "<<1<<endl;
				break;
			}

		}
	}


return 0;
}
