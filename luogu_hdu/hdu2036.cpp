#include<bits/stdc++.h>
#define eps 1e-8
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
bool point_on_segment(const point &p,const point &p1,const point &p2){
    //p点是否在线段p1p2上
    if(p==p1||p==p2)return true;
    double xmax=max(p1.x,p2.x),xmin=min(p1.x,p2.x),ymin=min(p1.y,p2.y),ymax=max(p1.y,p2.y);
    return (p.x>=xmin&&p.x<=xmax&&p.y<=ymax&&p.y>=ymin&&sgn(cross(p2-p,p2-p1))==0);//在范围内且叉积为0
}
vector<point> polygon;
double polygon_area(const vector<point> &polygon){
    //任意多边形面积计算，原理是鞋带定理，叉积累加
    //多边形给点必须顺或者逆时针
    double re=0;
    int n=polygon.size();
    for(int i=0;i<n;++i){
        re+=cross(polygon[i],polygon[(i+1)%n]);
    }
    //如果多边形逆时针给点，re为正，如果多边形顺时针给点，re为负
    return fabs(re/2);
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        polygon.clear();
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            point in;
            in.x=x,in.y=y;
            polygon.push_back(in);
        }
        
        printf("%.1f\n",polygon_area(polygon));
    }
    
    
    return 0;
}