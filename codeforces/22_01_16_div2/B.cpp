#include<bits/stdc++.h>
string in;
	cin.tie(nullptr);
	while(t--){
		cin>>in;
		int ind=-1;
		for(int i=in.size()-2;i>=0;--i){
			if(in[i]-'0'+in[i+1]-'0'>=10){
				ind=i;
				break;
			}
		}
		
		if(ind!=-1){
			int num=in[ind]-'0'+in[ind+1]-'0';
			in[ind]=to_string(num)[0];
			in[ind+1]=to_string(num)[1];
		}
		else{
			int num=in[0]+in[1]-'0'-'0';
			in=in.substr(1);
			in[0]=num+'0';
		}
		cout<<in<<endl;
	}