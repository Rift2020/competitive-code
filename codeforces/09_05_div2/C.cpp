#include <iostream>
#define maxn 15
using namespace std;
int t;
int a[maxn],ans;
string in;
int zs(int x){
	return  10-abs(x-9);//1-19的种类数
}
int dfs(int x){
	if(x==in.size())return 1;
	int re=0;
	if(x+2<in.size()&&a[x]>0){//最后两位分不了，等于0分不了
		a[x+2]+=10;
		re+=zs((a[x]-1))*dfs(x+1);//往后分的情况
		a[x+2]-=10;
	}
	re+=zs(a[x])*dfs(x+1);//不分的情况
	return re;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>in;
		for(int i=0;i<in.size();++i){
			a[i]=in[i]-'0';
		}
		ans=dfs(0)-2;
		cout<<ans<<endl;
	}
	
	return 0;
}