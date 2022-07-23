#include<bits/stdc++.h>
#define maxm 100005
using namespace std;
int m,n;
int a[maxm];
int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n;
    for(int i=0;i<m;++i)cin>>a[i];
    long long s=0;
    sort(a,a+m);
    for(int i=0;i<n;++i){
        int in;
        cin>>in;
        int x=in<a[0]?1e9:in-*(lower_bound(a,a+m,in)-1);
        int y=in>a[m-1]?1e9:*lower_bound(a,a+m,in)-in;
        s+=min(x,y);
    }
    cout<<s<<endl;
    
    
    return 0;
}