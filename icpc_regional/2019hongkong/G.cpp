#include<bits/stdc++.h>
	q=k/p;
	m=k%p;
	int cnt=1;
	n=p+q+m;
	cout<<n+1<<endl;
		cout<<i<<" ";
		++cnt;
	}
		cout<<cnt<<" ";
		++cnt;
	}
	cout<<m+1<<" ";
	++cnt;
	rep(i,1,q-1){
		cout<<cnt<<" ";
		++cnt;
	}
	cout<<endl;
	cout<<3<<" ";
	rep(i,1,m)cout<<2<<" ";
	rep(i,1,p+q)cout<<1<<" ";
	cout<<endl;