#include<bits/stdc++.h>
using namespace std;
int a[]={0,7,27,41,49,63,78,108};
int t,n;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        long long s=0;
        for(int i=1;i<=n;++i){
            int in;
            cin>>in;
            s+=a[in];
        }
        if(s>=120)s-=50;
        else if(s>=89)s-=30;
        else if(s>=69)s-=15;
        cout<<s<<endl;
    }
    
    return 0;
}