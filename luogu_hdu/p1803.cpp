#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct st{
    int a,b;
};
bool operator<(st x,st y){
    return x.b>y.b;
}
int n;
priority_queue<st> pq;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int ia,ib;
        cin>>ia>>ib;
        pq.push(st{ia,ib});
    }
    int la=0,ans=0;
    while(!pq.empty()){
        st tp=pq.top();
        pq.pop();
        if(tp.a>=la){
            la=tp.b;
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}