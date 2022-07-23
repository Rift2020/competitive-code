#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long int;
int t,n;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n){
            cin>>a[i];
        }
        int ans=0;
        rep(i,1,n){
            ans=max(ans,a[i]-i);
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}