#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 105		using namespace std;using ll = long long int;int t;
int n;
int a[maxn];
bool isPrime(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}