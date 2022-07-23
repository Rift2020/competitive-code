#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long int;
int t,n;
int in[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
int sf[maxn];
int fsf[maxn];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(false);
    
    cin>>t;
    while(t--){
        cin>>n;
        srand(time(NULL));
        rep(i,1,n)sf[i]=i;
        random_shuffle(sf+1,sf+n+1);
        rep(i,1,n)cin>>in[i];
        rep(i,1,n){
            a[sf[i]]=in[i];
        }
        rep(i,1,n){
            fsf[sf[i]]=i;
        }
        if(n%2==0){
            for(int i=1,j=n;i<j;++i,--j){
                b[i]=a[j]/gcd(a[j],a[i]);
                b[j]=-a[i]/gcd(a[j],a[i]);
            }
        }
        else{
            int l=n/2,m=l+1,r=l+2;
            for(int i=1,j=n;i!=l;++i,--j){
                b[i]=a[j];
                b[j]=-a[i];
            }
            if(a[m]+a[r]==0){
                b[l]=(a[m]*a[r]);
                b[m]=a[l]*a[r];
                b[r]=-a[l]*a[m]*2;
            }
            else{
                b[l]=(a[m]+a[r])/gcd(a[m]+a[r],a[l]);
                b[m]=b[r]=-a[l]/gcd(a[m]+a[r],a[l]);
            }
        }
        rep(i,1,n){
            ans[fsf[i]]=b[i];
        }
        rep(i,1,n)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    
    
    return 0;
}