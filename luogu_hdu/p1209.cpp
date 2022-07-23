#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,s,c;
    cin>>m>>s>>c;
    if(m>=c){
        cout<<c;
        return 0;
    }
    int a[s+1]={0};
    int n,d1=0,d2=0;
    int c2=c;
    while (c--)
    {   
        scanf("%d",&n);
        a[n]=1;
    }
    for(int i=0;i<s+1;++i){
        if(a[i]==1){
            d1=i;
            break;
        }
    }
    for(int i=s;i>0;--i){
        if(a[i]==1){
            d2=i;
            break;
        }
    }
    int d=d2-d1+1;
    int b[s+1];
    memset(b,0,sizeof(b));
    for(int i=d1;i<d2;++i){
        if(a[i]==1){
            for(int j=i+1;j<s+1;++j){
                if(a[j]==1){
                    b[i]=j-i-1;
                    break;
                }
            }
        }
    }
    sort(b,b+s+1);
    /*
    for(int i=0;i<s+1;++i){
        cout<<b[i]<<" ";
    }
    */
    --m;
    for(int i=s;;--i){
        if(m==0)break;
        --m;
        d-=b[i];
    }
    cout<<d;
    return 0;
}