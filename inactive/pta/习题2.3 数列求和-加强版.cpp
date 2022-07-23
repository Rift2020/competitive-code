//unpassed
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,n,s,ans=0;
int main(){
    cin>>a>>n;
    s=a;
    for(ll i=1;i<=n;++i){
        ans+=s;
        s=s*10+a;
    }
    cout<<ans;
    return 0;
}