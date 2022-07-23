#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
string s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        int ind;
        cin>>s;
        ind=s.find("std::make_tuple");
        while(ind!=-1){
            s.erase(ind,string("std::make_tuple").size());
            ind=s.find("std::make_tuple");
        }
        cout<<s<<endl;
    }
    
    
    
    return 0;
}