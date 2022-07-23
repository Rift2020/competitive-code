#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,x,d;
bool isPrime(int x){
    if(x==1)return true;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>x>>d;
        if(x%(d*d)!=0){
            cout<<"NO"<<endl;
            continue;
        }
        int cnt=0;
        while(x%d==0){
            cnt++;
            x/=d;
        }
        if((cnt>=4&&!isPrime(d))||!isPrime(x)){
            cout<<"YES"<<endl;
            continue;
        }
        if(isPrime(d)||cnt==2){
            cout<<"NO"<<endl;
            continue;
        }
        int sqr=sqrt(d);
        if(sqr*sqr==d&&isPrime(sqr)&&x==sqr){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    
    
    
    return 0;
}