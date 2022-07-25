#include <iostream>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn],mch[maxn],d[maxn],len,now;
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	for(int i=0;i<n;++i)mch[a[i]]=i;
	for(int i=0;i<n;++i)b[i]=mch[b[i]];
	d[0]=b[0];
	len=1,now=0;
	for(int i=1;i<n;++i){
		if(b[i]>d[now]){
			d[++now]=b[i];
			++len;
		}
		else{
			*lower_bound(d,d+len,b[i])=b[i];
		}
	}
	cout<<len<<endl;
	return 0;
}