#include<bits/stdc++.h>
	#define int long long
		using namespace std;
int a[maxn];
int b[maxn];
	while(t--){
		cin>>n;
		for(int i=1;i<n;++i)cin>>a[i];
		b[1]=0;
		for(int i=2;i<=n;++i)b[i]=b[i-1]+a[i-1];
		int l=1,r=n,dis=0,ans=0;
		bool isl=true;
		bool fl=true;
		while(l<=r){
			if(isl){
				ans+=dis;
				++l;
				isl=false;
			}
			else{
				isl=true;
				dis+=b[r]-b[l-1];
				ans+=dis;
				--r;
			}
			if(fl)
			{
				cout<<ans;
				fl=false;
			}
			else
				cout<<" "<<ans;
		}
		cout<<endl;
	}