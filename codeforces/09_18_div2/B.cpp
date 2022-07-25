#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 100005		using namespace std;using ll = long long int;unordered_map<int,int> st,f;
//st是b数组里的数对应的出现位置

//f是比x大的首个（在b中）数的位置
//比如x是3，b数组是8 4 2 6，那么f[x]就是1，因为8是第一个比x大的数

//所以答案其实就是  （把a[i]移到第一个数的代价(i-1) 加上 比a[i]大的首个数移到第一位的代价(f[a[i]]-1）的最小值

int a[maxn],b[maxn];
int n;
int t;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		st.clear();
		cin>>n;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)cin>>b[i];
		rep(i,1,n)st[b[i]]=i;
		for(int i=2*n;i>=2;i-=2){
			if(i==2*n)f[i-1]=st[i];
			else
				f[i-1]=min(f[i+1],st[i]);//这一行很关键
			//打个比方，比3大的数的集合是a，比5大的集合是b
			//那么a就是b再加一个4，比3大的首个数要么是4，要么是比5大的首个数
		}
		int ans=1e9;
		rep(i,1,n){
			int now=a[i];
			ans=min(i+f[now]-2,ans);
		}
		cout<<ans<<endl;
	}				return 0;}