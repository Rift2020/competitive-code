#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        int a=n-n/2;
        int b=n-(n-1)/3;
        b/=2;
        if(n%2==1&&((n-1)/3+1)%2==1){
            b++;
        }
        cout<<a+b<<endl;
    }
    
    
    return 0;
}