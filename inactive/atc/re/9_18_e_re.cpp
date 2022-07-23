#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 20
using namespace std;
using ll = long long int;
int ans;
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
bool a[maxn],now[maxn]={0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0,0},vis[maxn];
int mem[maxn];//0 no vis,1 yes,2 no
bool vis2[maxn];
const int n=16;
bool vilIn(){
    rep(i,1,n)if(a[i]&&now[i]==false)return false;
    return true;
}
void dfs3(int i){
    if(vis[i]==true)return;
    vis[i]=true;
    int x=i/4+1;
	if(i%4==0)x--;
	int y=i-(x-1)*4;
    rep(j,1,4){
		int nx=x+dx[j];
		int ny=y+dy[j];
		//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
		if(nx<1||nx>4||ny<1||ny>4)continue;
		if(now[(nx-1)*4+ny])
			//cout<<nx<<" "<<ny<<" "<<(nx-1)*4+ny<<endl;
			dfs3((nx-1)*4+ny);
	}
}
int dfs4(int i){
    vis2[i]=true;
    if(mem[i])return mem[i];
    int x=i/4+1;
	if(i%4==0)x--;
	int y=i-(x-1)*4;
    rep(j,1,4){
		int nx=x+dx[j];
		int ny=y+dy[j];
		//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
        if(vis2[(nx-1)*4+ny])continue;
		if(nx<1||nx>4||ny<1||ny>4)return mem[i]=1;
		if(now[(nx-1)*4+ny]==false)
			if(dfs4((nx-1)*4+ny)==1)return mem[i]=1;
	}
    return 2;
}
bool check(){
    if(vilIn()==false)return false;
    memset(vis,0,sizeof(vis));
    memset(mem,0,sizeof(mem));
    rep(i,1,n){
        if(now[i]){
            dfs3(i);
            break;
        }
    }
    rep(i,1,n){
        if(now[i]&&vis[i]==false)return false;
    }
    rep(i,1,n){
        memset(vis2,0,sizeof(vis2));
        if(now[i]==false&&dfs4(i)==2){
            return false;
        }
    }
    return true;
}
int main(){
    //ios::sync_with_stdio(false);
    //freopen("std2.out","w",stdout);

    rep(i,1,n){
        int in;
        cin>>in;
        if(in==1)a[i]=true;
    }
    check();
    rep(i,0,(1<<n)-1){
        rep(j,1,n){
            now[j]=i&(1<<(j-1));
        }
        if(check())++ans;
    }
    cout<<ans<<endl;
    
    return 0;
}