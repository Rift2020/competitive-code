#include<bits/stdc++.h>
deque<int> out,cl;
int t,n;
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
	}