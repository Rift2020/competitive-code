#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
bool dp[20][100][100];
string n;
int a,b;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>a>>b;
    dp[0][0][0]=true;
    int d=n.size();
    for(int i=0;i<n.size();++i){
        int now=n[i]-'0';
        int na=9-now;
        int nb=now+1;
        bool fl=false;
        for(int j=0;j<=a;++j){
            for(int k=0;k<=b;++k){
                if(dp[i][j][k]){
                    if(j+na<=a){
                        fl=true;dp[i+1][j+na][k]=true;
                    }
                        
                    if(k+nb<=b){
                        fl=true;dp[i+1][j][k+nb]=true;
                    }
                        
                    
                }
            }
        }
        if(fl==false){
            d=i;
            break;
        }
    }
    if(d==n.size()){
        cout<<string(n.size(),'9')<<endl;
    }
    else{
        int ma=a;
        for(int i=0;i<=a;++i){
            for(int j=0;j<=b;++j){
                if(dp[d][i][j]){
                    ma=min(ma,i);
                }
            }
        }
        for(int i=0;i<d;++i){
            n[i]='9';
        }
        n[d]=n[d]+(a-ma);
        cout<<n<<endl;
    }
    
    
    
    return 0;
}