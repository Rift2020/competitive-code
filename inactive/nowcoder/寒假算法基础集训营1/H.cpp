#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
template<typename T>
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
        if(r<l)return 0;
        return query0(r)-query0(l-1);
    }
};
BITree<ll> st(maxn);
BITree<int> num(maxn);
int n;
ll ans=0;
int v[1000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        int in;
        cin>>in;
        v[n-i+1]=in;
    }
    ll ss=0,snum=0,num0=0;
    for(int i=1;i<=n;++i){
        if(v[i]!=0){
            st.add(v[i],v[i]);
            num.add(v[i],1);
        }
        else num0++;
        ss+=v[i];
        snum++;
        int l=1000-v[i];
        int r=l+1;
        ll xy=st.getSum(1,l),dy=ss-xy;
        ll xnum=num.getSum(1,l)+num0,ynum=snum-xnum;
        ans+=xnum*1000-xnum*v[i]-xy;
        ans+=ynum*v[i]+dy-ynum*1000;
    }
    cout<<ans<<endl;
    return 0;
}