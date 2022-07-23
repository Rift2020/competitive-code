#include<bits/stdc++.h>
#define intt long long
using namespace std;
int t[105];
bool f[105];
int l[105],r[105],rt[105];
int n;
queue<int>q,empty,sp;
int main(){
    cin>>n;
    memset(l,0,sizeof(t));
    memset(r,0,sizeof(t));
    memset(t,0,sizeof(t));
    int tt,ll,rr;
    for(int i=1;i<=n;++i){
        cin>>t[i]>>ll>>rr;
        l[i]=ll;r[i]=rr;
        rt[ll]=i;rt[rr]=i;
    }
    intt s=INT_MAX;
    for(int i=1;i<=n;++i){
        q=empty;
        sp=empty;
        memset(f,0,sizeof(f));
        f[i]=true;
        intt ss=0;
        q.push(i);
        sp.push(0);
        while(!q.empty()){
            int now=q.front();
            int p=sp.front()+1;
            q.pop();
            sp.pop();
            int d[]={rt[now],l[now],r[now]};
            for(int j:d){
                if(j==0||f[j])continue;
                ss+=p*t[j];
                f[j]=true;
                q.push(j);
                sp.push(p);
            }
        }
        if(ss<s)s=ss;
    }
    cout<<s<<endl;
    return 0;
}