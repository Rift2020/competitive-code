#include<bits/stdc++.h>

string out;
void dfs(int x){
	if(nown==n)return;
	if(x==2*n){
		cout<<out<<endl;
		++nown;
		return;
	}
	if(st==0){
		out[x]='(';
		--k;
		st++;
		dfs(x+1);
	}
	else if(k==0){
		out[x]=')';
		st--;
		dfs(x+1);
	}
	else{
		out[x]='(';
		--k;
		++st;
		dfs(x+1);
		++k;
		--st;
		out[x]=')';
		--st;
		dfs(x+1);
	}
}
	while(t--){
		cin>>n;
		out="";
		nown=0;
		k=n;
		st=0;
		out.resize(2*n);
		dfs(0);
	}