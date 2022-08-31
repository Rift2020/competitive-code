#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 55
using namespace std;
using ll = long long int;
int h,w;
int a[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>h>>w;
    rep(i,1,h)
        rep(j,1,w)
            cin>>a[i][j];
    bool fl=true;
    for(int i1=1;i1<=h;++i1){
        for(int j1=1;j1<=w;++j1){
            for(int i2=i1+1;i2<=h;++i2){
                for(int j2=j1+1;j2<=w;++j2){
                    if(a[i1][j1]+a[i2][j2]>a[i2][j1]+a[i1][j2]){
                        cout<<"No"<<endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    
    
    return 0;
}