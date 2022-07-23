#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
using namespace std;
using ll = long long;
int t,n;
struct st{
    int a,b,v;
};
st ar[maxn];
template<typename T>
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
        d[p]=d[p*2]+d[p*2+1];
    }
    segTree(T* l,T* r){
        segTree::size=r-l+1;
        d=new T[size*4];
        b=new T[size*4]();
        build(1,size,1,l);
    }
    private:
    T getSum0(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p]) {
            d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
            b[p*2]+=b[p],b[p*2+1]+=b[p];
            b[p]=0;
        }
        T sum = 0;
        if (l<=m)sum=getSum0(l,r,s,m,p*2);
        if (r>m)sum+=getSum0(l,r,m+1,t,p*2+1);
        return sum;
    }
    void add0(int l, int r, T k, int s, int t, int p) {
        if(l<=s&&t<=r){
            d[p]+=(t-s+1)*k,b[p]+=k;
            return;
        }
        int m=s+((t-s)>>1);
        if(s!=t&&b[p]){
            d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
            b[p*2]+=b[p],b[p*2+1]+=b[p];
            b[p]=0;
        }
        if (l<=m)add0(l,r,k,s,m,p*2);
        if (r>m)add0(l,r,k,m+1,t,p*2+1);
        d[p]=d[p*2]+d[p*2+1];
    }
    public:
    T getSum(int l,int r){
        if(l>r)return 0;
        return getSum0(l,r,1,size,1);
    }
    void add(int l,int r,T k){
        add0(l,r,k,1,size,1);
    }
    ~segTree(){
        delete [] d;
        delete [] b;
    }
};
int ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        segTree<int> seg(n);
        rep(i,1,n){
            int x,y;
            cin>>x>>y;
            ar[i]={y,x,i};
        }
        ans=0;
        per(i,n,1){
            ans=max(ans,1+min(ar[i].b,seg.getSum(ar[i].a+1,n)));
            if(ar[i].a>=i-1)
                seg.add(n,n,1);
            else if(ar[i].a>0)
                seg.add(ar[i].a,ar[i].a,1);
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}