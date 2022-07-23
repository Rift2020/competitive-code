#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n,m,ml;
int a[maxn];
int inline cal(int h){
    int re=0;
    for(int i=0;i<n;++i){
        re+=max(0LL,a[i]-h);
    }
    return re;
}
int isAnswer(int x){
    if(cal(x)>=m&&cal(x+1)<m){
        cout<<x<<endl;
        exit(0);
    }
    return cal(x);
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        ml=max(ml,a[i]);
    }
    int l=0,r=ml;
    while(l<=r){
        int mi=(l+r)/2;
        if(isAnswer(mi)<m){
            r=mi;
        }
        else l=mi;
    }

    
    return 0;
}