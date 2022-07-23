#include<bits/stdc++.h>
#define maxn 55
using namespace std;
set<int> s[maxn],ss;
int n,m,k,a,b,in;
void solve(int a,int b){
    ss.clear();
    for(auto i:s[a])ss.insert(i);
    for(auto i:s[b])ss.insert(i);
    printf("%.2lf%%\n",(s[a].size()+s[b].size()-ss.size())*100.0/ss.size());
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m;
        for(int j=0;j<m;++j){
            cin>>in;
            s[i].insert(in);
        }
    }
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>a>>b;
        solve(a,b);
    }
    
    
    return 0;
}