#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long;
int n,k;
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    int la=a[1];
    int ans=1;
    rep(i,2,n){
        if(a[i]-k>=la){
            ++ans;
            la=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}