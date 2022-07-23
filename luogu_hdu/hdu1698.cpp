#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long int;
template<typename T>
struct segTree{
	T *d;
	T *b;
    bool *upd;
	int size;
	segTree(int size){
		segTree::size=size;
		d=new T[size*4]();
		b=new T[size*4]();
        upd=new bool[size*4]();
	}
	void build(int s,int t,int p,T *a){
		if(s==t){
			d[p]=a[s];
			return;
		}
		int m=s+((t-s)>>1);//等价于(s+t)/2但可以防止溢出
		build(s,m,p*2,a),build(m+1,t,p*2+1,a);
		d[p]=d[p*2]+d[p*2+1];
	}
	segTree(T* l,T* r){
		segTree::size=r-l+1;
		d=new T[size*4];
		b=new T[size*4]();
        upd=new bool[size*4]();
		build(1,size,1,l);
	}
	private:
    T getSum0(int l, int r, int s, int t, int p) {
		if (l <= s && t <= r) return d[p];
		int m = s + ((t - s) >> 1);
		if (upd[p]) {
			d[p*2]=b[p]*(m-s+1),d[p*2+1]=b[p]*(t-m);
			b[p*2]=b[p*2+1]=b[p];
            upd[p*2]=upd[p*2+1]=true;
			upd[p]=false;
            b[p]=0;
		}
		T sum = 0;
		if (l<=m)sum=getSum0(l,r,s,m,p*2);
		if (r>m)sum+=getSum0(l,r,m+1,t,p*2+1);
		return sum;
	}
    void update0(int l, int r, T k, int s, int t, int p) {
		if(l<=s&&t<=r){
			d[p]=(t-s+1)*k,b[p]=k,upd[p]=true;
			return;
		}
		int m=s+((t-s)>>1);
		if(upd[p]){
			d[p*2]=b[p]*(m-s+1),d[p*2+1]=b[p]*(t-m);
			b[p*2]=b[p*2+1]=b[p];
            upd[p*2]=upd[p*2+1]=true;
			upd[p]=false;
            b[p]=0;
		}
		if (l<=m)update0(l,r,k,s,m,p*2);
		if (r>m)update0(l,r,k,m+1,t,p*2+1);
		d[p]=d[p*2]+d[p*2+1];
	}
    public:
    T getSum(int l,int r){
		return getSum0(l,r,1,size,1);
	}
	void update(int l,int r,T k){
		update0(l,r,k,1,size,1);
	}
	~segTree(){
		delete [] d;
		delete [] b;
	}
};
int t,n,q,x,y,k;
int main(){
    ios::sync_with_stdio(false);
    //segTree<int> st(maxn);
    cin>>t;
    rep(e,1,t){
        cin>>n;
        segTree<int> st(n);
        cin>>q;
        st.update(1,n,1);
        rep(i,1,q){
            cin>>x>>y>>k;
            st.update(x,y,k);
        }
        cout<<"Case "<<e<<": The total value of the hook is "<<st.getSum(1,n)<<"."<<endl;
    }
    
    
    
    return 0;
}