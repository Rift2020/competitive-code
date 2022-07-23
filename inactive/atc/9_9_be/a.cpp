#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
int n;
char s[10];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=7;++i)cin>>s[i];
    if(s[n]=='x')cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    
    
    
    return 0;
}