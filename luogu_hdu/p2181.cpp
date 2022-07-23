#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n;
ll ans;
int main(){
    cin>>n;
    int nn=n-2;
    for(int l=1;l<nn;++l){
        int r=nn-l;
        ans+=(ll)l*r;
    }
    ans=ans*n/4;
    cout<<ans<<endl;
    return 0;
}