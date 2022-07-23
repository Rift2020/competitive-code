#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
ll x,y,k;
int main(){
    ios::sync_with_stdio(false);
    cin>>x>>y>>k;
    cout<<(k%x)-(y%k)<<endl;
    
    
    
    return 0;
}