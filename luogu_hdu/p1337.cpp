#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
typedef struct{
    double x,y,w;
}thi;
double t=3000,tend=1e-15,alpha=0.996;
double x,y;
int n;
thi a[maxn];
double f(double x,double y){
    double re=0;
    rep(i,1,n){
        double dx=x-a[i].x,dy=y-a[i].y;
        re+=sqrt(dx*dx+dy*dy)*a[i].w;
    }
    return re;
}
void sa(){
    t=3000;
    double nx,ny,re=f(x,y),nre;
    while(t>tend){
        nx=x+(double)(rand()*2-RAND_MAX)*t;
        ny=y+(double)(rand()*2-RAND_MAX)*t;
        nre=f(nx,ny);
        double d=nre-re;
        if(d<0||exp(-d/t)*RAND_MAX>rand()){
            x=nx,y=ny;
            re=min(re,nre);
        }
        t=t*alpha;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flags(ios::fixed);
    cout.precision(3);
    srand((int)time(NULL));
    cin>>n;
    rep(i,1,n){
        cin>>a[i].x>>a[i].y>>a[i].w;
        x+=a[i].x;
        y+=a[i].y;
    }
    x/=n;
    y/=n;   
    rep(i,1,50)sa();
    cout<<x<<" "<<y<<endl;
    return 0;
}