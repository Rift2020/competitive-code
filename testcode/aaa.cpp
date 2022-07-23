#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct Mt{
    ll d[2][2];
    Mt(){
        memset(d,0,sizeof(d));
    }
} mt;
const ll p=1000000007;
mt base,ans;
mt operator*(const mt& a,const mt& b){
    mt ret;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                ret.d[i][j]+=((a.d[i][k]%p)*(b.d[k][j])%p)%p;
            }
            ret.d[i][j]%=p;
        }
    return ret;
}
mt ksm(const mt& a,ll n){
    if(n==1)return a;
    mt ks=ksm(a,n/2);
    if(n%2==0) return ks*ks;
    else return ks*ks*a;
}
void qpow(int b) { // 求
    while (b) {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}
int main(){
    ll n;
    cin>>n;
    
    base.d[0][0]=0,base.d[0][1]=1,base.d[1][0]=1,base.d[1][1]=1;
    ans=base;
    n--;
    qpow(n);
    cout<<ans.d[1][0]%p<<endl;
    
    return 0;
}