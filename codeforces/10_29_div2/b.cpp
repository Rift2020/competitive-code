#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
__int128 n,k,ans,now;
ll in1,in2;
//_int128  
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>in1>>in2;
        n=in1,k=in2;
        n--;
        now=1;
        ans=0;
        if(n>0)
        for(ans=1;;++ans){
            n-=now;
            now*=2;
            if(now>=k){
                now=k;
                break;
            }
            if(n<=0)break;
        }
        if(n<=0)
            cout<<(ll)ans<<endl;
        else if(n%now==0){
            cout<<(ll)(ans+n/now)<<endl;
        }
        else{
            cout<<(ll)(ans+n/now+1)<<endl;
        }
    }
    
    
    
    return 0;
}