#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int t,n;
string s;
char a[maxn];
vector<int> ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        ans.clear();
        int ss=0;
        for(char c:s){
            if(c=='1')++ss;
        }
        for(int i=1;i<=s.size();++i)a[i]=s[i-1];
        for(int i=1;i<=s.size()-ss;++i)if(a[i]=='1')ans.push_back(i);
        for(int i=s.size()-ss+1;i<=s.size();++i)if(a[i]=='0')ans.push_back(i);
        if(ans.empty())
            cout<<"0"<<endl;
        else{
            cout<<1<<endl;
            cout<<ans.size()<<" ";
            for(int i:ans)cout<<i<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    return 0;
}