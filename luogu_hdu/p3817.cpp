#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,x;
int a[maxn];
int main(){
    cin>>n>>x;
    long long ans=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(a[0]>x){
        ans+=a[0]-x;
        a[0]-=a[0]-x;
    }
    for(int i=1;i<n;++i){
        if(a[i]+a[i-1]>x){
            ans+=a[i]+a[i-1]-x;
            a[i]-=a[i]+a[i-1]-x;
        }
    }
    cout<<ans<<endl;
    return 0;
}