#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define N 100005
using namespace std;
using ll = long long;
int t,n;
typedef pair<int,int> pr;//value,index
pr a[N];
pr b[N];
pr s[N];
bool ok[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        memset(ok,false,sizeof(ok));
        cin>>n;
        int in;
        rep(i,1,n){
            cin>>in;
            a[i]={in,i};
        }
        rep(i,1,n){
            cin>>in;
            b[i]={in,i};
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        rep(i,1,n){
            int index=a[i].second;
            s[index].first=i;
            int index2=b[i].second;
            s[index2].second=i;
        }
        int laa=n+1,lab=n+1,noa=n,nob=n;
        int fl=1;
        while(fl){
            if(fl==1){
                fl=0;
                for(int i=noa;i<laa;++i){
                    int index=a[i].second;
                    ok[index]=true;
                    if(s[index].second<nob){
                        nob=s[index].second;
                        fl=-1;
                    }
                }
                laa=noa;
            }
            else{
                fl=0;
                for(int i=nob;i<lab;++i){
                    int index=b[i].second;
                    ok[index]=true;
                    if(s[index].first<noa){
                        noa=s[index].first;
                        fl=1;
                    }
                }
                lab=nob;
            }
        }
        rep(i,1,n){
            if(ok[i])cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    
    
    
    return 0;
}