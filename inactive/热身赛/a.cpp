#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long;
int n;
double y[maxn];
typedef pair<double,int> pr;//value,index,
vector<pr> v;
vector<double> b;
double ans,l;
double dis(double x,double y,double a,double b){
    double dx=x-a,dy=y-b;
    return sqrt(dx*dx+dy*dy);
}
signed main(){
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lf",&y[i]);
    }
    rep(i,0,n){
        l+=dis(i,y[i],i+1,y[i+1]);
    }
    rep(i,1,n){
        double q=dis(i-1,y[i-1],i,y[i])+dis(i,y[i],i+1,y[i+1])-dis(i-1,y[i-1],i+1,y[i+1]);
        v.push_back({q,i});
    }
    sort(v.begin(),v.end());
    rep(i,1,n-1){
        double q=dis(i-1,y[i-1],i,y[i])+dis(i,y[i],i+1,y[i+1])+dis(i+1,y[i+1],i+2,y[i+2]);
        q-=dis(i-1,y[i-1],i+2,y[i+2]);
        b.push_back(q);
    }
    for(int i=v.size()-1;i>=0;--i){
        double now=v[i].first;
        int ind=v[i].second;
        for(int j=i-1;j>=0;--j){
            if(v[j].second!=ind-1&&v[j].second!=ind+1){
                ans=max(ans,now+v[j].first);
                break;
            }
        }
    }
    for(double i:b)ans=max(ans,i);
    printf("%.12lf\n",l-ans);
    return 0;
}