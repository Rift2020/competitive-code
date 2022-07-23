#include<bits/stdc++.h>
#define maxn 30004
using namespace std;
int w,n;
int a[maxn];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin>>w>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    for(int l=0,r=n-1;l<=r;){
        if(l==r){
            ++ans;
            break;
        }
        if(a[l]+a[r]<=w){
            ++ans;
            ++l,--r;
        }
        else {
            ++ans;
            --r;
        }
    }
    cout<<ans<<endl;
    return 0;
}