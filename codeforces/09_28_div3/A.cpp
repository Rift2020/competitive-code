#include<bits/stdc++.h>
string in;
	while(t--){
		cin>>in;
		int a=0,b=0;
		for(char c:in){
			if(c=='A'||c=='C')a++;
			else if(c=='B')++b;
		}
		if(a==b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}