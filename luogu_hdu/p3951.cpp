/**
 *    author:  Rift
 *    created: 2022.08.11  12:21
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
int a,b;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>a>>b;
	cout<<a*b-a-b<<endl;
	
	return 0;
}
