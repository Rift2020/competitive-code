#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int sol(int i,int x){
    return i-(1<<x)+1;
}
signed main(){
    ios::sync_with_stdio(false);
    while(1){
        int a,x;
        cin>>a>>x;
        cout<<sol(a,x)<<endl;
    }
    
    
    
    return 0;
}