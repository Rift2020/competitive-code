#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int zc(int x){
    if(x==1)return -1;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return i;
    }
    return x;
}
signed main(){
    ios::sync_with_stdio(false);    
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==1&&b==1){
            cout<<-1<<" "<<-1<<endl;
        }
        else if(a==b){
            cout<<2<<" "<<a<<endl;
        }
        else{
            int d=b-a;
            if(d>1)
                cout<<zc(d)<<" "<<d<<endl;
            else
                cout<<-1<<" "<<-1<<endl;
        }
    }
    return 0;
}