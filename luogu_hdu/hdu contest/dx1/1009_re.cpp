/**
 *    author:  Rift
 *    created: 2022.07.23  15:03
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 500005
#define eps 1e-8//最大允许偏差,或者也可以叫精度
using namespace std;
using ll = long long;
int sgn(double x){//返回x的符号
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct point{//点与方向向量都可以表示
    double x,y;
    point(){};
    point(const double &a,const double &b){
        x=a,y=b;
    }
};
istream &operator>>(istream &input,point &p){
    input>>p.x>>p.y;
    return input;
}
ostream &operator<<(ostream &output,const point &p){
    output<<p.x<<" "<<p.y<<endl;
    return output;
}
point operator-(const point &a,const point &b){//两点减出向量
    point re;
    re.x=b.x-a.x;
    re.y=b.y-a.y;
    return re;
}
point operator+(const point &a,const point &b){
    point re;
    re.x=a.x+b.x;
    re.y=a.y+b.y;
    return re;
}
point operator/(const point &p,const double &k){//向量除以实数，按比例缩小
    return point(p.x/k,p.y/k);
}
bool operator==(const point &a,const point &b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
double cross(const point &a,const point &b){//向量叉积
    return a.x*b.y-a.y*b.x;
}
double dist(const point &a,const point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool point_on_segment(const point &p,const point &p1,const point &p2){
    //p点是否在线段p1p2上
    if(p==p1||p==p2)return true;
    double xmax=max(p1.x,p2.x),xmin=min(p1.x,p2.x),ymin=min(p1.y,p2.y),ymax=max(p1.y,p2.y);
    return (p.x>=xmin&&p.x<=xmax&&p.y<=ymax&&p.y>=ymin&&sgn(cross(p2-p,p2-p1))==0);//在范围内且叉积为0
}
struct line{//p1,p2是直线上的两个点,v是方向向量，因此p1+v*t可以表示任何点
    point p1,p2;
    point v;
    line(){};
    line(const point &a,const point &b){
        //两点构造
        p1=a,p2=b;
        v=b-a;
    }
};
int point_line_relation(line l,point p){//点与直线位置关系
    return sgn(cross(p-l.p1,l.v));//-1:点在线上侧,1:点在线下侧,0:点在线上
}
double point_line_dist(const point &p,const line l){//点到直线距离
    return fabs(cross(p-l.p1,l.p2-l.p1)/dist(l.p1,l.p2));
}
point line_cross_point(const line &a,const line &b){//两直线交点
    //使用前要保证两直线不重合不平行
    double s1=cross(a.p2-a.p1,b.p1-a.p1);
    double s2=cross(a.p2-a.p1,b.p2-a.p1);
    return point(b.p1.x*s2-b.p2.x*s1,b.p1.y*s2-b.p2.y*s1)/(s2-s1);
}
int t,n;
point a[maxn];
vector<point> v;
point d[]={{0,1},{1,0},{1,1},{-1,1}};
void check(){
    for(point p:v){
        bool ans=true;
        rep(i,1,n){
            bool ok=false;
            rep(j,0,3){
                if(point_line_relation(line(p,p+d[j]),a[i])==0){
                    ok=true;
                    break;
                }
            }
            if(ok==false){
                ans=false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n){
            int x,y;
            //cin>>a[i];
            cin>>x>>y;
            a[i].x=x,a[i].y=y;
        }
        bool fl=true;
        point p=a[1],q;
        rep(i,1,n){
            bool ok=false;
            rep(j,0,3){
                if(point_line_relation(line(p,p+d[j]),a[i])==0){
                    ok=true;
                    break;
                }
            }
            if(ok==false){
                fl=false;
                q=a[i];
                break;
            }
        }
        v.clear();
        if(fl){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(j==i)continue;
                v.push_back(line_cross_point(line(p,p+d[i]),line(q,q+d[j])));
            }
        }
        check();
    }



}
