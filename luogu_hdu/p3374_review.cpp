#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 500005		using namespace std;using ll = long long int;
template<typename T>
struct BITree{
	int size;
	T *c;
	BITree(int size){
		BITree::size=size;
		c=new T[size+5];
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

int n,m;int a[maxn];int main(){	ios::sync_with_stdio(false);	cin>>n>>m;
	BITree<int> tr(n);
	rep(i,1,n){
		cin>>a[i];
		tr.add(i,a[i]);
	}
	rep(i,1,m){
		int op;
		cin>>op;
		int x,y,k;
		if(op==1){
			cin>>x>>k;
			tr.add(x,k);
		}
		else if(op==2){
			cin>>x>>y;
			cout<<tr.getSum(x,y)<<endl;
		}
	}				return 0;}