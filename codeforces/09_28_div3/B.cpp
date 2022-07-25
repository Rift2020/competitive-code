#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 55		using namespace std;using ll = long long int;int a[maxn];
struct st{
	int l,r,d;
};
vector<st> ans;
int t,n;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		cin>>n;
		ans.clear();
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=n;i>=1;--i){
			for(int j=i-1;j>=1;--j){
				if(a[j]>a[j+1]){
					int k=lower_bound(a+j,a+n+1,a[j])-a-1;
					int t=a[j];
					ans.push_back(st{j,k,1});
					for(int l=j+1;l<=k;++l){
						a[l-1]=a[l];
					}
					a[k]=t;
					i=j+1;
					break;
				}
			}
		}
		cout<<ans.size()<<endl;
		for(const auto &i:ans){
			cout<<i.l<<" "<<i.r<<" "<<i.d<<endl;
		}
	}				return 0;}