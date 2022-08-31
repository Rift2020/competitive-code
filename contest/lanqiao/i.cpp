#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
using namespace std;
using ll = long long;
int hav[maxn];
string mem[maxn];
int n,q;
vector<int> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    rep(i,1,n){
        int in;
        cin>>in;
        hav[in]++;
        v.push_back(in);
    }
    sort(v.begin(),v.end());
    while(q--){
        int in;
        cin>>in;
        if(mem[in]!="")cout<<mem[in]<<endl;
        else{
            mem[in]="NO";
            for(int i:v){
                if(hav[i*in]){
                    mem[in]="YES";
                }
            }
            cout<<mem[in]<<endl;
        }
    }
    
    return 0;
}