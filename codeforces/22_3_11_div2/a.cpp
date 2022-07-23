#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        string a,b;
        int x=0,y=0;
        for(int i=1;;++i){
            if(i%2==1){
                a+='1';
                b+='2';
                x+=1,y+=2;
            }
            else{
                a+='2';
                b+='1';
                x+=2,y+=1;
            }
            if(y==n){
                cout<<b<<endl;
                break;
            }
            if(x==n){
                cout<<a<<endl;
                break;
            }
            
        }
    }
    
    
    
    return 0;
}