#include<bits/stdc++.h>
#define eps 1e-8//最大允许偏差,或者也可以叫精度
using namespace std;
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
point operator-(const point &a,const point &b){//两点减出向量
    point re;
    re.x=b.x-a.x;
    re.y=b.y-a.y;
    return re;
}
bool operator==(const point &a,const point &b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
double cross(const point &a,const point &b){//向量叉积
    return a.x*b.y-a.y*b.x;
}
struct segment{
    point p1,p2;
};
bool point_on_segment(const point &p,const point &p1,const point &p2){
    //p点是否在线段p1p2上
    if(p==p1||p==p2)return true;
    double xmax=max(p1.x,p2.x),xmin=min(p1.x,p2.x),ymin=min(p1.y,p2.y),ymax=max(p1.y,p2.y);
    return (p.x>xmin&&p.x<xmax&&p.y<ymax&&p.y>ymin&&sgn(cross(p2-p,p2-p1))==0);//在范围内且叉积为0
}
vector<point> polygon;
int point_in_polygon(const point &p,const vector<point> &poly){
    //点是否在多边形（凹凸多边形都行）内
    //0在外部，1在内部，2在边上
    int n=poly.size();
    int wn=0;
    for(int i=0;i<n;++i){
        if(point_on_segment(p,poly[(i+1)%n],poly[i]))return 2;
    }
    for(int i=0;i<n;++i){
        int cro=sgn(cross(poly[(i+1)%n]-poly[i],poly[i]-p));
        int d1=sgn(poly[(i+1)%n].y-p.y);
        int d2=sgn(poly[i].y-p.y);
        if(cro>0&&d1>0&&d2<=0)wn++;
        else if(cro<0&&d2>0&&d1<=0)wn--;
    }
    return wn==0?0:1;
}
int n,m;
int main(){
    while(cin>>n){
        polygon.clear();
        polygon.resize(n);
        for(int i=n-1;i>=0;--i){
            point in;
            cin>>in;
            polygon[i]=in;
        }
        
        cin>>m;
        for(int i=0;i<m;++i){
            point in;
            cin>>in;
            if(point_in_polygon(in,polygon)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    
    
    return 0;
}