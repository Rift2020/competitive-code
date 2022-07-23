//最后一个点没过
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p;
vector<int> v;
ll fprime(int x){
    for(ll i=2;i<=sqrt(x);++i){
        if(x%i==0)return i;
    }
    return x;
}
int main(){
    cin>>p;
    cout<<p<<"=";
    ll f;
    while(p!=1){
        f=fprime(p);
        v.push_back(f);
        p/=f;
    }
    
    int k;
    for(int i=0;i<v.size();i=i+k){
        k=0;
        for(int j=i;j<v.size()&&v[i]==v[j];++j)++k;
        if(k>1)
            cout<<v[i]<<'^'<<k;
        else
            cout<<v[i];
        if(i+k!=v.size())
            cout<<"*";
    }
    cout<<endl;
    return 0;
}