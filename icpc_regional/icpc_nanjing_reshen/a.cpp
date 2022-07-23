#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n=620;
char c[4]={'U','L','D','R'};
signed main(){
    ios::sync_with_stdio(false);
    rep(i,1,n){
        for(char j:c){
            rep(k,1,20)
                cout<<j;
        }
    }
    
    
    
    return 0;
}