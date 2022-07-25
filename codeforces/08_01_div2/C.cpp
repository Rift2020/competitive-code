#include <iostream>
#include <unordered_set>
#include <string.h>
#define maxn 200005
using namespace std;
int n,m;
unordered_set<int> mp[maxn];
bool dead[maxn];
int die[maxn];
bool fr=true;
int inline read(){
	int s=0;
	char c=getchar();
	while(!(c<='9'&&c>='0'))c=getchar();//空格回车等消除
	while(c<='9'&&c>='0'){
		s=(s<<1)+(s<<3);//等价于s=s*10，但是位运算更快，注意此处位运算的括号不可省略
		s+=c-'0';//加在个位上
		c=getchar();
	}
	return s;
}
void inline add(int u,int v){
	mp[u].insert(v);
	mp[v].insert(u);
}
void inline del(int u,int v){
	mp[u].erase(v);
	mp[v].erase(u);
}
int process(int x){
	int re=die[x-1];
	for(int u=x;u<=n;++u){
		if(dead[u]){
			++re;
			continue;
		}
		int s=0;
		bool le=false;
		for(const int &v:mp[u]){
			if(dead[v])continue;
			++s;
			if(v<u){
				le=true;
				break;
			}
		}
		if(s>0&&le==false){
			++re;
			dead[u]=true;
			for(const int &v:mp[u]){
				mp[v].erase(u);
			}
			mp[u].clear();
		}
		die[u]=re;
	}
	return re;
}
int main() {
	n=read(),m=read();
	for(int i=0;i<m;++i){
		int u,v;
		u=read(),v=read();
		mp[u].insert(v);
		mp[v].insert(u);
	}
	int q;
	q=read();
	int lap=0,mem=0,low=1;
	while (q--) {
		int op,u,v;
		op=read();
		if(op==1){
			u=read(),v=read();
			low=min(low,min(u,v));
			mp[u].insert(v);
			mp[v].insert(u);
		}
		else if(op==2){
			u=read(),v=read();
			low=min(low,min(u,v));
			mp[u].erase(v);
			mp[v].erase(u);
		}
		else{
			if(lap==3){
				cout<<mem<<endl;
			}
			else{
				//for(int i=low;i<=n;++i)dead[i]=false;
				mem=n-process(low);
				cout<<mem<<endl;
			}
			low=maxn;
		}
		lap=op;
	}
	
	
	return 0;
}