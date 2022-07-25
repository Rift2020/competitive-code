#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005using namespace std;using ll = long long int;int t,n;
int a[maxn];
string in;
typedef pair<int,int> pr;
vector<pr> v;
int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}