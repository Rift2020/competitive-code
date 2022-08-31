#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 305		using namespace std;using ll = long long int;int dp[maxn][maxn];//i，j最少需要几个
bool used[maxn][maxn][maxn];//i，j最少的情况，k三明治有没有被买掉
int x,y;
int n;
int a[maxn];
int b[maxn];int main(){	ios::sync_with_stdio(false);	cin>>n;
	cin>>x>>y;
	rep(i,1,n)cin>>a[i]>>b[i];
		rep(i,0,x){
		rep(j,0,y){
			if(i!=0||j!=0)dp[i][j]=1e9;
			int si=-1,sj=-1,sk=-1;
			rep(k,1,n){
				if(used[max(0,i-a[k])][max(0,j-b[k])][k]==false&&dp[max(0,i-a[k])][max(0,j-b[k])]+1<dp[i][j]){
					//找到该转移哪个
					dp[i][j]=min(dp[i][j],dp[max(0,i-a[k])][max(0,j-b[k])]+1);
					si=max(0,i-a[k]),sj=max(0,j-b[k]),sk=k;
				}
			}
			if(si!=-1){
				//转移用过了什么
				rep(k,1,n){
					used[i][j][k]=used[si][sj][k];
				}
				used[i][j][sk]=true;
			}
		}
	}
	//rep(i,1,n)cout<<(used[x][y][i]==true?1:0)<<" ";
	if(dp[x][y]!=1e9)		cout<<dp[x][y]<<endl;	else 
		cout<<-1<<endl;	return 0;}