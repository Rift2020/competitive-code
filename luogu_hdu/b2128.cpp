#include<bits/stdc++.h>
using namespace std;
bool inline isPrime(const int &n){
    if(n<2)return false;
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return true;
}
int n;
int main(){
    cin>>n;
    int ans=0;
    for(int i=2;i<=n;++i){
        if(isPrime(i))++ans;
    }
    cout<<ans<<endl;
    
    return 0;
}