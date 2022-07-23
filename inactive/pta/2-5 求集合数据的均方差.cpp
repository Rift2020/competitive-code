#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double avg=0,ans=0;
    cin>>n;
    double a[n];
    for(double &i:a){
        cin>>i;
        avg+=i;
    }
    avg/=n;
    for(double i:a){
        ans+=(i-avg)*(i-avg);
    }
    ans/=n;
    ans=sqrt(ans);
    printf("%.5lf\n",ans);
    return 0;
}