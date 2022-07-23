#include<bits/stdc++.h>
#define mod 19260817
using namespace std;
int inline mod_read(){
    int s=0,f=1;
    char c=getchar();
    while(!(c<='9'&&c>='0')){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        s=(s<<1)+(s<<3);
        s+=c-'0';
        s%=mod;
        c=getchar();
    }
    return f*s;
}
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=x*(a/b);
}
int mod_inverse(int a,int m){
    int x,y;
    exgcd(a,m,x,y);
    return (m+x%m)%m;//这一步是为了使不确定符号的x变为正数，为什么是这样我还不明白
}
int main(){
    int a,b;
    a=mod_read(),b=mod_read();
    if(b%mod==0)
        cout<<"Angry!"<<endl;
    else{
        b=mod_inverse(b,mod);
        cout<<((a%mod)*(long long)(b%mod))%mod<<endl;
    }
    
    
    return 0;
}