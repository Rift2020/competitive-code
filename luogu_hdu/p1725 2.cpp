#include<bits/stdc++.h>
#define maxn 200005
int a[maxn];
typedef pair<int,int> pr;//index,value
deque<pr> dq;
void in(int x,int now){
	while(!dq.empty()&&dq.back().second<a[x])dq.pop_back();
	if(!dq.empty()&&dq.front().first>now+r)dq.pop_front();
	dq.push_back({x,a[x]});
}
	n++;
	rep(i,1,n)cin>>a[i];
	n++;
		in(i,now);
		a[now]+=dq.front().second;
	}
	cout<<a[1]<<endl;