#include<bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    cin>>t>>m;
    int ct[m],cq[m];
    for(int i=0;i<m;++i){
        scanf("%d%d",&ct[i],&cq[i]);
    }
    int r[t+1];
    memset(r,0,sizeof(r));
    for(int i=0;i<m;++i)
        for(int j=0;j<=t;++j)
            if(j>=ct[i]&&r[j-ct[i]]+cq[i]>r[j])
                r[j]=r[j-ct[i]]+cq[i];
    cout<<r[t];
    return 0;
}