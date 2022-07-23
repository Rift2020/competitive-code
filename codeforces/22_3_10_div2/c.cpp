#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll
#define maxn 200005
using namespace std;
using ll = long long;
int a[maxn];
int b[maxn];
int n;
int t;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n)cin>>a[i];
        rep(i,1,n)cin>>b[i];
        int ans=INT_MAX;
        ans=min(abs(a[1]-b[1])+abs(a[n]-b[n]),abs(a[1]-b[n])+abs(a[n]-b[1]));
        int a1=INT_MAX,an=INT_MAX,b1=INT_MAX,bn=INT_MAX;
        rep(i,1,n){
            b1=min(b1,abs(a[i]-b[1]));
            bn=min(bn,abs(a[i]-b[n]));
        }
        rep(i,1,n){
            a1=min(a1,abs(b[i]-a[1]));
            an=min(an,abs(b[i]-a[n]));
        }
        ans=min(ans,a1+an+b1+bn);
        ans=min(ans,abs(a[1]-b[1])+an+bn);
        ans=min(ans,abs(a[1]-b[n])+an+b1);
        ans=min(ans,abs(a[n]-b[1])+a1+bn);
        ans=min(ans,abs(a[n]-b[n])+a1+b1);
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}