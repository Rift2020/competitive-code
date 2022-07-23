#include<bits/stdc++.h>
#define maxn 105*2
using namespace std;
int a[maxn],s[maxn],ma[maxn][maxn],mi[maxn][maxn],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
        //mi[i][i]=mi[i+n][i+n]=a[i];
    }
    //n*=2;
    s[1]=a[1];
    for(int i=2;i<=n*2;++i)s[i]=s[i-1]+a[i];

    for(int len=1;len<=n;++len){
        for(int i=1;i<n*2;++i){
            int j=i+len-1;
            //mi[i][j]=999999999;
            for(int k=i;k<j&&k<=n*2-1;++k){
                ma[i][j]=max(ma[i][j],ma[i][k]+ma[k+1][j]+s[j]-s[i-1]);
                if(mi[i][j]==0){mi[i][j]=mi[i][k]+mi[k+1][j]+s[j]-s[i-1];}
                else mi[i][j]=min(mi[i][j],mi[i][k]+mi[k+1][j]+s[j]-s[i-1]);
            }
        }
    }  
    //n/=2;
    int mmi=999999999,mma=0;
    for(int i=1;i<=n+1;++i){
        //cout<<ma[i][i+n-1]<<endl;
        if(mi[i][i+n-1]<mmi)mmi=mi[i][i+n-1];
        if(ma[i][i+n-1]>mma)mma=ma[i][i+n-1];
    }
    cout<<mmi<<endl<<mma;
    return 0;
}