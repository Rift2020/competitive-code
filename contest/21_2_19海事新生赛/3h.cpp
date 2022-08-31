#include<bits/stdc++.h>
using namespace std;
int prime(int x){
    for(int i=2;i<=sqrt(x);++i){
        if(x%i==0)return 0;
    }
    return 1;
}
int main(){
    int k=0;
    for(int i=2;i<=1000000;++i)
        if(prime(i)){++k;cout<<i<<",";}
    cout<<endl;
    cout<<k;
    
    return 0;
}