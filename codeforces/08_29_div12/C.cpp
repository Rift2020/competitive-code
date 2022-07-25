#include <iostream>
#include <stack>
#define ll long long
#define int long long
using namespace std;
ll n,nn;
stack<int> st;
stack<int> sn;
ll ans;
signed main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		int in;
		cin>>in;
		if(i%2==1){
			st.push(in);
		}
		else{
			while (1) {
				if(st.empty())break;
				if(in==st.top()){
					ans+=in;
					if(sn.empty())sn.push(1);
					else sn.top()++;
					st.pop();
					break;
				}
				else if(in<st.top()){
					ans+=in;
					sn.push(1);
					st.top()-=in;
					break;
				}
				else{
					ans+=st.top();
					if(sn.empty())sn.push(1);
					else sn.top()++;
					in-=st.top();
					st.pop();
					ans+=(sn.top()-1)*sn.top()/2;
					sn.pop();
				}
			}
		}
		//cout<<ans<<endl;
	}
	if(!sn.empty())
		ans+=(sn.top()-1)*sn.top()/2;
	cout<<ans<<endl;
	
	return 0;
}