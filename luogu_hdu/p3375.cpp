#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005
using namespace std;
using ll = long long;
int pi[maxn];
void kmp(const string &t,const string &s){
    //寻找s在t中的每次出现，假设s与t中不含空格
    pi[0]=0;
    string str=s+' '+t;
    for(int i=1;i<str.size();++i){
        int j=pi[i-1];
        while(j>0&&str[j]!=str[i])j=pi[j-1];
        if(str[j]==str[i])++j;
        pi[i]=j;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t,s;
    cin>>t>>s;
    kmp(t,s);
    for(int i=0;i<=t.size()+s.size()+1;++i){
        if(pi[i]==s.size()){
            cout<<(i-s.size()*2+1)<<endl;
        }
    }
    for(int i=0;i<s.size();++i){
        cout<<pi[i]<<" ";
    }
    
    
    return 0;
}