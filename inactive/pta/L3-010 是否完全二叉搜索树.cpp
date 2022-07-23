#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int tree[maxn];
int n;
void insert(int x,int v){
    if(!tree[x]){
        tree[x]=v;
        return;
    }
    if(v>tree[x])
        insert(2*x,v);
    else
        insert(2*x+1,v);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        int in;
        cin>>in;
        insert(1,in);
    }
    int now=0,fl=1;
    for(int i=1;now<n;++i){
        if(tree[i]){
            ++now;
            if(i==1)
                cout<<tree[i];
            else
                cout<<" "<<tree[i];
        }
        if(i>n){
            fl=0;
        }
    }
    cout<<endl;
    if(fl)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}