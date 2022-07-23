#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,bot;
long long ans;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    bot=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>bot)bot=a[i];
        else {
            ans+=bot-a[i];
            bot=a[i];
        }
    }
    cout<<ans+bot<<endl;
    
    return 0;
}