#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
string from,to;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>from>>to;
        bool ok=false;
        int i=from.size()-1,j=to.size()-1;
        while(1){
            if(from[i]==to[j]){
                i--,j--;
            }
            else{
                i-=2;
            }
            if(j<=-1){
                ok=true;
                break;
            }
            if(i<=-1){
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}