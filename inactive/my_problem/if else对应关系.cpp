#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> pr;//str,num
stack<pr> st;
string in;
int n,num=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>in;
        if(in=="if")st.push((pr){in,++num});
        else if(in=="{")st.push((pr){in,0});
        else if(in=="else"){
            if(!st.empty()&&st.top().first=="if"){
                cout<<st.top().second<<endl;
                st.pop();
            }
            else cout<<-1<<endl;
        }
        else if(in=="}"){
            while(!st.empty()&&st.top().first!="{")st.pop();
            if(st.top().first=="{")st.pop();
        }
    }
    
    return 0;
}