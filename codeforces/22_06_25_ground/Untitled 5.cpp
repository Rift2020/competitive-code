#include<bits/stdc++.h>
		#define maxn 250005
int a[maxn];
int ru[maxn];
int rd[maxn];
	cin.tie(nullptr);
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		int ans=0,now=1;
			int mi=a[now];
			int ma=a[now];
			for(int i=now+1;;++i){
				if(a[i]>=mi&&a[i]<=ma){
					now=i-1;
					break;
				}
				mi=min(mi,a[i]);
				ma=max(ma,a[i]);
				if(mi!=a[now]&&ma!=a[now]){
					now=i-1;
					break;
				}
				if(i==n){
					now=n;
					break;
				}
			}
			++ans;
		}
	}