#include<bits/stdc++.h>
		#define maxn 105
int n;
int a[maxn];
bool isPrime(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		int s=0;
		int ind=-1;
		rep(i,1,n){
			s+=a[i];
			if(a[i]%2==1)ind=i;
		}
		//cout<<":"<<ind<<" "<<n<<endl;
		if(isPrime(s)==false){
			cout<<n<<endl;
			rep(i,1,n)cout<<i<<" ";
			cout<<endl;
		}
		else{
			cout<<n-1<<endl;
			rep(i,1,n){
				if(i==ind)continue;
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}