#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n,a,b,t;
vector<int> x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        x.clear(),y.clear();
        cin>>a>>b>>n;
        int hf=n/2;
        if(n%2==1)hf++;
        rep(i,1,a){
            int in;
            cin>>in;
            x.push_back(in);
        }
        rep(i,1,b){
            int in;
            cin>>in;
            y.push_back(in);
        }
        if(a<hf){
            cout<<-1<<endl;
            continue;
        }
        sort(x.begin(),x.end(),greater<int>());
        int ans=0;
        for(int i=0;i<hf;++i){
            ans+=x[i];
        }
        for(int i=hf;i<x.size();++i){
            y.push_back(x[i]);
        }
        sort(y.begin(),y.end(),greater<int>());
        for(int i=0;i<n-hf;++i){
            ans+=y[i];
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}