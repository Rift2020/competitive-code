#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005
#define endl '\n'
using namespace std;
using ll = long long;
int a[maxn];
ll n,t,mi,in;
ll s;
int inline abs(int x){
    if(x>=0)return x;
    return -x;
}
ll inline abs(ll x){
    if(x>=0)return x;
    return -x;
}
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        s=0;
        rep(i,1,n)scanf("%d",&a[i]);
        if(n==1){
            printf("%d\n",a[1]);
            continue;
        }
        mi=(ll)abs(a[1])+(ll)abs(a[2])-(ll)a[1]+(ll)a[2],in=1;
        
        rep(i,1,n){
            int ne=i+1;
            if(ne==n+1)ne=1;
            ll now=(ll)a[i]-(ll)a[ne];
            now=(ll)abs(a[i])+(ll)abs(a[ne])-now;
            if(now<mi){
                mi=now;
                in=i;
            }
        }
        int ne=in+1;
        if(ne==n+1)ne=1;
        rep(i,1,n){
            if(i==in){
                s+=a[i];
            }
            else if(i==ne){
                s-=a[i];
            }
            else
                s+=abs(a[i]);
        }
        printf("%lld\n",s);
    }
    
    
    
    return 0;
}