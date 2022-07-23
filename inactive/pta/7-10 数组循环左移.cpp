#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int n,m;
int a[maxn];
vector<int> fact;
void search_fact(int x){
    rep(i,1,x){
        if(x%i==0)fact.push_back(i);
    }
}
void roll(int dx){
    for(int i=0;i<dx;++i){
        int mem;
        bool f=true;
        for(int j=i;;j=(j-dx+n)%n){
            swap(mem,a[j]);
            if(j==i&&!f)break;
            f=false;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rep(i,0,n-1)cin>>a[i];
    m%=n;
    search_fact(n);
    while(m){
        int val=*(upper_bound(fact.begin(),fact.end(),m)-1);
        roll(val);
        m-=val;
    }
    rep(i,0,n-1){
        if(i!=0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;

    return 0;
}