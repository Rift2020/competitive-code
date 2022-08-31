#include<bits/stdc++.h>
using namespace std;
int bSort(int arr[], int len) {
    int i,j,k=0;
    for(int i=0;i<len-1;++i){
        for(int j=i+1;j<len;++j){
            if(arr[i]>arr[j])++k;
        }
    }
    cout<<k<<endl;
    return k; 
}
int main(){
    int n,s=0,ss=0;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<n;++i)scanf("%d",&b[i]);
    s=bSort(a,n)+bSort(b,n);
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;++i){
        ss+=(a[i]+b[i])*(a[i]+b[i]);
    }
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<ss<<" "<<s<<endl;
    return 0;
}