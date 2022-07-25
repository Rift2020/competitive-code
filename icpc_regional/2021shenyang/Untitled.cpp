#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)using namespace std;using ll = long long;
string in;
string ck="edgnb";int solve(){
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
}signed main(){	ios::sync_with_stdio(false);	cin>>in;
	cout<<solve()<<endl;				return 0;}