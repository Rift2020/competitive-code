#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    int ans=0;
    while(n>0){
        string s=to_string(n);
        int ma=0;
        for(char i:s)ma=max(ma,(int)(i-'0'));
        n-=ma;
        ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}