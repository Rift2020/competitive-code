#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define double long double		using namespace std;using ll = long long int;int t;
double n,p1,v1,p2,v2,ans;
double a,b,m;
const double eps=1e-14;int main(){	//ios::sync_with_stdio(false);	scanf("%d",&t);
	while(t--){
		scanf("%Lf%Lf%Lf%Lf%Lf",&n,&p1,&v1,&p2,&v2);
		if(p1>p2){
			swap(p1,p2);
			swap(v1,v2);
		}
		a=p1;
		b=n-p2;
		m=p2-p1;
		if(min((n+a)/v1,(n+m+b)/v1)<b/v2){
			ans=min((n+a)/v1,(n+m+b)/v1);
			printf("%.7Lf\n",ans);
			continue;
		}
		if(min((n+b)/v2,(n+a+m)/v2)<a/v1){
			ans=min((n+b)/v2,(n+a+m)/v2);
			printf("%.7Lf\n",ans);
			continue;
		}
		double l=p1,r=p2,mid=(l+r)/2;
		while(1){
			//cout<<l<<" "<<r<<endl;
			double z=mid-p1,y=p2-mid;
			double t1=min((a+z+z)/v1,(a+a+z)/v1);
			double t2=min((b+b+y)/v2,(b+y+y)/v2);
			if(fabs(t1-t2)<eps){
				//cout<<t1<<" "<<t2<<endl;
				ans=max(t1,t2);
				break;
			}
			if(t1<t2){
				l=mid;
			}
			else{
				r=mid;
			}
			mid=(r+l)/2;
			if(fabs(r-l)<eps){
				//cout<<a<<" "<<z<<" "<<y<<" "<<b<<endl;
				//cout<<t1<<" "<<t2<<endl;
				ans=max(t1,t2);
				break;
			}
		}
		printf("%.7Lf\n",ans);
	}				return 0;}