#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
string s;
map<char,int> mp;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        mp.clear();
        cin>>s;
        for(char i:s)mp[i]++;
        for(int i=0;i<s.size();++i){
            if(mp[s[i]]<=1){
                cout<<s.substr(i)<<endl;
                break;
            }
            mp[s[i]]--;
        }
    }
    
    
    
    return 0;
}