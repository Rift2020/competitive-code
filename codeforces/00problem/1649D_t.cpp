#include<bits/stdc++.h>
		#define maxc 1000005
int a[maxc];
int sec[maxc];
	cin.tie(nullptr);
	while(t--){
		cin>>n>>c;
		memset(a,0,sizeof(int)*(c+5));
		memset(sec,0,sizeof(int)*(c+5));
		rep(i,1,n){
			int in;
			cin>>in;
			a[in]=1;
		}
		rep(i,1,c){
			sec[i]=a[i]+sec[i-1];
		}
		bool fl=true;
		if(a[1]==0)fl=false;
		for(int now=1;now<=c&&fl;++now){
			if(a[now]==0)continue;
			int r=now,l=now;//(l,r]
			while(r!=1){
				int v=now/r;
				l=(now/(v+1))+1;
				//cout<<now<<" : "<<l<<" "<<r<<" "<<v<<endl;
				
				if(a[v]||sec[r]-sec[l-1]){
					if(a[v]&&sec[r]-sec[l-1]);
					else {
						//cout<<"no"<<endl;
						fl=false;
						break;
					}
				}
				r=l-1;
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}