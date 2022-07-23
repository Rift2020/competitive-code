#include<bits/stdc++.h>
#define maxn 100000005
using namespace std;
int mem[maxn];
int inline solve(int x){
    //if(mem[x])return mem[x];
    int cnt=0;
    int a=x;
    while(mem[a]==0){
        if(a%2==0){
            a/=2;
        }else{
            a=a*3+1;
        }
        cnt++;
    }
    return mem[x]=cnt+mem[a];
}
int main(){
    int l,r;
    cin>>l>>r;
    mem[1]=1;
    int ma=0;
    for(int i=l;i<=r;++i){
        ma=max(ma,solve(i));
    }
    cout<<ma<<endl;
    return 0;
}