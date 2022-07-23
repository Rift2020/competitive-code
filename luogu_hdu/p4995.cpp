#include<bits/stdc++.h>
#define maxn 305
using namespace std;
int n,a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    long long ans=a[n-1]*a[n-1],now=n-1;
    for(int l=0,r=n-1;l<=r;){
        ans+=(a[l]-a[r])*(a[l]-a[r]);
        if(now==r){
            now=l;
            r--;
        }
        else {
            now=r;
            ++l;
        }
    }
    cout<<ans<<endl;


    
    return 0;
}