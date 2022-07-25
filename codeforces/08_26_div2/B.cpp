#include<iostream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <string.h>
#define maxn 100005
using namespace std;
bool isPrime[maxn];
string s;
set<int> st,cl;
void dfs(string now,int i,int x){
    if(x==0){
        st.insert(atoi(now.c_str()));
        return;
    }
    if(i==s.size())return;
    dfs(now+s[i],i+1,x-1);
    dfs(now,i+1,x);
}
bool solve(int x){
    st=cl;
    dfs("",0,x);
    for(int i:st){
        //cout<<i<<" ";
        if(isPrime[i]==false){
            cout<<x<<endl;
            cout<<i<<endl;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    int n=maxn-5;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;++i){
        if(isPrime[i]){
            //prime.push_back(i);
        }
        for(long long j=(long long)i*i;j<=n;j+=i){//long long防止溢出
            isPrime[j]=false;
        }
    }
    int t,nn;
    cin>>t;
    while (t--) {
        cin>>nn;
        cin>>s;
        for(int i=1;;++i){
            if(solve(i))break;
        }
    }
    
    return 0;
}
