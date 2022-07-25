#include <iostream>
#define maxn 50005
using namespace std;
typedef struct{
	int a[5];
}st;
bool operator>(const st &a,const st &b){
	int r=0;
	for(int i=0;i<5;++i){
		if(a.a[i]<b.a[i])++r;
	}
	if(r>=3)return true;
	return false;
}
int n,t;
st ar[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>n;
		for(int i=0;i<n;++i){
			for(int &j:ar[i].a)cin>>j;
		}
		st ma=ar[0];
		int ind=0;
		for(int i=0;i<n;++i){
			if(ar[i]>ma){
				ma=ar[i];
				ind=i;
			}
		}
		bool fl=true;
		for(int i=0;i<n;++i){
			if(i==ind)continue;
			if(!(ma>ar[i])){
				fl=false;
				break;
			}
		}
		if(fl){
			cout<<ind+1<<endl;
		}
		else{
			cout<<-1<<endl;
			
		}
	}
	return 0;
}