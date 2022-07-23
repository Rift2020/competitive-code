#include<bits/stdc++.h>
using namespace std;
stack<string> st;
int main(){
    string in;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>in;
        if(in=="{")st.push("{");
        else if(in=="}"){
            if(st.empty()){
                cout<<"WRONG"<<endl;
                break;
            }
            else
                st.pop();
        }
    }
    
    
    return 0;
}