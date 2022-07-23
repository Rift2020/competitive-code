#include<bits/stdc++.h>
#define p 19260817
#define ll long long
using namespace std;
int main(){
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    ll a[a1][a2],b[b1][b2];
    for(int i=0;i<a1;++i)
        for(int j=0;j<a2;++j)
            scanf("%lld",&a[i][j]);
    for(int i=0;i<b1;++i)
        for(int j=0;j<b2;++j)
            scanf("%lld",&b[i][j]);
    ll c[a1][b2];
    for(int i=0;i<a1;++i)
        for(int j=0;j<b2;++j){
            c[i][j]=0;
            for(int k=0;k<a2;++k){
                c[i][j]+=((a[i][k]%p)*(b[k][j]%p))%p;
                c[i][j]=c[i][j]%p;
            }
        }
    for(int i=0;i<a1;++i){
        for(int j=0;j<b2;++j){
            printf("%lld ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}