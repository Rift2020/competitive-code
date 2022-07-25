#include <iostream>
#include <deque>
using namespace std;
int n;
string s;
deque<char> dq;
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		dq.clear();
		for(char i:s){
			dq.push_back(i);
		}
		bool fl=true;
		char la;
		if(dq.front()>dq.back()){
			la=dq.front();
			dq.pop_front();
		}
		else{
			la=dq.back();
			dq.pop_back();
		}
		if(la!=dq.size()+'a')fl=false;
		while (!dq.empty()) {
			if(la-1==dq.front()){
				dq.pop_front();
				la--;
			}else if(la-1==dq.back()){
				dq.pop_back();
				la--;
			}else{
				fl=false;
				break;
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}