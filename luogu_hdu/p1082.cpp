/**
 *    author:  Rift
 *    created: 2022.08.11  10:42
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return g;
}
int a,b;
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int x,y;
    cin>>a>>b;
    int g=exgcd(a,b,x,y);
    int x1=x/g;
    cout<<(x1%b+b)%b<<endl;


    return 0;
}
