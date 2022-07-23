#include<bits/stdc++.h>

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
int a,b,p,q,l,m,r;
double value(double a,double b){
    if(fabs((double)p/q-a/b-b/a)<=1e-6&&fabs(b-(int)b)<=1e-6)return 0;
    if((double)p/q>a/b+b/a)return -1;
    return 1;
}
int ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        ans=0;
        cin>>p>>q;
        int g=__gcd(p,q);
        p/=g;
        q/=g;
        l=1,r=1e9,m=(l+r)/2;
        while(l<r){
            if(value(m,(double)q/m)==0){
                ans=m;
                break;
            }
            if(value(l,(double)q/l)==0){
                ans=l;
                break;
            }
            if(value(r,(double)q/r)==0){
                ans=r;
                break;
            }
            if(l==r-1)break;
            if(value(m,(double)q/m)<0){
                r=m;
            }
            else if(value(m,(double)q/m)>0){
                l=m;
            }
            m=(l+r)/2;
        }
        if(ans!=0){
            cout<<ans<<" "<<q/ans<<endl;
        }
        else{
            cout<<0<<" "<<0<<endl;
        }
    }
    
    
    return 0;
}