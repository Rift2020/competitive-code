#include<bits/stdc++.h>
#define maxn 400005
using namespace std;
int n,m,k;
vector<int> v[maxn];
bool ban[maxn];
stack<int> bann;
stack<int> ans;
int fa[maxn];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int inline read(){
    int s=0;
    char c=getchar();
    while(!(c<='9'&&c>='0'))c=getchar();//空格回车等消除
    while(c<='9'&&c>='0'){
        s=(s<<1)+(s<<3);//等价于s=s*10，但是位运算更快，注意此处位运算的括号不可省略
        s+=c-'0';//加在个位上
        c=getchar();
    }
    return s;
}
int main(){
    //ios::sync_with_stdio(false);
    n=read(),m=read();
    for(int i=0;i<m;++i){
        int x,y;
        x=read(),y=read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>k;
    for(int i=0;i<k;++i){
        int in;
        in=read();
        ban[in]=true;
        bann.push(in);
    }
    for(int i=0;i<n;++i)fa[i]=i;
    int cnt=n-k;
    for(int i=0;i<n;++i){
        for(auto j:v[i]){
            if(!ban[i]&&!ban[j]&&find(i)!=find(j)){
                cnt--;
                merge(i,j);
            }
        }
    }
    ans.push(cnt);
    while(!bann.empty()){
        int now=bann.top();
        bann.pop();
        cnt++;
        ban[now]=false;
        for(auto i:v[now]){
            if(!ban[i]&&find(i)!=find(now)){
                cnt--;
                merge(now,i);
            }
        }
        ans.push(cnt);
    }
    while(!ans.empty()){
        int out=ans.top();
        ans.pop();
        cout<<out<<endl;
    }
    return 0;
}