#include<bits/stdc++.h>
#define N 8
using namespace std;
int n=7;
typedef pair<int,int> edge;
vector<edge> e={{1,2},{1,3},{1,4},{1,7},{2,3},{2,4},{2,5},
{2,7},{3,4},{3,6},{3,7},{4,5},{4,6},{5,6},{5,7},{6,7}};
int color[N];
bool check(){
    for(edge i:e){
        if(color[i.first]==color[i.second])return false;
    }
    return true;
}
void print(){
    for(int i=1;i<=7;++i){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
void solve(int x,int ans){
    if(x==N){
        if(check()){
            cout<<ans<<" colors has a solution:"<<endl;
            print();
            exit(0);
        }
        return;
    }
    for(int i=1;i<=ans;++i){
        color[x]=i;
        solve(x+1,ans);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    for(int ans=1;;++ans){
        solve(1,ans);
        cout<<ans<<" colors has no solution"<<endl;
    }
    
    
    return 0;
}