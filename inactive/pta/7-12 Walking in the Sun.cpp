#include<bits/stdc++.h>
#define maxn 255
using namespace std;
typedef struct{
    double x,y;
    double r;
}yy;
yy a[maxn];
int z,s,q,n;
double mt[maxn][maxn],ans[maxn][maxn];
int main(){
    double u,v,w;
    cin>>z;
    for(int o=1;o<=z;++o){
        cin>>s;
        for(int i=1;i<=s;++i){
            scanf("%lf%lf%lf",&u,&v,&w);
            a[i]=yy{u,v,w};
        }
        cin>>q;
        n=2*q+s;
        for(int i=1;i<=2*q;++i){
            scanf("%lf%lf",&u,&v);
            a[i+s]=yy{u,v,0};
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                if(i==j)mt[i][j]=0;
                else {
                    double dx=a[i].x-a[j].x,dy=a[i].y-a[j].y;
                    mt[i][j]=max(0.0,sqrt(dx*dx+dy*dy)-a[i].r-a[j].r);
                }
            }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
        printf("Campus #%d:\n",o);
        for(int i=1;i<=q;++i){
            printf("  Path #%d: Shortest sun distance is %.1lf.\n",i,mt[2*i-1+s][2*i+s]);
        }
        if(o!=z)
            printf("\n");
    }
    
    
    return 0;
}