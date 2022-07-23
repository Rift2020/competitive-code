#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,k;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n,greater<int>());
    long long ans=0;
    for(int i=0;i<k;++i)ans+=a[i];
    cout<<ans<<endl;
    
    
    return 0;
}