#include<bits/stdc++.h>
#define maxn 105
using namespace std;
bool know[maxn][maxn];
int sc[maxn],scnt;
int n;
void knw(){
    for(int i=1;i<=n;++i){
        if(sc[i])continue;
        scnt++;
        sc[i]=scnt;
        for(int j=1;j<=n;++j){
            if(j==i)continue;
            if(know[i][j]==true&&know[j][i]==true){
                sc[j]=scnt;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        int in;
        while(1){
            cin>>in;
            if(in==0)break;
            know[i][in]=true;
        }
    }
    knw();
    if(scnt>2){
        cout<<"No solution"<<endl;
    }
    else{
        vector<int> v1,v2;
        if(scnt==2){ 
            for(int i=1;i<=n;++i){
                if(sc[i]==1)v1.push_back(i);
                else if(sc[i]==2)v2.push_back(i);
            }
            if(v1.size()>v2.size())swap(v1,v2);
        }
        else if(scnt==1){
            for(int i=1;i<=n/2;++i)v1.push_back(i);
            for(int i=n/2+1;i<=n;++i)v2.push_back(i);
        }
        cout<<v1.size();
        for(int i:v1)cout<<" "<<i;
        cout<<endl<<v2.size();
        for(int i:v2)cout<<" "<<i;
        cout<<endl;
    }
    
    
    return 0;
}