#include<bits/stdc++.h>
#define maxn 255
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int mem[maxn];
int main(){
    ios::sync_with_stdio(false);
    mem[0]=mem[1]=1;
    for(int i=2;i<=250;++i){
        mem[i]=i;
        for(int j=0;j<=i/2;++j){
            int k=i-j;
            mem[i]=max(mem[i],lcm(mem[j],mem[k]));
        }
    }
    while(1){
        int in;
        cin>>in;
        if(in==0)break;
        cout<<mem[in]<<endl;
    }
    return 0;
}