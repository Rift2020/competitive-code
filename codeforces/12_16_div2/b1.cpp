#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long;
int t;
int n;
int a[maxn];
vector<int> v;
bool ok[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        memset(ok,false,sizeof(ok));
        rep(i,1,n)cin>>a[i];
        v.clear();
        rep(i,1,n){
            if(a[i]<=n&&ok[a[i]]==false){
                ok[a[i]]=true;
            }
            else
                v.push_back(a[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        bool fl=true;
        int now=0;
        int ans=0;
        per(i,n,1){
            if(ok[i]==false){
                if(v[now]==i||(v[now]-1)/2>=i){
                    ++now;
                    ++ans;
                }
                else{
                    fl=false;
                    break;
                }
            }
        }
        if(fl==false)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    
    
    
    return 0;
}