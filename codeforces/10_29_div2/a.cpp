#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        if(in[0]!=in[in.size()-1]){
            if(in[0]=='a')
                in[0]='b';
            else
                in[0]='a';
        }
        cout<<in<<endl;
    }
    
    
    
    return 0;
}