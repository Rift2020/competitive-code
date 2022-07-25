#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define eps 1e-8//最大允许偏差,或者也可以叫精度
#define maxn 35
using namespace std;
using ll = long long;
int t,n,m,k;
int g[maxn][maxn];
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
point operator/(const point &p,const double &k){//向量除以实数，按比例缩小
    return point(p.x/k,p.y/k);
}
bool operator==(const point &a,const point &b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
bool operator<(const point &a,const point &b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
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
    line(const point a,const point &b){
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
bool crs(const line &a,const line &b){
    point x=a.p2-a.p1;
    point y=b.p2-b.p1;

    if(fabs(cross(x,y))<eps)return false;
    point p=line_cross_point(a,b);
    double a1=a.p1.x,a2=a.p2.x;
    double b1=b.p1.x,b2=b.p2.x;
    if(a1>a2)swap(a1,a2);
    if(b1>b2)swap(b1,b2);
    if(p.x>=a1&&p.x<=a2&&p.x>=b1&&p.x<=b2){
        return true;
    }
    return false;
}
map<point,int> mp;
vector<point> v;
vector<line> li;
point st,ed;
typedef pair<int,int> nod;//dis,ind
int dis[maxn];//s到该点的距离
bool visit[maxn];//标记该点是否已经relax过
void dij(){
    //Dijkstra
    priority_queue<nod,vector<nod>,greater<nod> > pq;
    pq.push(nod{0,0});
    while(!pq.empty()){
        int k=pq.top().second;
        pq.pop();
        if(visit[k])continue;
        visit[k]=true;
        for(int i=0;i<n;++i){
            int s=g[k][i];
            if(dis[i]>dis[k]+s){
                dis[i]=dis[k]+s;
                pq.push(nod{dis[i],i});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        mp.clear();
        v.clear();
        li.clear();
        cin>>n>>m>>k;
        cin>>st>>ed;
        st.x+=0.5;
        st.y+=0.5;
        ed.x+=0.5;
        ed.y+=0.5;
        rep(i,1,k){
            point p1,p2;
                cin>>p1>>p2;
                mp[p1]++;
                mp[p2]++;
                if(p1.x==0||p1.x==n||p1.y==0||p1.y==m){
                    mp[p1]++;
                }
                if(p2.x==0||p2.x==n||p2.y==0||p2.y==m){
                    mp[p2]++;
                }
                li.push_back(line(p1,p2));
        }
        v.push_back(st);
        for(auto i:mp)v.push_back(i.first);
        v.push_back(ed);
        n=v.size();
        for(int i=0;i<n;++i){
            
            for(int j=0;j<n;++j){
                g[i][j]=0;
                if(mp[v[j]]>=1)
                    g[i][j]=mp[v[j]]-1;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(line lin:li){
                    if(lin.p1==v[i]||lin.p2==v[i]||lin.p1==v[j]||lin.p2==v[j])continue;
                    if(crs(line(v[i],v[j]),lin)){
                            g[i][j]++;
                            g[j][i]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;++i)dis[i]=INT_MAX;
        memset(visit,0,sizeof(visit));
        dis[0]=0;
        dij();
        cout<<dis[n-1]<<endl;
    }



    return 0;
}