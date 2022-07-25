#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 250005		using namespace std;using ll = long long;template<typename T>
struct segTree{
	T *d;
	T *b;
	int size;
	segTree(int size){
		segTree::size=size;
		d=new T[size*4]();
		b=new T[size*4]();
	}
	void build(int s,int t,int p,T *a){
		if(s==t){
			d[p]=a[s];
			return;
		}
		int m=s+((t-s)>>1);//等价于(s+t)/2但可以防止溢出
		build(s,m,p*2,a),build(m+1,t,p*2+1,a);
		d[p]=max(d[p*2],d[p*2+1]);
	}
	segTree(T* l,T* r){
		segTree::size=r-l;
		d=new T[size*4];
		b=new T[size*4]();
		build(1,size,1,l);
	}
private:
	T getMax0(int l, int r, int s, int t, int p) {
		if (l <= s && t <= r) return d[p];
		int m = s + ((t - s) >> 1);
		T ma = 0;
		if (l<=m)ma=max(ma,getMax0(l,r,s,m,p*2));
		if (r>m)ma=max(ma,getMax0(l,r,m+1,t,p*2+1));
		return ma;
	}
public:
	T getMax(int l,int r){
		return getMax0(l,r,1,size,1);
	}
	~segTree(){
		delete [] d;
		delete [] b;
	}
};
template<typename T>
struct segTree2{
	T *d;
	T *b;
	int size;
	segTree2(int size){
		segTree2::size=size;
		d=new T[size*4]();
		b=new T[size*4]();
	}
	void build(int s,int t,int p,T *a){
		if(s==t){
			d[p]=a[s];
			return;
		}
		int m=s+((t-s)>>1);//等价于(s+t)/2但可以防止溢出
		build(s,m,p*2,a),build(m+1,t,p*2+1,a);
		d[p]=min(d[p*2],d[p*2+1]);
	}
	segTree2(T* l,T* r){
		segTree2::size=r-l;
		d=new T[size*4];
		b=new T[size*4]();
		build(1,size,1,l);
	}
private:
	T getMin0(int l, int r, int s, int t, int p) {
		if (l <= s && t <= r) return d[p];
		int m = s + ((t - s) >> 1);
		T ma = INT_MAX;
		if (l<=m)ma=min(ma,getMin0(l,r,s,m,p*2));
		if (r>m)ma=min(ma,getMin0(l,r,m+1,t,p*2+1));
		return ma;
	}
public:
	T getMin(int l,int r){
		return getMin0(l,r,1,size,1);
	}
	~segTree2(){
		delete [] d;
		delete [] b;
	}
};
int t,n;ll a[maxn];
signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		segTree<ll> s1(a,a+n);
		segTree2<ll> s2(a,a+n);
		int now=1;
		int ans=0;
		int m;
		//cout<<s1.getMax(1,2)<<endl;
		while(now!=n){
			int l=now,r=n;
			m=(l+r)/2;
			while(l<r){
				if(l==r-1){
					//cout<<now<<" "<<r<<endl;
					int ma=s1.getMax(now,r);
					int mi=s2.getMin(now,r);

					if((mi==a[now]&&ma==a[r])||(mi==a[r]&&ma==a[now])){
						m=r;
						
					}
					else{
						m=l;
						
					}
					break;
				}
				//cout<<l<<" "<<r<<endl;
				int ma=s1.getMax(l,m);
				int mi=s2.getMin(l,m);
				if((mi==a[now]&&ma==a[m])||(mi==a[m]&&ma==a[now])){
					l=m;
				}
				else{
					r=m-1;
				}
				
			}
			now=m;
			++ans;
		}
		cout<<ans<<endl;
		
	}			return 0;}