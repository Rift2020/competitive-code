#include<bits/stdc++.h>
#define maxp 505
#define maxb 250005
using namespace std;
typedef struct{
    double l;
    int a,b;
}nd;
bool operator<(nd a,nd b){
    return a.l<b.l;
}
int s,p;
int d[maxp][2];
vector<nd> ar;
int fa[maxp];
int sf(int x){
    if(fa[x]==x)return x;
    else return fa[x]=sf(fa[x]);
}
void mf(int x,int y){
    int fx=sf(x),fy=sf(y);
    fa[fx]=fy;
}
int main(){
    double ans=0;
    cin>>s>>p;
    for(int i=0;i<p;++i)fa[i]=i;
    for(int i=0;i<p;++i)
        cin>>d[i][0]>>d[i][1];
    for(int i=0;i<p;++i)
        for(int j=0;j<p;++j){
            if(i==j)continue;
            double dx=d[i][0]-d[j][0],dy=d[i][1]-d[j][1];
            ar.push_back(nd{sqrt(dx*dx+dy*dy),i,j});
        }
    sort(ar.begin(),ar.end());
    int k=0;
    for(int i=0;i<ar.size();++i){
        if(sf(ar[i].a)!=sf(ar[i].b)){
            mf(ar[i].a,ar[i].b);
            ans=max(ans,ar[i].l);
            ++k;
        }
        if(k==p-s){
            printf("%.2lf\n",ans);
            return 0;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}