#include<bits/stdc++.h>
#define maxn 5000005
#define lon int
using namespace std;
int n,m;
lon tree[maxn*4];
lon laz[maxn*4];
lon a[maxn];
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
void inline change(int x){
    if(a[x]==0){
        a[x]=1;
        add(1,1,n,x,x,1);
    }
}
int q(int x){//query(1,1,n,1,now)
    int re=0;
    if(a[x]){
        if(a[1]==0)return 1;
        int now=n/2;
        int l=1,r=n;
        while(l<=r){
            int qnow=query(1,1,n,1,now);
            if(qnow==now){
                if(a[now+1]==0)return now+1;
                l=now+1,now=(l+r)/2;
            }
            else{
                r=now-1,now=(l+r)/2;
            }
        }
    }
    else{
        change(x);
        if(a[1]==0){
            a[x]=0;
            add(1,1,n,x,x,-1);
            return 1;
        }
        int now=n/2;
        int l=1,r=n;
        while(l<=r){
            int qnow=query(1,1,n,1,now);
            if(qnow==now){
                if(a[now+1]==0){
                    a[x]=0;
                    add(1,1,n,x,x,-1);
                    return now+1;
                }
                l=now+1,now=(l+r)/2;
            }
            else{
                r=now-1,now=(l+r)/2;
            }
        }
        
    }
    return 1;
}
int main(){
    n=read();
    //cout<<endl;
    int op,x;
    for(int i=0;i<n;++i){
        op=read(),x=read();
        if(op==1)change(x);
        if(op==2)cout<<q(x)<<endl;
    }
    
    
    return 0;
}