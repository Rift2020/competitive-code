#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 705
using namespace std;
using ll = long long;
string in;
int n;
int leb[maxn];
int ler[maxn];
int rib[maxn];
int rir[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>in;
    in=in+in;
    if(in[0]=='w')leb[0]=ler[0]=1;
    else if(in[0]=='b')leb[0]=1;
    else ler[0]=1;
    if(in[2*n-1]=='w')rib[2*n-1]=rir[2*n-1]=1;
    else if(in[2*n-1]=='b')rib[2*n-1]=1;
    else rib[2*n-1]=1;
    for(int i=1;i<=2*n-1;++i){
        if(in[i]=='w'){
            leb[i]=leb[i-1]+1;
            ler[i]=ler[i-1]+1;
        }
        else if(in[i]=='b'){
            if(in[i-1]!='r')leb[i]=leb[i-1]+1;
            else leb[i]=1;
            ler[i]=0;
        }
        else{
            if(in[i-1]!='b')ler[i]=ler[i-1]+1;
            else ler[i]=1;
            leb[i]=0;
        }
    }
    for(int i=2*n-2;i>=0;--i){
        if(in[i]=='w'){
            rib[i]=rib[i+1]+1;
            rir[i]=rir[i+1]+1;
        }
        else if(in[i]=='b'){
            if(in[i+1]!='r')rib[i]=rib[i+1]+1;
            else rib[i]=1;
            rir[i]=0;
        }
        else{
            if(in[i+1]!='b')rir[i]=rir[i+1]+1;
            else rir[i]=1;
            rib[i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<=n*2-2;++i){  
        //cout<<leb[i]<<" "<<ler[i]<<" "<<rib[i]<<" "<<rir[i]<<endl; 
        ans=max(ans,max(leb[i],ler[i])+max(rib[i+1],rir[i+1]));
    }
    cout<<min(ans,n)<<endl;
    return 0;
}