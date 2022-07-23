#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,c;
map<int,int> mp;
int main(){
    
    ios::sync_with_stdio(false);
    cin>>n>>c;
    for(int i=0;i<n;++i){
        int in;
        cin>>in;
        mp[in]++;
    }
    long long ans=0;
    for(auto i:mp){
        int a=i.first;
        if(mp.find(a-c)!=mp.end())
            ans+=(long long)mp[a]*mp[a-c];
    }
    cout<<ans<<endl;
    return 0;
}