#include<bits/stdc++.h>
using namespace std;

int fpow2(int x,int n){
    if(n==0)return 1;
    int hf=fpow2(x,n/2);
    if(n%2==0)
        return hf*hf;
    else
        return hf*hf*x;
}
int inline fpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re*=x;
        x*=x;
        n>>=1;
    }
    return re;
}
int main(){
    cout<<fpow(5,1);
    
    
    return 0;
}