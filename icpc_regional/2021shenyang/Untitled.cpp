#include<bits/stdc++.h>
string in;
string ck="edgnb";
	int re=0;
	for(int i=0;i<=(int)in.size()-5;++i){
		bool fl=true;
		for(int j=0;j<5;++j){
			if(in[i+j]!=ck[j]){
				fl=false;
				break;
			}
		}
		if(fl)
			re++;
	}
	return re;
}
	cout<<solve()<<endl;