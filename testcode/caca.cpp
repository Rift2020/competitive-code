#include<bits/stdc++.h>
using namespace std;
typedef struct{
   int w,v;
}item;
bool operator<(item a,item b){
   return (float)a.v/a.w>(float)b.v/b.w;
}
typedef struct{
   bool pick;
   int ind;
   int w;
   int v;
   float ub;
   int fa;
}nod;
bool operator<(nod a,nod b){
   return a.ub<b.ub;
}
int w;
int n;
item a[100005];
priority_queue<nod> pq;
vector<nod> v;
int ans,ansi;
bool fl;
float get_ub(int w,int val,int ind){
   if(ind==n-1)return val;
   return val+(float)w*a[ind+1].v/a[ind+1].w;
}
int main(){
    cin>>n>>w;
    for(int i=0;i<n;++i)cin>>a[i].w>>a[i].v;
   int now=w;
   for(int i=0;i<n;++i){
       if(a[i].w<=now){
           now-=a[i].w;
           ans+=a[i].v;
       }
   }
   sort(a,a+n);
   pq.push({false,-1,w,0,get_ub(w,0,0),-1});
   while(!pq.empty()){
       nod now=pq.top();
       pq.pop();
       if(now.ub<ans||(now.ub==ans&&fl==true)){
           continue;
       }
       v.push_back(now);
       if(now.ind==n-1){
           if(ans<now.v){
               ans=now.v;
               ansi=v.size()-1;
           }
           continue;
       }
       int i=now.ind+1;
       pq.push({false,now.ind+1,now.w,now.v,get_ub(now.w,now.v,i),(int)v.size()-1});

       if(now.w>=a[i].w){
           pq.push({true,now.ind+1,now.w-a[i].w,now.v+a[i].v,get_ub(now.w-a[i].w,now.v+a[i].v,i),(int)v.size()-1});
       }
   }
   cout<<ans<<endl;
  // bool p[n];
   //for(int i=n-1;i>=0;--i){
   //    p[i]=v[ansi].pick;
   //    ansi=v[ansi].fa;
   //}
   //cout<<"pick:";
   //for(int i=0;i<n;++i){
   //    if(p[i])cout<<" "<<i;
   //}
   //cout<<endl;
   return 0;
}