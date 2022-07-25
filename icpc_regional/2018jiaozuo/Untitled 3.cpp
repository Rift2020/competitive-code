#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
int a[5];
string out[5]={"Typically Otaku","Eye-opener","Young Traveller","Excellent Traveller","Contemporary Xu Xiake"};
int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		rep(i,1,4)
			cin>>a[i];
		int s=0;
		rep(i,1,4){
			if(a[i]>=1)++s;
		}
		cout<<out[s]<<endl;
		
	}				return 0;}