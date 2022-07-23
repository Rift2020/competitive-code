#include<bits/stdc++.h>
#define maxn 30
using namespace std;
struct ppt{
    int xmin,xmax,ymin,ymax;
    vector<int> in;
};
bool used[maxn];
int n;
ppt a[maxn];
int cp[maxn];
bool inline check(int i,int x,int y){
    if(a[i].xmin<=x&&a[i].xmax>=x&&a[i].ymin<=y&&a[i].ymax>=y)return true;
    return false;
}
bool dfs(int x){
    if(x==0)memset(used,0,sizeof(used));
    if(x==n)return true;
    for(int i:a[x].in){
        if(used[i]==false){
            used[i]=true;
            cp[x]=i;
            if(dfs(x+1))return true;
            used[i]=false;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].xmin>>a[i].xmax>>a[i].ymin>>a[i].ymax;
    }
    for(int i=1;i<=n;++i){
        int x,y;
        cin>>x>>y;
        for(int j=0;j<n;++j){
            if(check(j,x,y)){
                a[j].in.push_back(i);
            }
        }
    }
    if(dfs(0)){
        for(int i=0;i<n;++i){
            cout<<(char)('A'+i)<<" "<<cp[i]<<endl;
        }
    }
    else{
        cout<<"None"<<endl;
    }
    return 0;
}