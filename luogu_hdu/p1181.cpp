#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int s=0,f=0;
    for(int i=0;i<n;++i){
        s+=a[i];
        if(s>m){
            ++f;
            s=0;
            --i;
        }
    }
    cout<<f+1;
    return 0;
}