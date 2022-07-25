#include <iostream>
#include <string.h>
using namespace std;
int t;
string in;
int amo[26];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>in;
		memset(amo, 0, sizeof(amo));
		for(char j:in){
			amo[j-'a']++;
		}
		int r=0,g=0;
		for(int j:amo){
			if(j==0)continue;
			if(j>=2){
				r++;
				g++;
			}else if(j==1){
				if(r>g)swap(r,g);
				r++;
			}
		}
		cout<<min(r,g)<<endl;
	}
	return 0;
}