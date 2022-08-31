#include<bits/stdc++.h>
#define maxn 205
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
int n;
bool s[maxn][maxn],t[maxn][maxn];
bool cs[maxn][maxn],cst[maxn][maxn],tt[maxn][maxn];
void turn(bool a[maxn][maxn],bool to[maxn][maxn]){
    int lm=1e9,tm=1e9;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]){
                lm=min(lm,j);
                tm=min(tm,i);
            }
        }
    }
    for(int i=0;i+tm<=n;++i){
        for(int j=0;j+lm<=n;++j){
            to[i][j]=a[i+tm][j+lm];
        }
    }
}
void check(bool a[maxn][maxn],bool b[maxn][maxn]){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(a[i][j]!=b[i][j])return;
        }
    }
    cout<<"Yes"<<endl;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            char c;
            cin>>c;
            if(c=='#')s[i][j]=true;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            char c;
            cin>>c;
            if(c=='#')t[i][j]=true;
        }
    }
    turn(t,tt);
    turn(s,cst);
    check(cst,tt);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cs[j][n-i+1]=s[i][j];
        }
    }
    memset(cst,false,sizeof(cst));
    turn(cs,cst);
    check(cst,tt);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cs[n-j+1][i]=s[i][j];
        }
    }
    memset(cst,false,sizeof(cst));
    turn(cs,cst);
    check(cst,tt);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cs[n-i+1][n-j+1]=s[i][j];
        }
    }
    memset(cst,false,sizeof(cst));
    turn(cs,cst);
    check(cst,tt);
    cout<<"No"<<endl;
    return 0;
}