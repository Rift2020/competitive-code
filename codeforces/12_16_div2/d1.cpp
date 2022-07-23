#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 20005
using namespace std;
using ll = long long;
int t;
int n;
int a[maxn];
bool is[maxn];
vector<int> ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        memset(is,false,sizeof(is));
        cin>>n;
        int i;
        for(i=1;i<=n-2;++i){
            cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<endl;
            int in;
            cin>>in;
            a[i]=in;
            if(i>1&&a[i]^a[i-1]==1){
                break;
            }
        }
        int q=i-1,h=i+2;
        if(a[i]==1)swap(q,h);
        ans.clear();
        ans.push_back(h);
        rep(i,1,n){
            if(i==q||i==h)continue;
            int in;
            cout<<"? "<<q<<" "<<h<<" "<<i<<endl;
            cin>>in;
            if(in==0)ans.push_back(i);
        }
        cout<<"! "<<ans.size();
        for(int i:ans)cout<<" "<<i;
        cout<<endl;
        cout.flush();
    }
    
    
    return 0;
}