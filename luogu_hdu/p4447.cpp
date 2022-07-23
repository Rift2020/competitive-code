#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        int in;
        cin>>in;
        if(mp.find(in)==mp.end())mp[in]=1;
        else ++mp[in];
    }
    int len,ans=1e9,now=-1e9,la=-1e9;
    while(!mp.empty()){
        len=0,now=-1e9,la=-1e9;
        for(auto &i:mp){
            if(i.second<now||!(i.first==la+1||la==-1e9))break;
            now=i.second;
            i.second--;
            ++len;
            la=i.first;
        }
        while(!mp.empty()&&mp.begin()->second==0)mp.erase(mp.begin());
        ans=min(ans,len);
    }
    cout<<ans<<endl;


    
    return 0;
}