#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define int long long		using namespace std;using ll = long long;int t,n,l,r,ma,k,now,ni,ki;
string in;
vector<int> v;signed main(){	ios::sync_with_stdio(false);	cin>>t;
	rep(c,1,t){
		cin>>in;
		v.clear();
		int s=0;
		for(int i=0;i<in.size();++i){
			if(i>0&&in[i]!=in[i-1]){
				v.push_back(s);
				s=1;
			}
			else ++s;
		}
		v.push_back(s);
		ll ans=0;
		for(int i:v)ans+=i*i;
		ll add=0,now;
		for(int i=0;i<v.size();++i){
			now=v[i];
			if(i!=0)l=v[i-1];
			else l=-1;
			if(i!=v.size()-1)r=v[i+1];
			else r=-1;
			if(l==-1&&r==-1)continue;
			if(l==-1){
				add=max(add,(now-1)*(now-1)+(r+1)*(r+1)-now*now-r*r);
			}
			else if(r==-1){
				add=max(add,(now-1)*(now-1)+(l+1)*(l+1)-now*now-l*l);
			}
			else{
				if(now==1){
					add=max(add,(ll)(l+r+1)*(l+r+1)-l*l-r*r-1);
				}
				else{
					add=max(add,(now-1)*(now-1)+(r+1)*(r+1)-now*now-r*r);
					add=max(add,(now-1)*(now-1)+(l+1)*(l+1)-now*now-l*l);
				}
			}
		}
		cout<<"Case #"<<c<<": "<<ans+add<<endl;
	}				return 0;}