#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll
using namespace std;
using ll = long long;
int n;
int cnt;
int s[10];
bool isPrime(int x){
    if(x<=1)return false;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
bool check(){
    for(int i=0;i<n-1;++i){
        if(isPrime(s[i]+s[i+1])==false)return false;
    }
    return true;
}
int fact(int x){
    if(x<=1)return 1;
    return x*fact(x-1);
}
void kt(int x){
    x--;
    //string s;
    bool used[n]={0};
    for(int i=0;i<n;++i){
        int site=x/fact(n-i-1);
        int j;
        for(j=0;j<n;++j){
            if(used[j])continue;
            if(site==0)
                break;
            --site;
        }
        used[j]=true;
        s[i]=j+1;
        x%=fact(n-i-1);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n=10;
    cin>>cnt;
    for(int i=1;i<=fact(n);++i){
        kt(i);
        if(check()){
            --cnt;
            for(int i:s){
                cout<<i<<" ";
            }
            cout<<endl;
            if(cnt==0)break;
        }
    }
    
    
    
    return 0;
}