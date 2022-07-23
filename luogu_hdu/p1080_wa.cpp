//差个高精度
#include<bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n;
struct dc{
    int a,b;
};
bool operator<(dc x,dc y){
    return x.a*x.b<y.a*y.b;
}
dc a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<=n;++i)cin>>a[i].a>>a[i].b;
    sort(a+1,a+n+1);
    long long ans=0,ss=a[0].a;
    for(int i=1;i<=n;++i){
        ans=max(ans,ss/a[i].b);
        ss*=a[i].a;
    }
    cout<<ans<<endl;
    return 0;
}