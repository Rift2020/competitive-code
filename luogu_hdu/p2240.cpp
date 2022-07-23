#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int t,n;
struct gold{
    int m,v;
};
bool operator<(const gold a,const gold b){
    return (double)a.v/a.m>(double)b.v/b.m;
}
gold a[maxn];
int main(){
    double ans=0;
    cin>>n>>t;
    for(int i=0;i<n;++i){
        int im,iv;
        cin>>im>>iv;
        a[i].m=im,a[i].v=iv;
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        ans+=(double)min(t,a[i].m)*(double)a[i].v/a[i].m;
        t-=min(t,a[i].m);
        if(t==0)break;
    }
    printf("%.2f\n",ans);
    return 0;
}