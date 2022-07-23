#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
unordered_map<string,int> mp;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,1,n){
        string in;
        cin>>in;
        mp[in]++;
    }
    int s=0,ss=0;
    string ans;
    for(auto i:mp){
        if(i.second>s){
            s=i.second;
            ans=i.first;
        }
        ss+=i.second;
    }
    if(s>ss-s)
        cout<<ans<<endl;
    else
        cout<<"NONE"<<endl;
    
    return 0;
}