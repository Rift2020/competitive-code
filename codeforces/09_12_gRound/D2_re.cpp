#include<bits/stdc++.h>
#define maxnm 900005#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,n,m;
int a[maxnm];
int sa[maxnm];
unordered_map<int,int> la,fir,now;
int line(int x){
	if(x%m==0)return x/m;
	return x/m+1;
}
int nex(int x){
	if(now.find(x)==now.end()){
		now[x]=min(la[x],line(fir[x])*m);
		//cout<<"::"<<x<<" "<<fir[x]<<" "<<la[x]<<endl;
	}
	else{
		if(now[x]==fir[x]||now[x]%m==1||m==1){
			now[x]=min(la[x],(line(now[x])+1)*m);
		}
		else now[x]--;
	}
	//cout<<':'<<x<<" "<<now[x]<<endl;
	return now[x];
}
bool sit[maxnm];int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		la.clear();
		fir.clear();
		now.clear();
		memset(sit,false,sizeof(sit));
		cin>>n>>m;
		rep(i,1,n*m){
			cin>>a[i];
			sa[i]=a[i];
		}
		sort(sa+1,sa+n*m+1);
		rep(i,1,n*m){
			la[sa[i]]=i;
			if(fir.find(sa[i])==fir.end())fir[sa[i]]=i;
		}
		int ans=0;
		/*
		cout<<':';
		for(auto i:fir)cout<<i.first<<" "<<i.second<<endl;
		cout<<'/'<<endl;
		*/
		rep(i,1,n*m){
			int w=nex(a[i]);
			int l=w/m;
			if(w%m==0)--l;
			l=l*m+1;
			rep(i,l,w)if(sit[i])++ans;
			sit[w]=true;
		}
		cout<<ans<<endl;
	}				return 0;}