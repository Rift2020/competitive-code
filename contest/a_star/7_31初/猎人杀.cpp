#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int t,n,lr,nn;
int a[maxn][maxn];
bool dead[maxn];
bool inline check(int k){
    if(k==lr){
        cout<<"lieren"<<endl;
        return false;
    }
    else if(nn==2){
        cout<<"langren"<<endl;
        return false;
    }
    return true;
}
int inline run(int k){
    for(int i=1;i<=n;++i){
        if(a[k][i]==k||dead[a[k][i]])continue;
        return a[k][i];
    }
}
int main(){
    ios::sync_with_stdio(false);   
    cin>>t;
    while(t--){
        memset(dead,0,sizeof(dead));
        cin>>n;
        for(int i=1;i<=n;++i){
            int in;
            cin>>in;
            if(in==1)lr=i;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int in;
                cin>>in;
                a[i][j]=in;
            }
        }
        nn=n;
        int k=a[lr][1];
        do{
            --nn;
            dead[k]=true;
            if(check(k)==false)break;
            k=run(k);
        }while(1);
    }
    
    return 0;
}