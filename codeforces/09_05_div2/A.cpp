#include <iostream>

using namespace std;
int t;
int n;
string in;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n>>in;
		string ans;
		for(char i:in){
			if(i=='L'||i=='R'){
				ans+=i;
			}
			else if(i=='U'){
				ans+='D';
			}
			else if(i=='D'){
				ans+='U';
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}