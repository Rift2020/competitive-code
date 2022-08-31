#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 20		using namespace std;using ll = long long int;int fa[maxn];
bool a[maxn];
bool now[maxn];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
int ans;
int n=16;
void init(){
	rep(i,1,n)fa[i]=i;
}
int f(int x){
	if(fa[x]==x)return x;
	return fa[x]=f(fa[x]);
}
void mg(int x,int y){
	int fx=f(x);
	int fy=f(y);
	fa[fx]=fy;
}
bool check(){
	init();
	rep(i,1,n){
		if(now[i]==false)continue;
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
				mg(i,(nx-1)*4+ny);
		}
	}
	
	int ft=1;
	rep(i,1,n)if(now[i]==true)ft=i;
	rep(i,1,n){
		if(now[i]&&f(i)!=f(ft))return false;
	}
	
	cout<<':'<<endl;
	rep(i,1,4){
		rep(j,1,4){
			cout<<(now[(i-1)*4+j]?1:0)<<" ";
			//cout<<f((i-1)*4+j)<<" ";
		}
		cout<<endl;
	}
	
	return true;
}
void dfs(int x){
	if(x==17){
		if(check())++ans;
		return;
	}
	if(a[x]==true){
		now[x]=true;
		dfs(x+1);
	}
	else{
		now[x]=true;
		dfs(x+1);
		now[x]=false;
		dfs(x+1);
	}
}

int main(){	ios::sync_with_stdio(false);	rep(i,1,n){
		int in;
		cin>>in;
		if(in==1)a[i]=true;
	}	dfs(1);
	cout<<ans<<endl;			return 0;}