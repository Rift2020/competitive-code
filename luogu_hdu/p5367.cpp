#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 1000005
	#define mod 998244353
	#define int long long		using namespace std;using ll = long long;template<typename T>
struct BITree{
	int size;
	T *c;
	BITree(int size){
		BITree::size=size;
		c=new T[size+5]();
	}
	~BITree(){
		delete [] c;
	}
	int inline lowbit(int x){
		return x&-x;
	}
	void add(int x,T k){
		while (x<=size) {
			c[x]+=k;
			x+=lowbit(x);
		}
	}
	T query0(int r){
		T re(0);
		while (r>=1) {
			re+=c[r];
			r-=lowbit(r);
		}
		return re;
	}
	T getSum(int l,int r){
		return query0(r)-query0(l-1);
	}
};
int n;
int a[maxn];
int fact[maxn];
BITree<int> bt(maxn);
int sumNU(int x){
	return x-1-bt.getSum(0,x-1);
}
void setUsed(int x){
	bt.add(x,1);
}signed main(){	ios::sync_with_stdio(false);	cin>>n;
	fact[0]=fact[1]=1;
	for(int i=2;i<=n;++i){
		fact[i]=fact[i-1]*i%mod;
	}	
	rep(i,1,n){
		cin>>a[i];
	}	ll ans=1;
	rep(i,1,n){
		ans+=fact[n-i]*sumNU(a[i]);
		ans%=mod;
		setUsed(a[i]);
	}	cout<<ans<<endl;	return 0;}