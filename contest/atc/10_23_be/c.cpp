#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 305
using namespace std;
using ll = long long int;
int n;
typedef pair<int,int> pr;
pr a[maxn];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)
        cin>>a[i].first>>a[i].second;
    rep(i,1,n){
        rep(j,i+1,n){
            rep(k,j+1,n){
                int x1=a[j].first-a[i].first,x2=a[k].first-a[i].first;
                int y1=a[j].second-a[i].second,y2=a[k].second-a[i].second;
                if(x1*y2-x2*y1!=0)++ans;
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}