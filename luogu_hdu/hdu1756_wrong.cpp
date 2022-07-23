#include<bits/stdc++.h>
#define eps 1e-1//最大允许偏差,或者也可以叫精度
#define pi 3.1415926
using namespace std;
int sgn(double x){//返回x的符号
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct Point{//点与方向向量都可以表示
    double x,y;
};
istream &operator>>(istream &input,Point &p){
    input>>p.x>>p.y;
    return input;
}
Point operator-(const Point &a,const Point &b){//两点减出向量
    Point re;
    re.x=b.x-a.x;
    re.y=b.y-a.y;
    return re;
}
bool operator==(const Point &a,const Point &b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
double cross(const Point &a,const Point &b){//向量叉积
    return a.x*b.y-a.y*b.x;
}
double dist(const Point &a,const Point &b){
    double dx=b.x-a.x,dy=b.y-a.y;
    return sqrt(dx*dx+dy*dy);
}
struct Polygon{
    vector<Point> p;
};
int n,m;
Polygon pg;
bool point_in_polygon(const Point &p,const Polygon &pg){
    for(const Point &i:pg.p){
        if(i==p)return true;
    }
    Point la=pg.p[0];
    double s=0;
    for(int i=1;i<pg.p.size();++i){
        Point now=pg.p[i];
        s+=asin(cross(now-p,la-p)/(dist(now,p)*dist(la,p)));
        la=now;
    }
    Point now=pg.p[0];
    s+=asin(cross(now-p,la-p)/(dist(now,p)*dist(la,p)));
    if(sgn(s)==0)return false;
    return true;
}
int main(){
    while(cin>>n){
         
        for(int i=0;i<n;++i){
            Point p;
            cin>>p;
            pg.p.push_back(p);
        }
        reverse(pg.p.begin(),pg.p.end());
        cin>>m;
        for(int i=0;i<m;++i){
            Point p;
            cin>>p;
            if(point_in_polygon(p,pg))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        

    }
    
    
    
    return 0;
}