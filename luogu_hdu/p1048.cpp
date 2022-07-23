#include<bits/stdc++.h>
using namespace std;
int t,m;
int ct[105];
int cq[105];
int r[1005];
int main(){
    cin>>t>>m;
    for(int i=0;i<m;++i){
        cin>>ct[i]>>cq[i];
    }
    memset(r,0,sizeof(0));
    for(int i=0;i<m;++i)
        for(int j=t;j>=0;--j){
            if(j>=ct[i]&&r[j-ct[i]]+cq[i]>r[j])
                r[j]=r[j-ct[i]]+cq[i];
        }
    cout<<r[t];
    return 0;
}