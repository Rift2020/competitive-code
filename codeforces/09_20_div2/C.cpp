#include<bits/stdc++.h>
		using namespace std;
ll a[maxn];
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;++i)s+=a[i];
	cin>>m;
	while (m--) {
		cin>>x>>y;
		if(lower_bound(a,a+n,x)==a+n){
			ll now=a[n-1];
			cout<<x-now+max(0LL,y-s+now)<<endl;
		}
		else if(lower_bound(a,a+n,x)==a){
			ll now=a[0];
			cout<<max(0LL,y-s+now)<<endl;
		}
		else{
			ll now=*lower_bound(a,a+n,x);
			ll la=*(lower_bound(a,a+n,x)-1);
			cout<<min(x-la+max(0LL,y-s+la),max(0LL,y-s+now))<<endl;
		}
	}