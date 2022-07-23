#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn];
int sa[maxn];
unordered_map<int,int> fir;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sa[i]=a[i];
    }
    sort(sa,sa+n);
    for(int i=0;i<n;++i){
        if(fir.find(sa[i])==fir.end())fir[sa[i]]=i;
    }
    int r=-1;
    int ans=0;
    for(int i=0;i<n;++i){
        int sit=fir[a[i]]++;
        r=max(sit,r);
        if(r==i){
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}