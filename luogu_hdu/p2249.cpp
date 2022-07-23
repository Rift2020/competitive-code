#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,m;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i){
        int in;
        cin>>in;
        if(lower_bound(a,a+n,in)!=a+n&&*lower_bound(a,a+n,in)==in)
            cout<<lower_bound(a,a+n,in)-a+1<<" ";
        else
            cout<<-1<<" ";
    }
    
    
    return 0;
}