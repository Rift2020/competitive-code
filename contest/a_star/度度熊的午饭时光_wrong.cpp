#include<bits/stdc++.h>
#define maxn 105
#define maxb 1005
using namespace std;
int b,n;
int f[maxn][maxb];
bool tak[maxn][maxb];
int value[maxn],cost[maxn];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int o=1;o<=t;++o){
        cin>>b>>n;
        for(int i=1;i<=n;++i){
            cin>>value[i]>>cost[i];
        }
        memset(f,0,sizeof(f));
        memset(tak,false,sizeof(tak));
        for(int i=1;i<=n;++i){
            for(int j=b;j>=cost[i];--j){
                if(f[i-1][j+cost[i]]+value[i]>f[i-1][j]){
                    f[i][j+cost[i]]=f[i-1][j+cost[i]]+value[i];
                    tak[i][j]=true;
                }
                else{
                    f[i][j+cost[i]]=f[i-1][j];
                    tak[i][j]=false;
                }
            }
        }
        int c=0;
        for(int i=1;i<=n;++i){
            if(tak[i][b])c+=cost[i];
        }
        cout<<"Case #"<<o<<':'<<endl;
        cout<<f[n][b]<<" "<<c<<endl;
        for(int i=1;i<=n;++i){
            if(tak[i][b])cout<<i<<" ";
        }
    }
    
    
    return 0;
}