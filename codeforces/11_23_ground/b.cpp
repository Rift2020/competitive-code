#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
using namespace std;
using ll = long long;
int t,n;
int a[maxn];
int x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n)
            cin>>a[i];
        bool is=true;
        for(int i=1,j=n;i<j;++i,--j){
            if(a[i]!=a[j]){
                x=a[i],y=a[j];
                is=false;
                break;
            }
        }
        if(is){
            cout<<"YES"<<endl;
            continue;
        }
        bool ok=true;
        for(int i=1,j=n;i<j;){
            if(a[i]==a[j]){
                ++i,--j;
                continue;
            }
            if(a[i]==x){
                ++i;
            }
            else if(a[j]==x){
                --j;
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok==true){
            cout<<"YES"<<endl;
            continue;
        }
        ok=true;
        for(int i=1,j=n;i<j;){
            if(a[i]==a[j]){
                ++i,--j;
                continue;
            }
            if(a[i]==y){
                ++i;
            }
            else if(a[j]==y){
                --j;
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok==true){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}