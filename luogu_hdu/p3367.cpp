//仅仅使用了路径压缩 
#include<bits/stdc++.h>
#define max 10005
using namespace std;
int fa[max];
int sf(int x){
//搜索x的祖先 
	if(fa[x]==x)return x;
	fa[x]=sf(fa[x]);
	return fa[x];
}
void cf(int x,int y){
//将x和y所在的家族合并 
	int xf=sf(x);
	int yf=sf(y);
	fa[xf]=yf;
}
int main(){
	for(int i=0;i<max;++i){
		fa[i]=i;//初始化 
	}
	int n,m;
	cin>>n>>m;
	int z,x,y;
	for(int i=0;i<m;++i){
		cin>>z>>x>>y;
		if(z==1)
			cf(x,y);
		else{
			if(sf(x)==sf(y))
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}
	}
	
	return 0;
} 