#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
struct point{
    double x,y;
};
point a[maxn];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x>>a[i].y;
    }
    double ans=1e15;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            double dx=a[i].x-a[j].x;
            double dy=a[i].y-a[j].y;
            ans=min(ans,sqrt(dx*dx+dy*dy));
        }
    }
    printf("%.4lf\n",ans);
    return 0;
}