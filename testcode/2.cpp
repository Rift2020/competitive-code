//时间复杂度:O(n*k)
#include<bits/stdc++.h>
#define maxn 105
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n,k;
string s;
bool erase[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;++i){
        int ri=n-i;//从这个位置开始(含)还有多少数位
        if(k==0)break;
        if(ri<=k){
            for(int j=i;j<n;++j){
                erase[j]=true;
            }
            break;
        }
        for(int j=i+1;j<=i+k;++j){
            if(s[j]<s[i]){
                for(int l=i;l<j;++l){
                    erase[l]=true;
                }
                k-=j-i;
                i=j-1;
                break;
            }
        }
    }
    bool fl=false;
    for(int i=0;i<n;++i){
        if(erase[i]==false){
            cout<<s[i];
            fl=true;
        }
    }
    if(!fl)cout<<0;
    cout<<endl;
    return 0;
}