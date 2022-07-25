#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int fact(int a){
	int re=1;
	for(int i=2;i<=a;++i)re*=i;
	return re;
}
int c(int n,int m){
	return fact(n)/((fact(m)*fact(n-m)));
}
int main() {
	for(int n=1;n<=10;++n){
		int s=0;
		for(int m=1;m<=n;++m){
			s+=c(n,m);
		}
		cout<<s<<endl;
		//cout<<(1<<(n-1)+1)<<endl;
	}
	return 0;
}