#include<bits/stdc++.h>
#define maxn 15
using namespace std;
int t;
int n,ans;
bool adm[maxn][maxn];//true是能走，false不能走
struct po{//点
    int x,y;
};
bool operator==(const po &a,const po &b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
struct path{//路径
    vector<po> v;
};
bool operator==(const path &a,const path &b){
    for(int i=0;i<a.v.size()&&i<b.v.size();++i){//只要有一个点重复就相同路径
    //因为重复点只可能在相同下标处，所以只要比较每个下标是不是相等
        if(a.v[i]==b.v[i])return true;
    }
    return false;
}
vector<po> vp;//dfs时的临时路径
vector<path> vpa;//总路径
void dfs(int x,int y){
    if(!((x==1&&y==1)||(x==n&&y==n))){//起点终点不存
        vp.push_back(po{x,y});
    }
    if(x==n&&y==n){//抵达终点
        ++ans;//这行不需要
        vpa.push_back(path{vp});//把路径存到总的
        return;
    }
    if(x<n&&adm[x+1][y]){//能走就走
        dfs(x+1,y);
    }
    if(y<n&&adm[x][y+1]){
        dfs(x,y+1);
    }
    if(!((x==1&&y==1)||(x==n&&y==n))){//回溯
        vp.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                char c;
                cin>>c;
                if(c=='.')adm[i][j]=true;//输入部分
                else adm[i][j]=false;
            }
        }
        vp.clear();
        vpa.clear();
        ans=0;
        if(adm[1][1]==true)//判断起点是不是死的
            dfs(1,1);
        //dfs的时候路径本来就是按照从小到大的顺序存到vpa的
        //所以unique之前不用再sort了
        ans=unique(vpa.begin(),vpa.end())-vpa.begin();//去重，并且把不重复路径数量传给ans
        //if(ans>2)ans=2;
        cout<<ans<<endl;
    }
    
    
    return 0;
}