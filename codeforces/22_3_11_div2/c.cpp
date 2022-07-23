#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int t,n,m;
int a[maxn][maxn];
typedef pair<int,int> pr;
typedef struct{
    pr a,b;
}st;
vector<st> ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans.clear();
        rep(i,1,n){
            rep(j,1,m){
                char c;
                cin>>c;
                a[i][j]=c-'0';
            }
        }
        if(a[1][1]==1){
            cout<<-1<<endl;
            continue;
        }
        per(i,n,2){
            per(j,m,1){
                if(a[i][j]){
                    ans.push_back({{i-1,j},{i,j}});
                }
            }
        }
        per(i,m,1){
            if(a[1][i]){
                ans.push_back({{1,i-1},{1,i}});
            }
        }
        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<i.a.first<<" "<<i.a.second<<" "<<i.b.first<<" "<<i.b.second<<endl;
        }
    }
    
    
    
    return 0;
}