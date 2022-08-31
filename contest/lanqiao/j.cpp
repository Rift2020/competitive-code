#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int n;
int w[maxn];
int v[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,1,n){
        cin>>w[i]>>v[i];
    }
    int a[n];
    int ans=0;
    for(int i=0;i<n;++i)a[i]=i+1;
    do{
        int kk=0;
        for(int k=1;k<=n;++k){
            int s=0;
            for(int i=1;i<=k;++i){
                s+=w[a[i]];
            }
            bool fl=true;
            for(int i=1;i<k;++i){
                s-=w[a[i]];
                if(s>v[a[i]]){
                    fl=false;
                    break;
                }
            }
            if(fl){
                kk=k;
            }
            else{
                break;
            }
        }
        int ss=0;
        rep(i,1,kk)ss+=v[a[i]];
        ans=max(ans,ss);
    }while(next_permutation(a,a+n));
    cout<<ans<<endl;
    
    return 0;
}