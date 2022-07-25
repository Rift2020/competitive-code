#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string.h>
#define maxn 15
using namespace std;
int t,n;
int a[maxn];
int all[]={0,1,3,7,15,31,63,127,255,511,1023};
bool fl;
unordered_set<int> st;
int ar[maxn];
void dfs(int x,int ind,int le){
    ar[ind]=x;
	if(le==0){
		int sum=0;
		for(int i=0;i<=ind;++i){
			sum+=a[ar[i]];
		}
		st.insert(sum);
        return;
	}
	for(int i=x+1;i<n-le+1;++i){
		dfs(i,ind+1,le-1);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
			a[i]=abs(a[i]);
		}
		fl=false;
		if(n==1){
			fl=true;
		}
		st.clear();
		for(int i=0;i<n;++i){
			st.insert(a[i]);
		}
		if(st.size()<n){
			fl=true;
		}
		if(fl){
			cout<<"YES"<<endl;
			continue;
		}
		memset(ar, 0, sizeof(ar));
		for(int le=2;le<=n;++le){
			for(int x=0;x<n-le+1;++x){
				dfs(x, 0, le-1);
			}
		}
		if(st.size()<all[n])fl=true;
		if(fl){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}