#include<bits/stdc++.h>
		using namespace std;
	int re=x/3*2;
	re+=x%3;
	return re;
}
int queryOdd(int l,int r){
	return sumOdd(r)-sumOdd(l-1);
}
int n;
	unsigned long long s=0;
	unsigned long long nj=sumOdd(n);
	s=n*(n-1)/2-(nj-1)*nj/2;