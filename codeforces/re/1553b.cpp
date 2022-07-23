#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
int q;
string s,t;
bool isReverse(const string a,int x){
    for(int i=0;x-i>=0&&x+i<a.size();++i){
        if(a[x-i]!=a[x+i])return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>q;
    while(q--){
        cin>>s>>t;
        bool ok=false;
        for(int i=0;i<t.size();++i){
            if(i+1>s.size())break;
            if(t.size()-i>s.size())continue;
            if(isReverse(t,i)){
                string l=t.substr(0,i+1),r=t.substr(i,t.size()-i);
                reverse(r.begin(),r.end());
                string pd=l.size()>r.size()?l:r;
                if(s.find(pd)!=string::npos){
                    ok=true;
                    break;
                }
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    
    
    return 0;
}