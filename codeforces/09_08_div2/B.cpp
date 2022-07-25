#include <bits/stdc++.h>
#define maxn 55
using namespace std;
int t,n;
int dz[maxn][maxn];//1win2lose3eq4x
bool is1[maxn];
char out[5]={'=','+','-','=','X'};
void init(){
	memset(dz,0,sizeof(dz));
	for(int i=1;i<=n;++i)dz[i][i]=4;
}
void filleq(int x){
	for(int i=1;i<=n;++i){
		if(dz[i][x])continue;
		dz[i][x]=dz[x][i]=3;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		memset(is1,0,sizeof(is1));
		cin>>n;
		init();
		for(int i=1;i<=n;++i){
			char c;
			cin>>c;
			if(c=='1'){
				is1[i]=true;
				filleq(i);
			}
		}
		bool fl=true;
		for(int i=1;i<=n;++i){
			if(is1[i])continue;
			fl=false;
			for(int j=1;j<=n;++j){
				if(dz[i][j])continue;
				dz[i][j]=1;
				dz[j][i]=2;
				fl=true;
				break;
			}
			if(fl==false)break;
		}
		if(fl==false)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					cout<<out[dz[i][j]];
				}
				cout<<endl;
			}
		}
	}
	
	
	return 0;
}