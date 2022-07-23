#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct Mt{//二阶矩阵
    ll d[2][2];
    Mt(){
        memset(d,0,sizeof(d));//初始化为0
    }
} mt;
const ll p=1000000007;//mod
mt operator*(const mt& a,const mt& b){//矩阵乘法，已经嵌入求模
    mt ret;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                ret.d[i][j]+=((a.d[i][k]%p)*(b.d[k][j])%p)%p;
            }
            ret.d[i][j]%=p;
        }
    return ret;
}
mt ksm(const mt& a,ll n){//标准递归快速幂写法
    if(n==1)return a;
    mt ks=ksm(a,n/2);
    if(n%2==0) return ks*ks;
    else return ks*ks*a;
}
int main(){
    ll n;
    cin>>n;
    mt m;
    m.d[0][0]=0,m.d[0][1]=1,m.d[1][0]=1,m.d[1][1]=1;//P矩阵
    mt an=ksm(m,n);
    cout<<an.d[1][0]%p<<endl;
    
    return 0;
}