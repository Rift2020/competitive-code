#include<bits/stdc++.h>
	#define maxn 100005
		using namespace std;
int a[maxn];
	cin.tie(nullptr);
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		int a0=-1;
		bool a1=false;
		bool d=false;
		bool s=false;
		rep(i,1,n){
			if(a[i]==0)a1=true;
			if(a[i]!=0&&a0==-1){
				a0=i;
			}
			else if(a[i]==0&&a0!=-1){
				d=true;
			}
			else if(a[i]!=0&&d){
				s=true;
			}
		}
		if(s)cout<<"2"<<endl;
		else if(a0==-1)cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}