#include<bits/stdc++.h>
using namespace std;
int n,s,a,b;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>s>>a>>b;
    for(int i=0;i<n;++i){
        int in,h;
        cin>>h>>in;
        if(h>a+b)continue;
        v.push_back(in);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i:v){
        if(i<=s){
            s-=i;
            ++ans;
        }
        else break;
    }
    cout<<ans<<endl;
    
    
    return 0;
}