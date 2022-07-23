#include<bits/stdc++.h>
using namespace std;
string q,z;
void h(string q,string z){
	if(q.empty()){
		return;
	}
	char root=q[0];
	q.erase(q.begin());
	int k=z.find(root);
	h(q.substr(0,k),z.substr(0,k));
	h(q.substr(k),z.substr(k+1));
	printf("%c",root);
}
int main(){
	cin>>z>>q;
	h(q,z);
	return 0;
}