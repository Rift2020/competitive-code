#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int t,n;
char s[maxn];
int a[maxn],b[maxn];
int fabs(int x){
    if(x>0)return x;
    else return -x;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>s[i];
            if(s[i]=='U')a[i]=a[i-1]+1;
            else if(s[i]=='D')a[i]=a[i-1]-1;
            else if(s[i]=='L')b[i]=b[i-1]+1;
            else if(s[i]=='R')b[i]=b[i-1]-1;
        }
        ll ans=0;
        for(int l=1;l<=n;++l){
            for(int r=l+1;r<=n;){
                if(a[r]-a[l-1]==0&&b[r]-b[l-1]==0){
                    ++ans;
                    r+=2;
                }
                else{
                    r+=max(fabs(a[r]-a[l-1]),fabs(b[r]-b[l-1]));
                }
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}