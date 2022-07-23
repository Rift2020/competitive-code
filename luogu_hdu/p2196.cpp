#include<bits/stdc++.h>
#define maxn 25
using namespace std;
int n,l[maxn],mem[maxn],mx=0;
int nex[maxn],ap[maxn],fr;
bool book[maxn];
vector<int> v[maxn];
int dfs(int x,int step){
    if(mem[x]){
        //nex[x]=ap[x];
        return mem[x];
    }
    for(auto i:v[x])
        if(book[i]==false){
            book[i]=true;
            int dff=dfs(i,step+1)+l[i];
            book[i]=false;
            if(dff>mem[x]){
                nex[x]=i;
                mem[x]=dff;
            }
            //mem[x]=max(mem[x],dfs(i,s)+l[i]);
        }
    if(mem[x]+l[x]>mx){
        mx=mem[x]+l[x];
        for(int i=0;i<maxn;++i)ap[i]=nex[i];
        fr=x;
    }
    return mem[x];
}
int main(){
    memset(mem,0,sizeof(mem));
    cin>>n;
    int is;
    for(int i=1;i<=n;++i)cin>>l[i];
    for(int i=1;i<=n-1;++i){
        for(int j=i+1;j<=n;++j){
            cin>>is;
            if(is){
                v[i].push_back(j);
                //v[j].push_back(i);
            }
        }
    }memset(nex,-1,sizeof(nex));
    for(int i=1;i<=n;++i){
        memset(book,0,sizeof(book));
        //string str="";
        
        book[i]=true;
        dfs(i,0);
    }
    for(int i=fr;i!=-1;i=ap[i]){
        if(i==fr)
            cout<<i;
        else
            cout<<" "<<i;
    }
    cout<<endl;
    cout<<mx<<endl;
    return 0;
}