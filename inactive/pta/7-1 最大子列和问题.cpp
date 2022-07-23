#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    int a[k+1];
    a[0]=0;
    for(int i=1;i<k+1;++i)
    {
       scanf("%d",&a[i]); 
    }
    int s[k+1];
    s[0]=a[0];
    for(int i=1;i<k+1;++i){
        s[i]=s[i-1]+a[i];
    }
    int max=0;
    for(int i=0;i<k+1;++i)
        for(int j=i;j<k+1;++j){
            if(s[j]-s[i]>max)
                max=s[j]-s[i];
        }
    cout<<max<<endl;
    return 0;
}