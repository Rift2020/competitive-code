#include<bits/stdc++.h>
using namespace std;
int t;
int n,ma,mi,ave;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>ma>>mi>>ave;
        int all=ave*n;
        if(mi*(n-1)+ma<=all&&all<=ma*(n-1)+mi&&mi<=ma)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    
    
    return 0;
}