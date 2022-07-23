#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll
using namespace std;
using ll = long long;
int e,r,p,q,t,k;
bool fl;
void check(int m){
    int rr=(e*q)%m;
    if(e==(rr*p))
        cout<<m<<" "<<rr<<endl;
    if(e==(rr*p)%m&&r==-1){
        r=rr;
        fl=true;
    }
    else if(e==(rr*p)%m&&fl&&rr!=r){
        fl=false;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>p>>q>>e;
        k=p*q-1;
        fl=false;
        r=-1;
        for(int i=max({p,q,e})+1;i<=k;++i){
            if(k%i==0)
                check(i);
        }
        if(fl==false){
            cout<<"shuanQ"<<endl;
        }
        else{
            cout<<r<<endl;
        }
    }
    
    
    
    return 0;
}