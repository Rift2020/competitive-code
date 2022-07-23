#include<bits/stdc++.h>
#define maxn 25
using namespace std;
int n,r;
string te;
char num[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int ans[maxn];
int solve(){
    memset(ans,0,sizeof(ans));
    int pre[maxn]={0};
    int c=n;
    if(c==0)return 0;
    int ar=-r;
    int re=0;
    if(c>0){
        for(int i=0;c>0;++i,++re){
            pre[i]=c%ar;
            c/=ar;
        }
        --re;
        for(int i=0;i<=re;++i){
            if(i%2==0){
                ans[i]+=pre[i];
            }
            else{
                ans[i+1]+=1;
                ans[i]+=ar-pre[i];
            }
         
        }
        re=0;
        for(int i=0;i<maxn;++i){
            if(ans[i])re=i;
            while(ans[i]>=ar){
                ans[i+1]++;
                ans[i]-=ar;
            }
        }
        //for(int i=0;i<=re;++i)ans[i]=pre[i];
        return re;
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    while(1){
        cin>>te;
        if(te=="#")break;
        n=atoi(te.c_str());
        cin>>r;
        int t=solve();
        for(int i=t;i>=0;--i){
            cout<<num[ans[i]];
        }
        cout<<endl;
    }
    
    return 0;
}