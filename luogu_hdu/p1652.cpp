#include<bits/stdc++.h>
#define maxn 55
using namespace std;
struct circle{
    int x,y;
    int r;
};
circle a[maxn];
bool incircle(int x,int y,circle c){
    double dx=x-c.x,dy=y-c.y;
    double d=sqrt(dx*dx+dy*dy);
    if(d<c.r)return true;
    return false;
}
int main(){
    int n,x1,y1,x2,y2;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].x;
    for(int i=0;i<n;++i)cin>>a[i].y;
    for(int i=0;i<n;++i)cin>>a[i].r;
    int ans=0;
    cin>>x1>>y1>>x2>>y2;
    for(int i=0;i<n;++i){
        if(incircle(x1,y1,a[i])^incircle(x2,y2,a[i]))++ans;
    }
    cout<<ans<<endl;
    
    return 0;
}