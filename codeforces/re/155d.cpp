#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
#define maxn 200005
using namespace std;
using ll = long long int;
int n,m;
string in,now;
char per[3]={'a','b','c'};
int chg[maxn];
int pSum[maxn][6];
int query(int l,int r){
    int re=1e9;
    for(int i=0;i<6;++i){
        int now=pSum[r][i]-pSum[l-1][i];
        re=min(re,now);
    }
    return re;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    cin>>in;
    in=' '+in;
    int ind=0;
    do{
        now=" ";
        now+=per[0];
        now+=per[1];
        now+=per[2];
        now.resize(n+1);
        for(int i=4;i<=n;++i){
            now[i]=now[i-3];
        }
        for(int i=1;i<=n;++i){
            if(in[i]==now[i])chg[i]=0;
            else chg[i]=1;
        }
        for(int i=1;i<=n;++i){
            pSum[i][ind]=pSum[i-1][ind]+chg[i];
        }
        ++ind;
    }
    while(next_permutation(per,per+3));
    
    int l,r;
    repeat(i,m){
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    
    return 0;
}