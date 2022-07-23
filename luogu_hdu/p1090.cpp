#include<bits/stdc++.h>
#define maxn 10005
#define int long long
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>> pq;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        int in;
        cin>>in;
        pq.push(in);
    }
    int ans=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}