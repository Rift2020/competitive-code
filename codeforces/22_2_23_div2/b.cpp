#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n;
unordered_set<int> st;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        int in;
        st.clear();
        rep(i,1,n){
            cin>>in;
            st.insert(in);
        }
        int k=st.size();
        rep(i,1,n){
            if(i<=k)cout<<k<<" ";
            else cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}