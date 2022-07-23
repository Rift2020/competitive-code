#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long long
using namespace std;
using ll = long long;
int t,n,s;
priority_queue<int> pq,num,cl;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        pq=cl;
        num=cl;
        s=0;
        rep(i,1,n){
            int in;
            cin>>in;
            pq.push(in);
            s+=in;
        }
        bool fl=true;
        num.push(s);
        while(!pq.empty()){
            if(pq.top()==num.top()){
                pq.pop();
                num.pop();
            }
            else if(num.top()>pq.top()){
                int f=num.top();
                num.pop();
                if(f%2==0){
                    num.push(f/2);
                    num.push(f/2);
                }
                else {
                    num.push(f/2);
                    num.push(f/2+1);
                }
            }
            else{
                fl=false;
                break;
            }
        }
        if(fl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}