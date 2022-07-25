#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 25		using namespace std;using ll = long long int;int t,n,m,k;
typedef pair<int,int> pr;
priority_queue<pr> q,cl;
bool is[maxn][maxn];
bool ok[maxn][maxn];int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		memset(is,false,sizeof(is));
		memset(ok,false,sizeof(ok));
		q=cl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				char c;
				cin>>c;
				if(c=='*'){
					is[i][j]=true;
					q.push(pr{i,j});
				}
			}
		}
		bool ye=true;
		while (!q.empty()) {
			ye=false;
			int x=q.top().first,y=q.top().second;
			//cout<<x<<" "<<y<<endl;
			q.pop();
			if(ok[x][y]==true){
				ye=true;
			}
			int h;
			for(h=1;;++h){
				int nx=x-h;
				int ny1=y-h;
				int ny2=y+h;
				if(nx<1||ny1<1||ny2>m){
					--h;break;
				}
				if(!is[nx][ny1]||!is[nx][ny2]){
					--h;break;
				}
			}
			if(h>=k){
				ye=true;
				ok[x][y]=true;
				for(int i=1;i<=h;++i){
					int nx=x-i;
					int ny1=y-i;
					int ny2=y+i;
					ok[nx][ny1]=ok[nx][ny2]=true;
				}
			}
			if(ye==false){
				//cout<<x<<" "<<y<<" "<<h<<endl;
				break;
			}
		}
		if(ye==false){
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
		}
	}				return 0;}