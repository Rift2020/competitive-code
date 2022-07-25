#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,n;
int rtype(string s){
	if(s[0]=='b'||s[0]=='c')return 1;
	if(s[0]=='i'||s[0]=='f')return 4;
	if(s[0]=='d'||(s[0]=='l'&&s[5]=='l'))return 8;
	if(s[0]=='_'||(s[0]=='l'&&s[5]=='d'))return 16;
	return 0;
}
int ramt(string s){
	if(s[s.size()-2]!=']')return 1;
	string re;
	bool fl=false;
	for(char c:s){
		if(c==']')break;
		if(fl)re+=c;
		if(c=='[')fl=true;
	}
	return atoi(re.c_str());
}int main(){	ios::sync_with_stdio(false);	cin>>t;
	rep(c,1,t){
		cin>>n;
		cin.ignore();
		ll ans=0;
		string in;
		rep(i,1,n){
			getline(cin,in);
			//cout<<rtype(in)<<" "<<ramt(in)<<endl;
			ans+=rtype(in)*ramt(in);
			
		}
		//cout<<ans<<endl;
		ans=ans/1024+(ans%1024?1:0);
		cout<<"Case #"<<c<<": "<<ans<<endl;
		
	}				return 0;}