#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
typedef pair<int,int> pr;
pr a[3];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        rep(i,0,2)cin>>a[i].first>>a[i].second;
        int ans=0;
        rep(i,0,2){
            if(a[i].second==a[(i+1)%3].second&&a[i].second!=0&&a[(i+2)%3].second<a[i].second)ans+=abs(a[i].first-a[(i+1)%3].first);
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}