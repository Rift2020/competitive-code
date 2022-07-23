#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 155
using namespace std;
using ll = long long int;
typedef pair<int,int> pr;
pr sec[maxn];
bool a[maxn][maxn];
int n;
double dist(pr a,pr b){
    double dx=a.first-b.first,dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        sec[i]=pr{x,y};
    }
    rep(i,1,n){
        rep(j,1,n){
            char c;
            cin>>c;
            if(c=='1')a[i][j]=true;
        }
    }
    
    
    return 0;
}