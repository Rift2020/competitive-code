#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[n+1-m];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int s=0;
    for(int i=0;i<m;++i){
        s+=a[i];
    }
    b[0]=s;
    int min=b[0];
    for(int i=1;i<n+1-m;++i){
        b[i]=b[i-1]-a[i-1]+a[i+m-1];
        if(b[i]<min){
            min=b[i];
        }
    }
    cout<<min;
    return 0;
}