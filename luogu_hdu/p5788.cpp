#include<bits/stdc++.h>
		#define maxn 3000005
int a[maxn];
int ans[maxn];
typedef pair<int,int> pr;//value,index
stack<pr> st;
	rep(i,1,n)cin>>a[i];
		while(!st.empty()&&st.top().first<=a[i])st.pop();
		if(!st.empty())ans[i]=st.top().second;
		st.push({a[i],i});
	}
	cout<<endl;