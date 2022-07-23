#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005
using namespace std;
using ll = long long;
int t,n,m;
int a[maxn];
int s[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        bool fl=false;
        cin>>n;
        m=0;
        rep(i,0,n){
            cin>>a[i];
            m+=a[i];
        }
        if(a[0]>=1)fl=true;
        int now=2;
        rep(i,1,n){
            if(now>=1000001)break;
            if(a[i]>=now){
                fl=true;
                break;
            }
            now=now-a[i];
            now*=2;
        }
        if(fl)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;
    }
    
    
    
    return 0;
}