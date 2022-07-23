#include<bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n,k;
int a[maxn];
int q(int x){
    int re=0;
    for(int i=0;i<n;++i)re+=a[i]/x;
    return re;
}
signed main(){
	//freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    int ml=0;
    long long s=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        s+=a[i];
        ml=max(ml,a[i]);
    }
    if(s<k)cout<<0<<endl;
    else{
        int l=1,r=s/k+1;
        //cout<<r<<endl;
        while(l<=r){
        int m=(l+r)/2;
        //cout<<m<<endl;
        if(q(m)>=k&&q(m+1)<k){
            cout<<m<<endl;
            break;
        }
        else if(q(m)>=k){
            l=m;
        }
        else{
            r=m;
        }
        }
        
    }
    
    return 0;
}