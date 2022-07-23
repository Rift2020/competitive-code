#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
int t,a,b,c;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        c=c%2;
        if(b>=3)b=2+b%2;
        if(a>=3)a=2+a%2;
        int x=0,y=c*3;
        while(b--){
            if(x<y)x+=2;
            else y+=2;
        }
        while(a--){
            if(x<y)x++;
            else y++;
        }
        cout<<abs(x-y)<<endl;
    }
    
    
    
    return 0;
}