#include<bits/stdc++.h>
#define maxn 705
#define eps 1e-8
using namespace std;
struct Point{//点与方向向量都可以表示
    double x,y;
};
istream &operator>>(istream &input,Point &p){
    input>>p.x>>p.y;
    return input;
}
Point operator-(const Point &a,const Point &b){
    Point re;
    re.x=b.x-a.x;
    re.y=b.y-a.y;
    return re;
}
struct Line{//p1,p2是直线上的两个点,v是方向向量，因此p1+v*t可以表示任何点
    Point p1,p2;
    Point v;
    Line(){};
    Line(const Point &a,const Point &b){
        //两点构造
        p1=a,p2=b;
        v=b-a;
    }
};
double cross(const Point &a,const Point &b){
    return a.x*b.y-a.y*b.x;
}
int sgn(double x){//返回x的符号
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
int point_line_relation(Line l,Point p){
    return sgn(cross(p-l.p1,l.v));//-1:点在线上侧,1:点在线下侧,0:点在线上
}
Point p[maxn];
int n;
int main(){
    Line l2;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)cin>>p[i];
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int s=2;
            for(int k=0;k<n;++k){
                if(k==i||k==j)continue;
                Line l(p[i],p[j]);
                if(point_line_relation(l,p[k])==0)++s;
            }
            ans=max(ans,s);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}