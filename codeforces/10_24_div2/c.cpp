#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long int;
bool inline isReverse(string s){
    string ss=s;
    reverse(s.begin(),s.end());
    if(s==ss)return true;
    return false;
}
string inline ban(string s,char b){
    string re;
    for(int i=0;i<s.size();++i)re+=' ';
    for(int i=0,j=s.size()-1;i<=j;){
        if(s[i]==s[j]){
            re[i]=re[j]=s[i];
            ++i,--j;
        } 
        else{
            if(s[i]==b){
                ++i;
            }
            else if(s[j]==b){
                --j;
            }
            else{
                re[i]=s[i];
                re[j]=s[j];
                ++i,--j;
            }
        }
    }
    string rre;
    for(char c:re){
        if(c!=' ')
        rre+=c;
    }

    return rre;
}
int t,n;
string in;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>in;
        string rin=in;
        reverse(in.begin(),in.end());
        if(isReverse(in)){
            cout<<0<<endl;
            continue;
        }
        int s1=-1;
        for(int i=0;i<n;++i){
            if(rin[i]!=in[i]){
                if(isReverse(ban(in,in[i])))
                    s1=ban(in,in[i]).size();
                if(isReverse(ban(in,rin[i])))
                    s1=max(s1,(int)ban(in,rin[i]).size());
                break;
            }
        }
        if(s1==-1)
            cout<<-1<<endl;
        else
            cout<<in.size()-s1<<endl;
    }
    
    
    
    return 0;
}