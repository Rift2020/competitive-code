#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 15
using namespace std;
using ll = long long int;
int t,n,k;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>k;
        rep(i,0,n-1)cin>>a[i];
        string ans="";
        if(n==1){
            ans=to_string(k+1);
            k=0;
        }
            
        else{
            ++k;
            rep(i,0,n-2){
                int le=a[i],now=a[i+1];
                int g=now-le;
                string s(g,'9'); 
                if(atoi(s.c_str())>=k){
                    ans=to_string(k)+ans;
                    k=0;
                    break;
                }
                else{
                    k-=atoi(s.c_str());
                    ans=s+ans;
                }
            }
        }
        bool fl=true;
            if(k!=0)ans=to_string(k)+ans;
            for(int i=0;i<ans.size();++i){
                if(ans[i]=='0'&&fl==true){
                    continue;
                }
                fl=false;
                cout<<ans[i];
            }
            cout<<endl;
        
    }
    
    
    
    return 0;
}