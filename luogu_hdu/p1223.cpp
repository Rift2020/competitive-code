#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct st{
    int t;
    int p;
};
bool operator<(st a,st b){
    return a.t<b.t;
}
st t[maxn];
int s[maxn],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i].t;
        t[i].p=i;
    }
    sort(t+1,t+n+1);
    for(int i=2;i<=n;++i)s[i]=s[i-1]+t[i-1].t;
    double ans=0;
    for(int i=1;i<=n;++i)ans+=s[i];
    ans/=n;
    for(int i=1;i<=n;++i)cout<<t[i].p<<" ";
    printf("\n%.2f\n",ans);
    return 0;
}