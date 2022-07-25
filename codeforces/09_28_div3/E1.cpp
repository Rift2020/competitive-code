#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;deque<int> in;
deque<int> out,cl;
int t,n;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		in=cl,out=cl;
		rep(i,1,n){
			int x;
			cin>>x;
			in.push_back(x);
		}
		while(!in.empty()){
			int tp;
				tp=in.front();
				in.pop_front();
			if(out.empty())out.push_back(tp);
			else{
				if(tp<out.front()){
					out.push_front(tp);
				}
				else {
					out.push_back(tp);
				}
			}
		}
		for(int i:out){
			cout<<i<<" ";
		}
		cout<<endl;
	}				return 0;}