#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
#define int ll
using namespace std;
using ll = long long;
typedef pair<int,int> pr;
int n,m;
pr a[maxn];
int s[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i].first;
    }
    rep(i,1,n){
        cin>>a[i].second;
    }
    sort(a+1,a+n+1);
    rep(i,1,n){
        s[i]=s[i-1]+a[i].first;
    }
    int low=0;
    if(m>=a[n].first*(n-1)-s[n-1]){
        m-=a[n].first*(n-1)-s[n-1];
        low=a[n].first+m/n;
    }
    else{
        for(int i=n;i>=2;--i){
            if(m>=a[i].first*(i-1)-s[i-1]){
                low=a[i].first;
                break;
            }
        }
    }
    if(low==0)low=a[1].first;
    int low2=INT_MAX;
    rep(i,1,n){
        low2=min(low2,a[i].first+a[i].second);
    }
    cout<<min(low,low2)<<endl;

    
    return 0;
}