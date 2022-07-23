#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005
using namespace std;
using ll = long long;
int n,k;
int a[maxn],ans;
int now[maxn*5],ma[maxn*5],s[maxn*5];
unordered_set<int> us;
signed main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%d",&a[i]);
        a[i]+=2e6;
    }
    rep(i,1,n){
        us.insert(a[i]);
        s[a[i]]++;
        now[a[i]]++;
        now[a[i]-k]--;
        if(now[a[i]-k]<0)now[a[i]-k]=0;
        ma[a[i]]=max(ma[a[i]],now[a[i]]);
    }
    for(auto i:us){
        ans=max(ans,s[i]+ma[i-k]);
    }
    printf("%d\n",ans);
    
    return 0;
}
