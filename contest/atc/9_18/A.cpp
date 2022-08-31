#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int x;int main(){	ios::sync_with_stdio(false);	cin>>x;
	if(x<40){
		cout<<40-x;
	}
	else if(x<70){
		cout<<70-x;
	}
	else if(x<90){
		cout<<90-x;
	}
	else {
		cout<<"expert";
	}	cout<<endl;			return 0;}