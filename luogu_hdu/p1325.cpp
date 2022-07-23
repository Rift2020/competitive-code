#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
#define eps 1e-8//最大允许偏差,或者也可以叫精度

int sgn(double x){//返回x的符号
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct point{//点与方向向量都可以表示
    double x,y;
};
istream &operator>>(istream &input,point &p){
    input>>p.x>>p.y;
    return input;
}
double dist(const point &a,const point &b){
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
int n,d;
struct sec{
    double l,r;
};
bool cmp(const sec &a,const sec &b){
    if(a.r!=b.r)return a.r<b.r;
    return a.l>b.l;
}
sec a[maxn];
bool fl=true;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=0;i<n;++i){
        point in;
        cin>>in;
        if(in.y>d){
            fl=false;
            break;
        }
        double r=sqrt(d*d-in.y*in.y);
        a[i]=sec{in.x-r,in.x+r};
    }
    sort(a,a+n,cmp);
    int ans=0;
    double now=-1e9;
    for(int i=0;i<n;++i){
        if(sgn(now-a[i].l)>=0&&sgn(a[i].r-now)>=0)continue;
        ++ans;
        now=a[i].r;
    }
    cout<<ans<<endl;
    return 0;
}