#include<bits/stdc++.h>
#define maxk 70
using namespace std;
struct num{
    int a[maxk];
    int p;
};
num operator*(const num &x,const num &y){
    num re;
    re.p=0;
    memset(re.a,0,sizeof(re.a));
    for(int i=0;i<=x.p;++i){
        for(int j=0;j<=y.p;++j){
            if(x.a[i]==0||y.a[j]==0)continue;
            re.a[i+j]=re.a[i+j]^(x.a[i]*y.a[j]);
        }
    }
    for(int i=x.p+y.p;i>=0;++i){
        if(re.a[i]>0){
            re.p=i;
            break;
        }
    }
    return re;
}
num operator++(num &x){
    x.a[0]+=1;
    for(int i=0;i<=x.p;++i){
        if(x.a[i]>1){
            x.a[i]=0;
            x.a[i+1]+=1;
        }
        else{
            break;
        }
    }
    if(x.a[x.p+1])x.p++;
    return x;
}
/*
num operator+(const num& x,const num& y){
    num re;
    re.p=0;
    memset(re.a,0,sizeof(re.a));
    for(int i=max(x.p,y.p);i>=0;--i)re.a[i]=x.a[i]+y.a[i];
    re.p=max(x.p,y.p);
    for(int i=0;i<=re.p;++i){
        if(re.a[i]>1){
            re.a[i]-=2;
            re.a[i+1]+=1;
        }
    }
    if(re.a[re.p+1])re.p++;
    return re;
}
*/
ostream &operator<<(ostream &output,const num&x){ 
    bool fl=false;
    for(int i=x.p;i>=0;--i){
        if(x.a[i]){
            if(fl)output<<"+";
            fl=true;
            if(i>=1){
                output<<"x^"<<i;
            }
            else{
                output<<1;
            }
        }
    }
    return output;            
}
bool operator<(const num &a,const num &b){
    if(a.p!=b.p)
        return a.p<b.p;
    for(int i=a.p;i>=0;i--){
        if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
    }
    return false;
}
set<num> not_prime;
int main(){
    int k=1;
    num i;
    memset(i.a,0,sizeof(i.a));
    i.a[0]=0,i.a[1]=1,i.p=1;
    for(;;++i){
        if(not_prime.find(i)==not_prime.end()){
            if(i.p==k){
                cout<<i<<endl;
                if(k==30)break;
                ++k;
            }
            for(num j=i;;++j){
                num ins=j*i;
                if(ins.p>30)break;
                not_prime.insert(ins);
            }
        }
    }
    return 0;
}