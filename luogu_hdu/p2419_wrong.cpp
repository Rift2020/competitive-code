#include<bits/stdc++.h>
#define maxn 105
#define maxm 4505
using namespace std;
int n,m;
unordered_set<int> rd[maxn],cd[maxn];
queue<int> qq,q,hq;
bool is[maxn];
int main(){
    int a,b,ans=0;
    cin>>n>>m;
    memset(is,0,sizeof(is));
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        cd[a].insert(b);
        rd[b].insert(a);
    }
    for(int i=1;i<=n;++i){
        if(rd[i].empty()&&cd[i].empty()){
            cout<<"0"<<endl;
            return 0;
        }
        if(rd[i].empty())qq.push(i);
        else if(cd[i].empty())hq.push(i);
    }
    while(qq.size()==1){
        ++ans;
        int fr=qq.front();
        qq.pop();
        for(int i:cd[fr]){
            rd[i].erase(fr);
            if(rd[i].empty()&&is[i]==0){
                qq.push(i);
                is[i]=1;
            }
        }
    }
    if(ans==n){
        cout<<ans<<endl;
        return 0;
    }
    while(hq.size()==1){
        ++ans;
        int fr=hq.front();
        hq.pop();
        for(int i:rd[fr]){
            cd[i].erase(fr);
            if(cd[i].empty()&&is[i]==0){
                hq.push(i);
                is[i]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}