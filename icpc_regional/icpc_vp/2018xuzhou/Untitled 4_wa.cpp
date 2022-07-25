#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define eps 1e-8//最大允许偏差,或者也可以叫精度
#define maxm 1005using namespace std;using ll = long long int;
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
//typedef pair<int,int> pr;
typedef struct{
	int l,r,i;
}pr;
bool operator<(pr a,pr b){
	return a.l<b.l;
}
int len(pr p){
	return p.r-p.l;
}
vector<point> poly;
vector<point> v;
pr sec[maxm];

int t,n,m;

pr calSec(point p){
	int l=-1,r=-1;
	bool is[maxm]={0};
	for(int i=0;i<poly.size();++i){
		int nn=poly.size();
		point vec=poly[(i+1)%nn]-poly[i];
		point now=p-poly[i];
		if(sgn(cross(vec,now))<0){
			is[i]=true;
		}
	}
	//rep(i,0,m-1)cout<<is[i]<<" ";
	//cout<<endl;
	if(is[0]==true&&is[m-1]==true){
		rep(i,0,m-1){
			if(is[i]==false)
				r=i-1;
		}
		per(i,m-1,0){
			if(is[i]==false)
				l=i+1;
		}
	}
	else{
		rep(i,0,m-1){
			if(l==-1&&is[i]==true)
				l=i;
			if(l!=-1&&is[i]==false)
				r=i-1;
		}
		if(r==-1)r=m-1;
	}
	return pr{l,r,-1};
}
void pre(){
	for(int i=0;i<v.size();++i){
		pr r=calSec(v[i]);
		r.i=i;
		sec[i]=r;
		if(sec[i].l>sec[i].r)sec[i].r+=m;
	}
}int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n>>m;
		poly.clear();
		v.clear();
		rep(i,1,n){
			point in;
			cin>>in;
			poly.push_back(in);
		}
		rep(i,1,m){
			point in;
			cin>>in;
			v.push_back(in);
		}
		int s,t,nows,nowt;
		pre();
		/*
		rep(i,0,m-1){
			cout<<':'<<sec[i].l<<" "<<sec[i].r<<endl;
		}
		*/
		sort(sec,sec+m);
		vector<pr> nv,minv;
		minv.resize(10005);
		for(s=0;s<=n-1;++s){
			t=s+n;
			nows=nowt=s;
			int index=-1;
			bool ok=true;
			//xcout<<s<<" "<<t<<endl;
			
			for(int i=0;i<m;++i){
				if(sec[i].l<=nows){
					if(nowt<sec[i].r){
						index=i;
						nowt=sec[i].r;
					}
				}
				else{
					if(nows==nowt){
						ok=false;
						break;
					}
					nows=nowt;
					nv.push_back(sec[index]);
					--i;
				}
			}
			if(ok==true){
				if(minv.size()>nv.size())
					minv=nv;
			}
		}
		if(minv.size()==10005){
			cout<<-1<<endl;
		}
		else{
			cout<<minv.size()<<endl;
			for(auto i:minv){
				cout<<i.i<<" ";
			}
			cout<<endl;
		}
	}					return 0;}