#include<bits/stdc++.h>
#include <stdlib.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
stringstream ss;
int w;
ull sr(ull x,bool f,int w){
    ull re;
    re=re&((1ULL<<(w-1))-1);
    if(f)re=re|(1ULL<<(w-1));
    return re;
}
ull stoy(string s,bool &f){
    ull re;
    if(s[0]=='-'){
        f=true;
        s.erase(s.begin());
    }
    ss.clear();
    ss<<s;
    ss>>re;
    re=re&((1ULL<<(w-1))-1);
    if(f)re=re|(1ULL<<(w-1));
    return re;
}
ull ytof(ull x,bool f){
    if(f){
        x=~x;
        x=x&((1ULL<<(w-1))-1);
        x=x|(1ULL<<(w-1));
    }
    return x;
}
ull ftob(ull x,bool f){
    if(f)++x;
    return x;
}
void printu2(ull x,ull w){
    string s;
    for(int i=0;i<w;++i){
        if(x&1)s+='1';
        else s+='0';
        x=x>>1;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
void print3t(int ym,bool f){
    cout<<" 原 反 补"<<endl;
    printu2(ym,w),cout<<"  ";
    printu2(ytof(ym,f),w),cout<<"  ";
    printu2(ftob(ytof(ym,f),f),w),cout<<endl;
}
void twoInteger(){
    //ull x=0,y=0;
    string in1,in2,z1,z2;
    bool f1=false,f2=false,f3=false,f4=false,f5=false;
    cout<<"计算两个(有符号)整数间加减法，输入位数(不能大于64)"<<endl;
    cin>>w;
    cout<<"输入需要计算的两个整数(十进制正常输入)"<<endl;
    cin>>in1>>in2;
    z1=to_string(atoll(in1.c_str())+atoll(in2.c_str()));
    z2=to_string(atoll(in1.c_str())-atoll(in2.c_str()));
    ull xy=stoy(in1,f1);
    ull yy=stoy(in2,f2);
    ull z1y=stoy(z1,f4);
    ull z2y=stoy(z2,f5);
    cout<<"A",print3t(xy,f1);
    cout<<"B",print3t(yy,f2);
    if(in2[0]=='-'){
        in2.erase(in2.begin());
    }
    else{
        in2='-'+in2;
    }
    ull fyy=stoy(in2,f3);
    cout<<"(-B)",print3t(fyy,f3);
    cout<<"(最前面多输出了2位)A+B补码为 ",printu2(ftob(ytof(z1y,f4),f4),w+2),cout<<endl;
    cout<<"(最前面多输出了2位)A-B补码为 ",printu2(ftob(ytof(z2y,f5),f5),w+2),cout<<endl;
}
void tohm(){
    cout<<"输入欲传送码(b4b3b2b1输出汉明码为c1c2b4c4b3b2b1)(同教材)"<<endl;
    string in;
    cin>>in;
    int n=in.size();
    int a[n+1];
    int ans[2*n+1];//ji
    int ans2[2*n+1];
    memset(ans,-1,sizeof(ans));
    memset(ans2,-1,sizeof(ans));
    rep(i,1,n)a[i]=in[i-1]-'0';
    int k=1;
    for(;(1<<k)<n+k+1;++k);
    for(int i=1,cnt=1;cnt<=k;(i=i<<1),cnt++){
        ans[i]=ans2[i]=-2;
    }
    int now=1;
    rep(i,1,k+n){
        if(ans[i]==-2)continue;
        ans[i]=ans2[i]=a[now];
        ++now;
    }
    for(ll p=1;p<=k;p++){
        int i=(1<<(p-1));
        int cnt=0;
        for(int j=i;j<=n+k;++j){
            if((i&j)&&ans[j]==1){
                cnt++;
            }
        }
        if(cnt%2==1){
            ans[i]=0;
            ans2[i]=1;
        }
        else{
            ans[i]=1;
            ans2[i]=0;
        } 
    }
    cout<<"配奇: ";
    for(int i=1;;++i){
        if(ans[i]==-1)break;
        cout<<ans[i];
    }
    cout<<endl;
    cout<<"配偶: ";
    for(int i=1;;++i){
        if(ans2[i]==-1)break;
        cout<<ans2[i];
    }
    cout<<endl;
}
void solvehm(){
    cout<<"请输入汉明码"<<endl;
    string in;
    cin>>in;
    int n=in.size();
    int a[n+1];
    rep(i,1,n)a[i]=in[i-1]-'0';
    int ans=0;
    bool fl=false;
    for(int i=1;i<=n;i=(i<<1)){
        int cnt=0;
        for(int j=i;j<=n;++j){
            if((j&i)&&a[j]==1){
                ++cnt;
            }
        }
        if(cnt%2==0){
            fl=true;
            ans+=i;
        }
    }
    cout<<"若配奇: "<<endl;
    if(fl==false){
        cout<<"没有错误位"<<endl;
    }
    else{
        cout<<"错误位: "<<ans<<endl;
    }
    fl=false;
    ans=0;
    for(int i=1;i<=n;i=(i<<1)){
        int cnt=0;
        for(int j=i;j<=n;++j){
            if((j&i)&&a[j]==1){
                ++cnt;
            }
        }
        if(cnt%2!=0){
            fl=true;
            ans+=i;
        }
    }
    cout<<"若配偶: "<<endl;
    if(fl==false){
        cout<<"没有错误位"<<endl;
    }
    else{
        cout<<"错误位: "<<ans<<endl;
    }
}
signed main(){
    cin.tie(nullptr);
    while(1){
        cout<<"1. 整数加减法"<<endl;
        cout<<"2. 传送码转汉明码"<<endl;
        cout<<"3. 汉明码校验器"<<endl;
        int op;
        cin>>op;
        if(op==1)twoInteger();
        else if(op==2)tohm();
        else if(op==3)solvehm();
    }
    


    return 0;
}