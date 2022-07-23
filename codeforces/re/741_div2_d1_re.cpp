#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int t,n,q;
int a[maxn];
int sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>q;
        for(int i=1;i<=n;++i){
            char c;
            cin>>c;
            if(c=='+')a[i]=1;
            else a[i]=-1;
        }
        for(int i=1;i<=n;++i){
            if(i%2==1)
                sum[i]=sum[i-1]+a[i];
            else 
                sum[i]=sum[i-1]-a[i];
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            int now=sum[r]-sum[l-1];
            if(now==0)cout<<0<<endl;
            else if(len%2==0)cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
    
    
    return 0;
}