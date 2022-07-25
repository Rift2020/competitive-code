#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,n,nown,k,st;

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
}int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		out="";
		nown=0;
		k=n;
		st=0;
		out.resize(2*n);
		dfs(0);
	}				return 0;}