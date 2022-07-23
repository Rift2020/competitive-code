#include<bits/stdc++.h>
using namespace std;
int a[4];
void p(string s){
	s.insert(0,2,'(');
	s.insert(5,1,')');
	s.insert(8,1,')');
	cout<<s;
	exit(0);
}
void so(int i,float s,string str){
	if(i==4){
		if(s==24)
			p(str);
		return;
	}
	if(s<0)return;
	so(i+1,s+a[i],str+'+'+to_string(a[i]));
	so(i+1,s-a[i],str+'-'+to_string(a[i]));
	so(i+1,s*a[i],str+'*'+to_string(a[i]));
	so(i+1,s/a[i],str+'/'+to_string(a[i]));
}
int main(){
	for(int &i:a)cin>>i;
	sort(a,a+4);
	do{
		so(1,a[0],to_string(a[0]));
	}
	while(next_permutation(a,a+4));
	cout<<-1<<endl;
	return 0;
}