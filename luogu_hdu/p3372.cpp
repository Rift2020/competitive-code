#include<bits/stdc++.h>
#define maxn 100005
#define lon long long
using namespace std;
int n,m;
lon tree[maxn*4];
lon laz[maxn*4];
lon a[maxn];
void build(int x,int l,int r){
    if(l!=r){
        int m=(l+r)/2;
        build(x*2,l,m);
        build(x*2+1,m+1,r);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
    else{
        tree[x]=a[l];
    }
}
void add(int x,int l,int r,int al,int ar,lon k){
    int m=(l+r)/2;
    if(l>=al&&r<=ar){
        laz[x]+=k;
        tree[x]+=k*(r-l+1);
    }else{
        if(laz[x]>0){
            laz[x*2]+=laz[x];
            tree[x*2]+=laz[x]*(m-l+1);
            laz[x*2+1]+=laz[x];
            tree[x*2+1]+=laz[x]*(r-m);
            laz[x]=0; 
        }
        if(al<=m){
            add(x*2,l,m,al,ar,k);
        }
        if(ar>m){
            add(x*2+1,m+1,r,al,ar,k);
        }
        tree[x]=tree[x*2]+tree[x*2+1];
    } 
    
}
lon query(int x,int l,int r,int ql,int qr){
    int m=(l+r)/2;
    lon s=0;
    if(l>=ql&&r<=qr)return tree[x];
    else {
        if(laz[x]>0){
            laz[x*2]+=laz[x];
            tree[x*2]+=laz[x]*(m-l+1);
            laz[x*2+1]+=laz[x];
            tree[x*2+1]+=laz[x]*(r-m);
            laz[x]=0;
        }
        if(ql<=m){
            s+=query(x*2,l,m,ql,qr);
        }
        if(qr>m){
            s+=query(x*2+1,m+1,r,ql,qr);
        }
    }
    return s;
}
int main(){
    memset(tree,0,sizeof(tree));
    memset(laz,0,sizeof(laz));
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    //cout<<endl;
    int op,x,y,k;
    for(int i=0;i<m;++i){
        scanf("%d",&op);
        //cout<<'t';
        //for(int i=1;i<=9;++i)cout<<tree[i]<<" ";
        if(op==1){
            scanf("%d%d%d",&x,&y,&k);
            add(1,1,n,x,y,k);
        }
        if(op==2){
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));
        }
    }

    
    return 0;
}