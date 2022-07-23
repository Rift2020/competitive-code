#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 20005
#define maxe 105

typedef struct{
    int u,v;
}edge;
int nxt[maxn],head[maxn],to[maxn];
int vis[maxn];
int cnt=-1,now=-1;
int n,m;
edge ed[maxe];
int cmp(const void *a,const void *b){
    return ((edge*)b)->v-((edge*)a)->v;
}
void add(int u, int v) {
  nxt[++cnt] = head[u];  
  head[u] = cnt;         
  to[cnt] = v;           
}



void dfs(int u){
    if(vis[u]==1)return;
    vis[u]=1;
    printf("%d ",u);
    for (int i = head[u]; ~i; i = nxt[i]) {  // ~i 表示 i != -1
        int v = to[i];
        dfs(v);
    }
}


int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        ed[++now]=(edge){u,v};
    }
    qsort(ed,m,sizeof(edge),cmp);
    for(int i=0;i<m;++i)add(ed[i].u,ed[i].v);
    for(int i=0;i<n;++i)
        if(vis[i]==0)
            dfs(i);
}