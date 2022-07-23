#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long int;
int t,n;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n)cin>>a[i];
        bool has=false;
        rep(i,1,n-1)
            if(a[i]>=a[i+1])has=true;
        if(has==false&&n%2==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    
    
    return 0;
}