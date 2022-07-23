#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,string> pr;
priority_queue<pr,vector<pr>,greater<pr> > pq;
int main(){
    ios::sync_with_stdio(false);    
    cin>>n;    
    for(int i=0;i<n;++i){
        string op,ms;
        int pri;
        cin>>op;
        if(op=="PUT"){
            cin>>ms>>pri;
            pq.push((pr){pri,ms});
        }
        else if(op=="GET"){
            if(pq.empty()){
                cout<<"EMPTY QUEUE!"<<endl;
            }
            else {
                pr tp=pq.top();
                pq.pop();
                cout<<tp.second<<endl;
            }
        }
    }
    return 0;
}