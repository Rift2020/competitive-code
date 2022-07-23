#include<bits/stdc++.h>
#define int long long
#define EX 1000000007
using namespace std;
const int N = 100010;
const int M = 100010;
int visl[N];
int visr[M];
int a[N];
int b[M];
struct node{
    int flag;
    int x;
    int T;
};
int ans;
vector<node> q;
signed main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int io,op,ip;
        cin>>io>>op>>ip;
        if(io==1)
        {
            visl[op]=ip;
        }
        else{
            visr[op]=ip;
        }
        node NOW;
        NOW.flag=io;
        NOW.x=op;
        NOW.T=ip;
        q.push_back(NOW);
    }
    int suml=0,sumr=0;
    for(int i=1;i<=n;i++)
    {
        if(visl[i]==0)
        {
            suml=(suml+a[i])%EX;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(visr[i]==0)
        {
            sumr=(sumr+b[i])%EX;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(q[i].flag==1)
        {
            if(q[i].T!=visl[q[i].x])
            {
                continue;
            }
            else{
                ans=(ans+(((__int128)a[q[i].x]*(__int128)sumr)%EX*(__int128)q[i].T)%EX)%EX;
                suml=(suml+a[q[i].x])%EX;
            }
        }
        else
        {
            if(q[i].T!=visr[q[i].x])
            {
                continue;
            }
            else{
                ans=(ans+(((__int128)b[q[i].x]*(__int128)suml)%EX*(__int128)q[i].T)%EX)%EX;
                sumr=(sumr+b[q[i].x])%EX;
            }
        }
    }
    cout<<ans;
    return 0;
}