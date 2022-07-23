#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long long
using namespace std;
int t;
int x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(y%x==0){
            cout<<x<<endl;
        }
        else if(x<y){
            cout<<(x+y)/2<<endl;
        }
        else{
            int i=1.9e18;
            int k=((i%x)-(y%i));
            if(k==0);
            else if(k>0)i-=k;
            else{
                i-=k+x;
            }
            cout<<i<<endl;
        }
    }
    
    
    return 0;
}