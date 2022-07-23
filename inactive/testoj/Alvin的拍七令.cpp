#include<bits/stdc++.h>
#define maxn 10000005
using namespace std;
int m,n,x;
string st;
bool inline check(int a){
    if(a%n==0)return true;
    string s=to_string(a);
    if(s.find(st)!=s.npos)return true;
    return false;
}

int a[maxn];
int main(){
    cin>>m>>n>>x;
    st=to_string(n);
    int d=0,k=0,kn=0;
    for(int i=1;;++i){
        if(i>m)i=1;
        if(d==m-1)break;
        if(a[i]==1)continue;
        ++k;
        
        if(check(k)){
            //cout<<"k:"<<k<<" "<<i<<endl;
            ++kn;
        }
        if(kn==x+1){
            //cout<<i<<endl;
            kn=0;
            a[i]=1;
            ++d;
        }
    }
    for(int i=1;i<=m;++i){
        if(a[i]==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}