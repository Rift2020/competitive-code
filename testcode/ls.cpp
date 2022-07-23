#include<bits/stdc++.h>
using namespace std;
vector<int> g[5]={{},{2,3},{1},{2,4},{4}};
int nn,now,s,s2;
vector<int> ans;
void dfs(int x,int n){
    ans.push_back(x);
    if(n==nn){
        ++s;
        for(int i:ans)cout<<i<<" ";
        if(x==now){
            cout<<"loop ";
        }
        if(now==3&&x==4){
            cout<<"q2";
            ++s2;
        }
        cout<<endl;
        ans.pop_back();
        return;
    }
    for(int v:g[x]){
        dfs(v,n+1);
    }
    ans.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    for(nn=1;nn<=4;++nn){
        cout<<"case:"<<nn<<endl;
        s=0;
        for(now=1;now<=4;++now){
            dfs(now,0);
        }
        cout<<"sum:"<<s<<endl;
        cout<<"q2Sum:"<<s2<<endl;
    }
    
    
    
    return 0;
}