#include<bits/stdc++.h>
#define maxn 200005
int a[maxn];
string in;
typedef pair<int,int> pr;
vector<pr> v;
int main(){
	while(t--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		cin>>in;
		in=" "+in;
		v.clear();
		rep(i,1,n){
			if(in[i]=='B'){
				v.push_back({1,min(a[i],n)});
			}
			else{
				v.push_back({max(a[i],1),n});
			}
		}
		sort(v.begin(),v.end());
		bool fl=true;
		rep(i,1,n){
			if(v[i-1].first>i||v[i-1].second<i){
				fl=false;
				break;
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}