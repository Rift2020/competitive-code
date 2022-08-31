#include<bits/stdc++.h>
using namespace std;
int k=0,m,n;
void move(int n,char a,char b,char c)
{
    if(n==1){
        if(m==0)exit(0);
        printf("%d:%d.%c->%c\n",++k,n,a,c);
        --m;
    }
    else
    {
        move(n-1,a,c,b);
        if(m==0)exit(0);
        printf("%d:%d.%c->%c\n",++k,n,a,c);
        --m;
        move(n-1,b,a,c);            
    }
}
int main(){
    cin>>n>>m;
    move(n,'1','2','3');
    
    return 0;
}