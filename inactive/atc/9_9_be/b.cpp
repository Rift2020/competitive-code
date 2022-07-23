#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
int a[30];
int main(){
    ios::sync_with_stdio(false);
    for(int i=1;i<=26;++i)cin>>a[i];
    string s;
    for(int i=1;i<=26;++i)s+='a'+a[i]-1;
    cout<<s<<endl;
    
    
    return 0;
}