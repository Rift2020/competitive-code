#include<bits/stdc++.h>
#define N 5005
#define M 200005
using namespace std;
struct side{
	int f1,f2,z;
	bool operator <(const side& s){
		return z<s.z;
	}
}a[M];
int fa[N];
int sf(int x){
	if(fa[x]==x)return x;
	fa[x]=sf(fa[x]);
	return fa[x];
}
void mf(int x,int y){
	int fx=sf(x);
	int fy=sf(y);
	fa[fx]=fy;
}


int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&a[i].f1,&a[i].f2,&a[i].z);
	}
	sort(a,a+m);
	int k=0,s=0;
	for(int i=0;i<m;++i){
		if(sf(a[i].f1)!=sf(a[i].f2)){
			++k;
			mf(a[i].f1,a[i].f2);
			s+=a[i].z;
		}
		if(k==n-1){
			cout<<s<<endl;
			break;
		}
	}
	if(k<n-1)
		cout<<"orz"<<endl;
	return 0;
}