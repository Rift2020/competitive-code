#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n;
signed main(){
    ios::sync_with_stdio(false);
    n=15;

    rep(p,1,n){
        rep(q,1,n){
            rep(a,1,q){
                rep(b,1,q){
                    if((double)p/q==(double)(a*a+b*b)/a/b){
                        cout<<p<<"/"<<q<<'='<<a<<" "<<b<<endl;
                    }
                }
            }
        }
    }
    
    
    
    return 0;
}