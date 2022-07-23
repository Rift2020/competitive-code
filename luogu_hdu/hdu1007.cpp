#include<bits/stdc++.h>
#define maxn 100005
#define INF 1e20
using namespace std;
struct point{
    double x,y;
};
bool xmp(const point &a,const point &b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
bool ymp(const point &a,const point &b){
    if(a.y!=b.y)return a.y<b.y;
    return a.x<b.x;
}
point p[maxn];
vector<point> mg;//合并时，可能产生新最小值的点的集合
int n;
double dist(const point &a,const point &b){
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
double divquer(int le,int ri){//divide and conquer的混写2333
    if(le==ri)return INF;
    if(le==ri-1)return dist(p[le],p[ri]);
    double dis=INF;
    int mid=(le+ri)/2;
    double d1=divquer(le,mid);
    double d2=divquer(mid+1,ri);
    dis=min(d1,d2);
    mg.clear();
    for(int i=le;i<=ri;++i){
        if(fabs(p[i].x-p[mid].x)<=dis){
            mg.push_back(p[i]);
        }
    }
    sort(mg.begin(),mg.end(),ymp);
    for(int i=0;i<mg.size();++i){
        for(int j=i+1;j<mg.size();++j){
            if(mg[j].y-mg[i].y>dis)break;//剪枝
            dis=min(dis,dist(mg[i],mg[j]));
        }
    }
    return dis;
}
int main(){
    while(1){
        scanf("%d",&n);//换成cin会tle(这波是两位小数输出不方便用cout)
        if(n==0)break;
        for(int i=0;i<n;++i){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,xmp);
        double ans=divquer(0,n-1);
        printf("%.2f\n",ans/2);
    }
    
    
    return 0;
}