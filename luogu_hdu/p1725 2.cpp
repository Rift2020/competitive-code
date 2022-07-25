#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005using namespace std;using ll = long long;int n,l,r;
int a[maxn];
typedef pair<int,int> pr;//index,value
deque<pr> dq;
void in(int x,int now){
	while(!dq.empty()&&dq.back().second<a[x])dq.pop_back();
	if(!dq.empty()&&dq.front().first>now+r)dq.pop_front();
	dq.push_back({x,a[x]});
}signed main(){	ios::sync_with_stdio(false);	cin>>n>>l>>r;
	n++;
	rep(i,1,n)cin>>a[i];
	n++;	for(int i=n,j=n+r-l,now=i-l;now>=1;--i,--j,--now){
		in(i,now);
		a[now]+=dq.front().second;
	}
	cout<<a[1]<<endl;		return 0;}